#include "TelegramClient.h"
#include "network/Authenticator.h"
#include "network/TCPTransport.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "Crypto.h"
#include "MTProtoSender.h"
#include <typeinfo> 
/*prob should not be here*/
#include <exception>
#include <system_error>
#include <chrono>
#include <thread>
/*TL objects*/
#include "../TL/AllObjects.h"
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

bool TelegramClient::Connect()
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
	COMMON::InvokeWithLayer * InvokeWithLayerRequest = new COMMON::InvokeWithLayer(CurrentLayer(), InitRequest);
	Invoke(*InvokeWithLayerRequest);

	COMMON::Config* ConfigResult = reinterpret_cast<COMMON::Config*>(InvokeWithLayerRequest->GetResult());

	for (auto DCOption : ConfigResult->GetDcOptions())
		ClientSession->DCOptions.Add(*DCOption);

	UE_LOG(LogTemp, Warning, TEXT("Telegram Client connect"));
	delete InvokeWithLayerRequest;
	return true;
}

void TelegramClient::GenerateNewAuthKey()
{

	AuthKey AuthKeyData = Authenticator::Authenticate(ClientSession->GetServerAddress(), ClientSession->GetPort());
	ClientSession->SetAuthKey(AuthKeyData);
	Sender->SetTimeOffset(Authenticator::TimeOffset);
	bAuthanticated = true;
	return;
}

bool TelegramClient::SendCode(FString NewPhoneNumber)
{
	this->PhoneNumber = NewPhoneNumber;
	if(!IsUserAuthorized())
	{
		AUTH::SendCode SendCodeRequest(true, PhoneNumber, true, API_ID, API_Hash);
		Invoke(SendCodeRequest);
		PhoneHashCode = SendCodeRequest.GetResult()->GetPhoneCodeHash();
	}
	return true;
}

bool TelegramClient::Invoke(TLBaseObject &Request)
{
	if (!Request.IsContentRelated()) return false;
	UE_LOG(LogTemp, Warning, TEXT("Send begin"));
	int32 InitSent = Sender->Send(Request);
	UE_LOG(LogTemp, Warning, TEXT("receive begin"));
	Sender->Receive(Request);

	return true;
}

bool TelegramClient::Reconnect()
{
	GenerateNewAuthKey();
	return CreateNewSession();
}

TArray<FString> TelegramClient::GetDialogSlice(int32 SliceNumber)
{
	//if (!IsUserAuthorized()) return TArray<FString>();
	MESSAGES::GetDialogs GetDialogRequest(false, FDateTime::MinValue(), 0, new COMMON::InputPeerEmpty(), 0);
	Invoke(GetDialogRequest);
	TArray<FString> DialogsNames;
	if (GetDialogRequest.GetResult()->GetConstructorID() == 0x71e094f3)
	{
		MESSAGES::DialogsSlice * GetDialogResult = reinterpret_cast<MESSAGES::DialogsSlice *> (GetDialogRequest.GetResult());
		for (COMMON::Dialog * dialog : GetDialogResult->Getdialogs())
		{
			COMMON::PeerUser * Title = reinterpret_cast<COMMON::PeerUser *> (dialog->Getpeer());
			//Save all users
			for (COMMON::User * User : GetDialogResult->Getusers())
			{
				if (User)
					Users.Add(*User);
			}
			//Get all users names
			for (COMMON::User * user : GetDialogResult->Getusers())
				if (user->Getid() == Title->GetUserId())
					DialogsNames.Add(user->GetFirstName());
			//Save all chats
			for (COMMON::Chat * Chat : GetDialogResult->Getchats())
			{
				if (Chat->GetConstructorID() == -652419756)
					Chats.Add(*Chat);
			}
			//Get all chats names
			for (COMMON::Chat * chat : GetDialogResult->Getchats())
				if (chat->Getid() == Title->GetUserId())
					DialogsNames.Add(chat->Gettitle());
		}
	}
	else
	{
		MESSAGES::Dialogs * GetDialogResult = reinterpret_cast<MESSAGES::Dialogs *> (GetDialogRequest.GetResult());
		for (COMMON::Dialog * dialog : GetDialogResult->Getdialogs())
		{
			COMMON::PeerUser * Title = reinterpret_cast<COMMON::PeerUser *> (dialog->Getpeer());
			for (COMMON::User *  User : GetDialogResult->Getusers())
			{
				if (User)
					Users.Add(*User);
			}
			for (COMMON::User * user : GetDialogResult->Getusers())
				if (user->Getid() == Title->GetUserId())
					DialogsNames.Add(user->GetFirstName());
			for (COMMON::Chat * Chat : GetDialogResult->Getchats())
			{
				if (Chat->GetConstructorID() == -652419756)
					Chats.Add(*Chat);
			}
			for (COMMON::Chat * chat : GetDialogResult->Getchats())
				if (chat->Getid() == Title->GetUserId())
					DialogsNames.Add(chat->Gettitle());
		}
	}
	return DialogsNames;
}

bool TelegramClient::SingIn(FString Code)
{
	AUTH::SignIn SingInRequest(PhoneNumber, PhoneHashCode, Code);
	Invoke(SingInRequest);
	return true;
}

bool TelegramClient::SendMessage(FString UserSendTo, FString Message)
{
	if (!IsUserAuthorized()) return false;
	COMMON::User User;
	for (COMMON::User user : Users)
		if (user.GetFirstName() == UserSendTo)
			User = user;

	bool Result = false;
	if(!Message.IsEmpty())
	{
		MESSAGES::SendMessage SendMessageRequest(
			true, 
			false, 
			false, 
			false, 
			new COMMON::InputPeerUser(User.Getid(), User.GetAccessHash()),
			0, 
			Message, 
			Crypto::GetRandomLong(), 
			nullptr, 
			TArray<TLBaseObject *>() );

		Result = Invoke(SendMessageRequest);
	}
	return Result;	
}

bool TelegramClient::IsUserAuthorized()
{
	if (!Sender->IsConnected()) return false;
	COMMON::InputUser *  InputUser = new COMMON::InputUser();
	TArray<COMMON::InputUser*> UserVector;
	UserVector.Add(InputUser);
	USERS::GetUsers * IsAuthorizedRequest = new USERS::GetUsers(UserVector);
	bUserAuthorized = true;

	Invoke(*IsAuthorizedRequest);

	if (IsAuthorizedRequest->GetLastErrorMessage() == L"AUTH_KEY_UNREGISTERED")
		bUserAuthorized = false;

	//delete InputUser;
	delete IsAuthorizedRequest;
	return bUserAuthorized;
}

bool TelegramClient::LogOut()
{
	AUTH::LogOut LogOutRequest;
	Invoke(LogOutRequest);
	ClientSession->Delete();
	return true; // we don't get response for this
}

bool TelegramClient::CreateNewSession()
{
	ClientSession->GenerateNewSessionID(); //effectively creating new session 
	ClientSession->Save();
	bool IsDisconnected = Sender->Disconnect();
	bool IsUpdated = Sender->UpdateTransport(ClientSession.Get());
	bool IsConected = Connect();
	ClientSession->SetSequence(0);
	return IsDisconnected && IsUpdated && IsConected;
}

