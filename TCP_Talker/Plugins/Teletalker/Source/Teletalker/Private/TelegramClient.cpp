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
	ClientSession->Load();	
}

TelegramClient::~TelegramClient()
{
	if (Transport) delete Transport;
	if (ClientSession) delete ClientSession;
}

bool TelegramClient::Connect()
{
	FIPv4Address TelegramServer;
	FIPv4Address::Parse(ClientSession->GetServerAddress(), TelegramServer);

	Transport = new TCPTransport(TelegramServer, ClientSession->GetPort());
	/*Connect here and close only when program is done*/
	/*This is due to FSocket bug*/
	Sender = TSharedPtr<MTProtoSender>(new MTProtoSender(Transport, ClientSession));
	Sender->Connect();
	if(ClientSession->GetAuthKey().GetKey().Num() == 0)
	{
		AuthKey AuthKeyData = Authenticator::Authenticate(Transport);
		ClientSession->SetAuthKey(AuthKeyData);

		if (ClientSession->Save())
			UE_LOG(LogTemp, Warning, TEXT("Session saved"));
	}

	HELP::GetConfig ConfigRequest;

	COMMON::InitConnection InitRequest(API_ID, ClientSession->GetDeviceModel(), ClientSession->GetSystemVersion(), ClientSession->GetAppVersion(), ClientSession->GetSystemLangCode(),
		ClientSession->GetLangPack(), ClientSession->GetLangCode(), &ConfigRequest);
	COMMON::InvokeWithLayer InvokeWithLayerRequest(71, &InitRequest);

	Invoke(InvokeWithLayerRequest);
	COMMON::Config* ConfigResult = reinterpret_cast<COMMON::Config*>(InvokeWithLayerRequest.GetResult());

	ClientSession->DCOptions = ConfigResult->GetDcOptions();

	return true;
}

bool TelegramClient::Authorize()
{
	if (!Sender->IsConnected()) return false;
	COMMON::InputUserSelf InputUser;
	TArray<TLBaseObject*> UserVector;
	UserVector.Add(&InputUser);
	USERS::GetUsers IsAuthorized(UserVector);

	bool IsUserAuthorized;
	try
	{
		Invoke(IsAuthorized);
	}
	catch (const std::system_error)
	{
		IsUserAuthorized = false;
	}
	FString PhoneNumber = FString("+380668816402");

	AUTH::SendCode SendCodeRequest(false, PhoneNumber, false, API_ID, API_Hash);
	Invoke(SendCodeRequest);
	FString PhoneHashCode = SendCodeRequest.GetResult()->GetPhoneCodeHash();
	FString Path;
	Path += FPaths::GamePluginsDir();
	Path += "CrunchPower.txt";
	FString PhoneCode;
	(!FFileHelper::LoadFileToString(PhoneCode, Path.GetCharArray().GetData()));
	AUTH::SignIn SingInRequest(PhoneNumber, PhoneHashCode, PhoneCode);
	Invoke(SingInRequest);
	MESSAGES::GetDialogs GetDialogRequest(false, FDateTime::MinValue(), 0, new COMMON::InputPeerEmpty(), 10);
	Invoke(GetDialogRequest);
	MESSAGES::DialogsSlice * GetDialogResult = reinterpret_cast<MESSAGES::DialogsSlice *> (GetDialogRequest.GetResult());

	//TArray<PRIVATE::Peer*> Peers;
	TArray<FString> DialogsNames;
	for (auto dialog : GetDialogResult->Getdialogs())
	{
		COMMON::PeerUser * Title = reinterpret_cast<COMMON::PeerUser *> (dialog->Getpeer());
	
		for (COMMON::User * user : GetDialogResult->Getusers())
			if (user->Getid() == Title->GetUserId())
				DialogsNames.Add(user->GetFirstName());
		for (COMMON::Chat * chat : GetDialogResult->Getchats())
			if (chat->Getid() == Title->GetUserId())
				DialogsNames.Add(chat->Gettitle());

	}
	UE_LOG(LogTemp, Warning, TEXT(""));
	for (auto dialognames : DialogsNames)
		UE_LOG(LogTemp, Warning, TEXT("%s"), *dialognames);

	COMMON::User * UserSendTo = nullptr;
	for (COMMON::User * user : GetDialogResult->Getusers())
		if (user->GetFirstName() == L"Yaroslav")
			UserSendTo = user;

	if(UserSendTo)
	{
		SendMessage(new COMMON::InputPeerUser(UserSendTo->Getid(), UserSendTo->GetAccessHash()), FString("Govnogram API "));
	}
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
	Connect();
}

bool TelegramClient::SendMessage(COMMON::InputPeerUser * Peer, FString Message)
{
	bool Result = false;
	if(Peer && !Message.IsEmpty())
	{
		MESSAGES::SendMessage SendMessageRequest(true, false, false, false, Peer, 0, Message, Crypto::GetRandomLong(), nullptr, TArray<PRIVATE::MessageEntity *>());
		Result = Invoke(SendMessageRequest);
	}
	return Result;
	
}

