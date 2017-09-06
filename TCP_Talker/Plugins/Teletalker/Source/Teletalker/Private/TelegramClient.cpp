#include "TelegramClient.h"
#include "network/Authenticator.h"
#include "network/TCPTransport.h"
#include "MTProtoSender.h"

/*Prob should not be here*/
#include "extensions/BinaryReader.h"
#include "extensions/BinaryWriter.h"

#define UI UI_ST
THIRD_PARTY_INCLUDES_START
#include "tl/Session.h"
//#include "IPv4Address.h"
THIRD_PARTY_INCLUDES_END
#undef UI


TelegramClient::TelegramClient(FString SessionName, int32 API_id, FString API_hash)
{
	ClientSession = new Session(SessionName);
	API_ID = API_id;
	API_Hash = API_hash;
}

bool TelegramClient::Connect(FString AuthKey)
{
	FIPv4Address TelegramServer;
	FIPv4Address::Parse(ClientSession->GetServerAddress(), TelegramServer);

	TCPTransport Transport(TelegramServer, ClientSession->GetPort());
	
	TArray<unsigned char> AuthKeyData = Authenticator::Authenticate(&Transport);
	AuthKey = FString::FromBlob(AuthKeyData.GetData(), AuthKeyData.Num());
	ClientSession->SetAuthKey(AuthKeyData);
	if(ClientSession->Save())
		UE_LOG(LogTemp, Warning, TEXT("Session prob saved"));

	MTProtoSender Sender(&Transport, ClientSession);
// 	if(Sender.Connect())
// 		UE_LOG(LogTemp, Warning, TEXT("MTProtoSender connected"));
	BinaryWriter InitConnection;
	InitConnection.WriteInt(API_ID);
	InitConnection.TGWriteString(ClientSession->GetDeviceModel());
	InitConnection.TGWriteString(ClientSession->GetSystemVersion());
	InitConnection.TGWriteString(ClientSession->GetAppVersion());
	InitConnection.TGWriteString(ClientSession->GetLangCode());
	InitConnection.TGWriteString(ClientSession->GetSystemLangCode());
	InitConnection.TGWriteString(ClientSession->GetLangPack());
	InitConnection.WriteInt(0xc4f9186b); // get config request constructor
	int32 InitSent = Sender.Send(InitConnection.GetBytes().GetData(), InitConnection.GetWrittenBytesCount());
	UE_LOG(LogTemp, Warning, TEXT("Init sent %d"), InitSent);

	return true;

}
