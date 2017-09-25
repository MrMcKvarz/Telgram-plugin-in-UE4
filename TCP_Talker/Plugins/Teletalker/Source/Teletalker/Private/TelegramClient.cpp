#include "TelegramClient.h"
#include "network/Authenticator.h"
#include "network/TCPTransport.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "MTProtoSender.h"
/*#include "crypto/AuthKey.h"*/

/*TL objects*/
//#include "../TL/AllObjects.h"
#include "TL/Functions/HELP/Public/GetConfig.h"
#include "TL/Functions/COMMON/Public/InitConnection.h"
#include "TL/Functions/COMMON/Public/InvokeWithLayer.h"
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

	MTProtoSender Sender(&Transport, ClientSession);

	int32 InitSent = Sender.Send(InvokeWithLayerRequest);
  	auto Recv = Sender.Receive(InvokeWithLayerRequest);

// 	BinaryWriter StringWriter;
// 	StringWriter.TGWriteString(FString("192.168.15.46"));
// 	BinaryReader StringReader(StringWriter.GetBytes().GetData(), StringWriter.GetWrittenBytesCount());
// 	FString Result = StringReader.TGReadString();

// 	BinaryReader NEwReader(Recv.GetData(), Recv.Num());
// 	uint32 BadResponse = NEwReader.ReadInt();

// 	if (ClientSession->Save())
// 		UE_LOG(LogTemp, Warning, TEXT("Session prob saved 2"));

	return true;
}

bool TelegramClient::Invoke(TLBaseObject &Request)
{
	//if()
	return true;
}


