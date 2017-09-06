#include "TelegramClient.h"
#include "network/Authenticator.h"
#include "network/TCPTransport.h"

#define UI UI_ST
THIRD_PARTY_INCLUDES_START
#include "tl/Session.h"
//#include "IPv4Address.h"
THIRD_PARTY_INCLUDES_END
#undef UI

TelegramClient::TelegramClient()
{
	ClientSession = new Session("");
	API_ID = 0;
	API_Hash = "";
}

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



	return true;

}
