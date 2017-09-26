#include "TelegramClient.h"
#include "network/Authenticator.h"
#include "network/TCPTransport.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "MTProtoSender.h"
/*#include "crypto/AuthKey.h"*/

/*TL objects*/
//#include "../TL/AllObjects.h"
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

	auto ConfigResult = reinterpret_cast<COMMON::Config*>(Invoke(InvokeWithLayerRequest));

	auto DCOptions = ConfigResult->dc_options;

	COMMON::InputUserSelf InputUser;
	TArray<TLBaseObject*> UserVector;
	UserVector.Add(&InputUser);
	USERS::GetUsers IsAuthorized(UserVector);

	auto IsAuthorizedResult = reinterpret_cast<COMMON::Config*>(Invoke(IsAuthorized));


// 	if (ClientSession->Save())
// 		UE_LOG(LogTemp, Warning, TEXT("Session prob saved 2"));

	return true;
}

TLBaseObject * TelegramClient::Invoke(TLBaseObject &Request)
{
	int32 InitSent = Sender->Send(Request);
	Sender->Receive(Request);
	return Request.GetResult();
}


