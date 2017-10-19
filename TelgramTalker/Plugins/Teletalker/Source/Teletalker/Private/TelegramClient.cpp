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
	ClientSession = new Session(SessionName);
	API_ID = API_id;
	API_Hash = API_hash;
	bAuthorized = false;
	bAuthanticated = false;
	bUserAuthorized = false;
}

TelegramClient::~TelegramClient()
{
	if (ClientSession) delete ClientSession;
}

bool TelegramClient::Connect()
{

	/*Connect here and close only when program is done*/
 	/*This is due to FSocket bug*/
 	if(!Sender.IsValid())
	{
		Sender = TSharedPtr<MTProtoSender>(new MTProtoSender(ClientSession));
		Sender->SetClient(this);
	}

	if(!ClientSession->Load() || ClientSession->GetAuthKey().GetKeyID() == 0)
	{

		/*if (!Sender->IsConnected()) Sender->Connect();*/
		GenerateNewAuthKey();
		bAuthanticated = true;
		if (ClientSession->Save())
			UE_LOG(LogTemp, Warning, TEXT("Session saved"));
	}
	Sender->UpdateTransport(ClientSession);
	if (!Sender->IsConnected()) Sender->Connect();

	HELP::GetConfig ConfigRequest;

	COMMON::InitConnection InitRequest(API_ID, ClientSession->GetDeviceModel(), ClientSession->GetSystemVersion(), ClientSession->GetAppVersion(), ClientSession->GetSystemLangCode(),
		ClientSession->GetLangPack(), ClientSession->GetLangCode(), &ConfigRequest);
	COMMON::InvokeWithLayer InvokeWithLayerRequest(71, &InitRequest);

	Invoke(InvokeWithLayerRequest);
	COMMON::Config* ConfigResult = reinterpret_cast<COMMON::Config*>(InvokeWithLayerRequest.GetResult());

	ClientSession->DCOptions = ConfigResult->GetDcOptions();

	UE_LOG(LogTemp, Warning, TEXT("Telegram Client connect"));
	return true;
}

void TelegramClient::GenerateNewAuthKey()
{
	AuthKey AuthKeyData = Authenticator::Authenticate(ClientSession->GetServerAddress(), ClientSession->GetPort());
	ClientSession->SetAuthKey(AuthKeyData);
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
/*Crunch power
// 	FString Path;
// 	Path += FPaths::GamePluginsDir();
// 	Path += "CrunchPower.txt";
// 	FString PhoneCode;
// 	(!FFileHelper::LoadFileToString(PhoneCode, Path.GetCharArray().GetData()));
*/	
	return true;
}

bool TelegramClient::Invoke(TLBaseObject &Request)
{
	if (!Request.IsContentRelated()) return false;
	int32 InitSent = Sender->Send(Request);
	Sender->Receive(Request);
	return true;
}

void TelegramClient::Reconnect()
{
	ClientSession->GenerateNewSessionID(); //effectively creating new session 
	ClientSession->Save();
	bAuthanticated = false;
	bool disc = Sender->Disconnect();
	Sender->UpdateTransport(ClientSession);
	GenerateNewAuthKey();
	Connect();
}

TArray<FString> TelegramClient::GetDialogSlice(int32 SliceNumber)
{
	//if (!IsUserAuthorized()) return TArray<FString>();
	MESSAGES::GetDialogs GetDialogRequest(false, FDateTime::MinValue(), 0, new COMMON::InputPeerEmpty(), 0);
	Invoke(GetDialogRequest);
	MESSAGES::Dialogs * GetDialogResult = reinterpret_cast<MESSAGES::Dialogs *> (GetDialogRequest.GetResult());
	if (GetDialogResult == nullptr)
		int32 s = 2;
	//TArray<PRIVATE::Peer*> Peers;
	TArray<FString> DialogsNames;
	for (COMMON::Dialog * dialog : GetDialogResult->Getdialogs())
	{
		COMMON::PeerUser * Title = reinterpret_cast<COMMON::PeerUser *> (dialog->Getpeer());
		Users = GetDialogResult->Getusers();
		for (COMMON::User * user : GetDialogResult->Getusers())
			if (user->Getid() == Title->GetUserId())
				DialogsNames.Add(user->GetFirstName());
		Chats = GetDialogResult->Getchats();
		for (COMMON::Chat * chat : GetDialogResult->Getchats())
			if (chat->Getid() == Title->GetUserId())
				DialogsNames.Add(chat->Gettitle());

	}
	UE_LOG(LogTemp, Warning, TEXT(""));
	for (auto dialognames : DialogsNames)
		UE_LOG(LogTemp, Warning, TEXT("%s"), *dialognames);

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
	COMMON::User * User = nullptr;
	for (COMMON::User * user : Users)
		if (user->GetFirstName() == UserSendTo)
			User = user;
	if (!User) return false;

	bool Result = false;
	if(!Message.IsEmpty())
	{
		MESSAGES::SendMessage SendMessageRequest(
			true, 
			false, 
			false, 
			false, 
			new COMMON::InputPeerUser(User->Getid(), User->GetAccessHash()),
			0, 
			Message, 
			Crypto::GetRandomLong(), 
			nullptr, 
			TArray<PRIVATE::MessageEntity *>() );

		Result = Invoke(SendMessageRequest);
	}
	return Result;	
}

bool TelegramClient::IsUserAuthorized()
{
	if (!Sender->IsConnected()) return false;
	COMMON::InputUserSelf InputUser;
	TArray<TLBaseObject*> UserVector;
	UserVector.Add(&InputUser);
	USERS::GetUsers IsAuthorizedRequest(UserVector);
	bUserAuthorized = true;
	try
	{
		Invoke(IsAuthorizedRequest);
	}
	catch (const std::logic_error error)
	{
		bUserAuthorized = false;
	}
	return bUserAuthorized;
}



