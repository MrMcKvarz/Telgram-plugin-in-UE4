#include "TelegramClient.h"
#include "network/Authenticator.h"
#include "network/TCPTransport.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "Crypto.h"
#include "MTProtoSender.h"
#include <typeinfo> 

/*TL objects*/
#include "../../TL/AllObjects.h"
#include "TL/TLObjectBase.h"
#define UI UI_ST
THIRD_PARTY_INCLUDES_START
#include "tl/Session.h"
THIRD_PARTY_INCLUDES_END
#undef UI


TelegramClient::TelegramClient(FString SessionName, int32 API_id, FString API_hash)
{
	ClientSession = MakeShareable(new Session(SessionName));
	API_ID = API_id;
	API_Hash = API_hash;
	bAuthorized = false;
	bAuthanticated = false;
	bUserAuthorized = false;
}

TelegramClient::~TelegramClient()
{

}

UserError TelegramClient::Connect()
{

	/*Connect here and close only when program is done*/
 	/*This is due to FSocket bug*/
 	if(!Sender.IsValid())
	{
		Sender = MakeShareable((new MTProtoSender(*ClientSession.Get())));
		Sender->SetClient(this);
	}

	if(!ClientSession->Load() || ClientSession->GetAuthKey().GetKeyID() == 0)
	{
		GenerateNewAuthKey();

		if (ClientSession->Save())
			UE_LOG(LogTemp, Warning, TEXT("Session saved"));
	}
	Sender->UpdateTransport(ClientSession.Get());
	if (!Sender->IsConnected()) Sender->Connect();
	HELP::GetConfig * ConfigRequest = new HELP::GetConfig();

	COMMON::InitConnection * InitRequest = new COMMON::InitConnection(API_ID, ClientSession->GetDeviceModel(), ClientSession->GetSystemVersion(), ClientSession->GetAppVersion(), ClientSession->GetSystemLangCode(),
		ClientSession->GetLangPack(), ClientSession->GetLangCode(), ConfigRequest);
	COMMON::InvokeWithLayer * InvokeWithLayerRequest = new COMMON::InvokeWithLayer(AllObjects::CurrentLayer(), InitRequest);
	Invoke(*InvokeWithLayerRequest);

	COMMON::Config* ConfigResult = reinterpret_cast<COMMON::Config*>(InvokeWithLayerRequest->GetResult());

	for (auto DCOption : ConfigResult->GetDcOptions())
		ClientSession->DCOptions.Add(DCOption);

	UE_LOG(LogTemp, Warning, TEXT("Telegram Client connect"));
	FString ErrorMessage = InvokeWithLayerRequest->GetLastErrorMessage();
	int32 ErrorCode = InvokeWithLayerRequest->GetLastErrorCode();
	delete InvokeWithLayerRequest;
	return UserError(ErrorMessage, ErrorCode);
}

void TelegramClient::GenerateNewAuthKey()
{

	AuthKey AuthKeyData = Authenticator::Authenticate(ClientSession->GetServerAddress(), ClientSession->GetPort());
	ClientSession->SetAuthKey(AuthKeyData);
	Sender->SetTimeOffset(Authenticator::TimeOffset);
	bAuthanticated = true;
	return;
}

UserError TelegramClient::SendCode(FString PhoneNumber)
{
	this->PhoneNumber = PhoneNumber;
	UserError AuthorizeError = IsUserAuthorized();
	if(AuthorizeError.GetError() == EMTProtoErrors::AuthKeyUnregistered)
	{
		AUTH::SendCode SendCodeRequest(true, PhoneNumber, true, API_ID, API_Hash);
		Invoke(SendCodeRequest);
		if(SendCodeRequest.GetResult())
			PhoneHashCode = SendCodeRequest.GetResult()->GetPhoneCodeHash();
		return UserError(SendCodeRequest.GetLastErrorMessage(), SendCodeRequest.GetLastErrorCode());
	}
	return AuthorizeError;
}

bool TelegramClient::Invoke(TLBaseObject &Request)
{
	if (!Request.IsContentRelated()) return false;
	UE_LOG(LogTemp, Warning, TEXT("Send begin"));
	int32 InitSent = Sender->Send(Request);
	UE_LOG(LogTemp, Warning, TEXT("receive begin"));
	Sender->Receive(Request);
	if (!Request.GetLastErrorMessage().IsEmpty())
	{
		return false;
	}

	return true;
}

bool TelegramClient::Reconnect()
{
	GenerateNewAuthKey();
	return CreateNewSession();
}

UserError TelegramClient::GetDialogSlice(int32 SliceNumber, TArray<FString> &OutTitles)
{
	//if (!IsUserAuthorized()) return TArray<FString>();
	MESSAGES::GetDialogs GetDialogRequest(false, FDateTime::MinValue(), 0, new COMMON::InputPeerEmpty(), 0);
	Invoke(GetDialogRequest);
	if (GetDialogRequest.GetResult()->GetConstructorID() == 0x71e094f3)
	{
		MESSAGES::DialogsSlice * GetDialogResult = reinterpret_cast<MESSAGES::DialogsSlice *> (GetDialogRequest.GetResult());
		for (COMMON::Dialog dialog : GetDialogResult->GetDialogs())
		{
			COMMON::PeerUser * Title = reinterpret_cast<COMMON::PeerUser *> (dialog.GetPeer());
			//Save all users
			for (COMMON::User User : GetDialogResult->GetUsers())
			{
					Users.Add(User);
			}
			//Get all users names
			for (COMMON::User user : GetDialogResult->GetUsers())
				if (user.GetId() == Title->GetUserId())
					OutTitles.Add(user.GetFirstName());
			//Save all chats
			for (COMMON::Chat Chat : GetDialogResult->GetChats())
			{
				if (Chat.GetConstructorID() == -652419756)
					Chats.Add(Chat);
			}
			//Get all chats names
			for (COMMON::Chat chat : GetDialogResult->GetChats())
				if (chat.GetId() == Title->GetUserId())
					OutTitles.Add(chat.GetTitle());
		}
	}
	else
	{
		MESSAGES::Dialogs * GetDialogResult = reinterpret_cast<MESSAGES::Dialogs *> (GetDialogRequest.GetResult());
		for (COMMON::Dialog dialog : GetDialogResult->GetDialogs())
		{
			COMMON::PeerUser * Title = reinterpret_cast<COMMON::PeerUser *> (dialog.GetPeer());
			for (COMMON::Dialog dialog : GetDialogResult->GetDialogs())
			{
				COMMON::PeerUser * Title = reinterpret_cast<COMMON::PeerUser *> (dialog.GetPeer());
				//Save all users
				for (COMMON::User User : GetDialogResult->GetUsers())
				{
					Users.Add(User);
				}
				//Get all users names
				for (COMMON::User user : GetDialogResult->GetUsers())
					if (user.GetId() == Title->GetUserId())
						OutTitles.Add(user.GetFirstName());
				//Save all chats
				for (COMMON::Chat Chat : GetDialogResult->GetChats())
				{
					if (Chat.GetConstructorID() == -652419756)
						Chats.Add(Chat);
				}
				//Get all chats names
				for (COMMON::Chat chat : GetDialogResult->GetChats())
					if (chat.GetId() == Title->GetUserId())
						OutTitles.Add(chat.GetTitle());
			}
		}
	}
	return UserError(GetDialogRequest.GetLastErrorMessage(), GetDialogRequest.GetLastErrorCode());
}

UserError TelegramClient::SingIn(FString Code)
{
	AUTH::SignIn SingInRequest(PhoneNumber, PhoneHashCode, Code);
	Invoke(SingInRequest);
	return UserError(SingInRequest.GetLastErrorMessage(), SingInRequest.GetLastErrorCode());
}

UserError TelegramClient::SendMessage(FString UserSendTo, FString Message)
{
	UserError AuthorizeError = IsUserAuthorized();
	if (AuthorizeError.GetError() == EMTProtoErrors::RequestOK)
	{
		COMMON::User User;
		for (COMMON::User user : Users)
			if (user.GetFirstName() == UserSendTo)
				User = user;

		bool Result = false;
		if (!Message.IsEmpty())
		{
			MESSAGES::SendMessage SendMessageRequest(
				true,
				false,
				false,
				false,
				new COMMON::InputPeerUser(User.GetId(), User.GetAccessHash()),
				0,
				Message,
				Crypto::GetRandomLong(),
				nullptr,
				TArray<TLBaseObject>());

			Invoke(SendMessageRequest);

			return UserError(SendMessageRequest.GetLastErrorMessage(), SendMessageRequest.GetLastErrorCode());
		}
	}
	return AuthorizeError;
}

UserError TelegramClient::IsUserAuthorized()
{
	if (!Sender->IsConnected()) return UserError(-1);
	COMMON::InputUser InputUser;
	TArray<COMMON::InputUser> UserVector;
	UserVector.Add(InputUser);
	USERS::GetUsers IsAuthorizedRequest(UserVector);
	bUserAuthorized = true;

	Invoke(IsAuthorizedRequest);

	UserError Error(IsAuthorizedRequest.GetLastErrorMessage(), IsAuthorizedRequest.GetLastErrorCode());

	if (Error.GetError() == EMTProtoErrors::AuthKeyUnregistered)
		bUserAuthorized = false;

	//delete InputUser;
	return Error;
}

UserError TelegramClient::LogOut()
{
	AUTH::LogOut LogOutRequest;
	Invoke(LogOutRequest);
	ClientSession->Delete();
	ClientSession->GenerateNewSessionID();
	Sender->UpdateTransport(ClientSession.Get());
	return true; // we don't get response for this
}

bool TelegramClient::CreateNewSession()
{
	ClientSession->GenerateNewSessionID(); //effectively creating new session 
	ClientSession->Save();
	bool IsDisconnected = Sender->Disconnect();
	bool IsUpdated = Sender->UpdateTransport(ClientSession.Get());
	bool IsConected = Connect().GetError() == EMTProtoErrors::RequestOK;
	ClientSession->SetSequence(0);
	return IsDisconnected && IsUpdated && IsConected;
}

