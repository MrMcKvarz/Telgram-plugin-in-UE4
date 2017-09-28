#include "TelegramClient.h"
#include "network/Authenticator.h"
#include "network/TCPTransport.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
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
	ClientSession->Load();	
}

TelegramClient::~TelegramClient()
{
	if(Sender)
		delete Sender;
}

bool TelegramClient::Connect()
{
	FIPv4Address TelegramServer;
	FIPv4Address::Parse(ClientSession->GetServerAddress(), TelegramServer);

	TCPTransport Transport(TelegramServer, ClientSession->GetPort());
	/*Connect here and close only when program is done*/
	/*This is due to FSocket bug*/
	Transport.Connect(); 

	if(ClientSession->GetAuthKey().GetKey().Num() == 0)
	{
		AuthKey AuthKeyData = Authenticator::Authenticate(&Transport);
		ClientSession->SetAuthKey(AuthKeyData);

		if (ClientSession->Save())
			UE_LOG(LogTemp, Warning, TEXT("Session saved"));
	}

	HELP::GetConfig ConfigRequest;
	COMMON::InitConnection InitRequest(API_ID, ClientSession->GetDeviceModel(), ClientSession->GetSystemVersion(), ClientSession->GetAppVersion(), ClientSession->GetSystemLangCode(),
		ClientSession->GetLangPack(), ClientSession->GetLangCode(), &ConfigRequest);
	COMMON::InvokeWithLayer InvokeWithLayerRequest(71, &InitRequest);

	Sender = new MTProtoSender(&Transport, ClientSession);


	Invoke(InvokeWithLayerRequest);
	COMMON::Config* ConfigResult = reinterpret_cast<COMMON::Config*>(InvokeWithLayerRequest.GetResult());

	ClientSession->DCOptions = ConfigResult->GetDcOptions();

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
	FString PhoneNumber = FString("9996621234");
	if (!IsUserAuthorized)
	{
// 		AUTH::SendCode SendCodeRequest(false, PhoneNumber, false, API_ID, API_Hash);
// 		Invoke(SendCodeRequest);
// 		FString PhoneHashCode = SendCodeRequest.GetResult()->GetPhoneCodeHash();
// 		FString Path;
// 		Path += FPaths::GamePluginsDir();
// 		Path += "CrunchPower.txt";
// 		FString PhoneCode;
// 		(!FFileHelper::LoadFileToString(PhoneCode, Path.GetCharArray().GetData()));
// 		AUTH::SignIn SingInRequest(PhoneNumber, PhoneHashCode, PhoneCode);
// 		Invoke(SingInRequest);
// 		MESSAGES::GetDialogs GetDialogRequest(false, FDateTime(),0,new PRIVATE::InputPeer(),10);
// 		Invoke(GetDialogRequest);
// 		auto GetDialogResult = GetDialogRequest.GetResult();
	}


// 	if (ClientSession->Save())
// 		UE_LOG(LogTemp, Warning, TEXT("Session prob saved 2"));

	return true;
}

bool TelegramClient::Invoke(TLBaseObject &Request)
{
	//auto wrtf = typeid(Request).name();
	if (!Request.IsContentRelated()) return false;
	int32 InitSent = Sender->Send(Request);
	Sender->Receive(Request);
	return true;
}


