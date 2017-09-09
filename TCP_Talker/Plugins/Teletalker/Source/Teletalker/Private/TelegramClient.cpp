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
	ClientSession->SetAuthKey(AuthKeyData);
	AuthKey = FString::FromBlob(AuthKeyData.GetData(), AuthKeyData.Num());

	if (ClientSession->Save())
		UE_LOG(LogTemp, Warning, TEXT("Session prob saved"));

	MTProtoSender Sender(&Transport, ClientSession);
	// 	if(Sender.Connect()) /*sender is not disconnected in authentication*/
	// 		UE_LOG(LogTemp, Warning, TEXT("MTProtoSender connected"));
	BinaryWriter InitConnection;
	/*TL init with layer*/
	InitConnection.WriteInt(0xda9b0d0d);
	InitConnection.WriteInt(71);
	/*TL init connection*/
	InitConnection.WriteInt(0xc7481da6);
	InitConnection.WriteInt(API_ID);
	InitConnection.TGWriteString(ClientSession->GetDeviceModel());
	InitConnection.TGWriteString(ClientSession->GetSystemVersion());
	InitConnection.TGWriteString(ClientSession->GetAppVersion());
	InitConnection.TGWriteString(ClientSession->GetLangCode());
	InitConnection.TGWriteString(ClientSession->GetSystemLangCode());
	InitConnection.TGWriteString(ClientSession->GetLangPack());
	/*TL get config*/
	InitConnection.WriteInt(0xc4f9186b); // get config request constructor

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*Python rsa encrypt test area*/
// 	FIPv4Address TeServer(127, 0, 0, 1);
// 	const int32 TePort = 27015;
// 
// 	FSocket *Sock = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("PythonEncrypt"), false);
// 
// 	auto Address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
// 	Address->SetIp(TeServer.Value);
// 	Address->SetPort(TePort);
// 
// 	const int32 TestReceive = 120;
// 	uint8 RecvKey[120];
// 	Sock->Connect(*Address);
// 	//Sock->Send((uint8 *)AuthKey.GetData(), AuthKey.Num(), bytessent);
// 	// 	Sock->Send((uint8 *)NewNonceHash1.GetData(), NewNonceHash1.Num(), bytessent);
// 	// 	Sock->Send((uint8 *)NewNonce.GetData(), NewNonce.Num(), bytessent);
// 	//std::this_thread::sleep_for(std::chrono::milliseconds(10));
// 	int32 CipherRead;
// 	Sock->Recv(RecvKey, TestReceive, CipherRead);
	// 	/*End test area*/
	// 	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Sender.Disconnect();

	int32 InitSent = Sender.Send(InitConnection.GetBytes().GetData(), InitConnection.GetWrittenBytesCount());
	auto Recv = Transport.Receive();

	UE_LOG(LogTemp, Warning, TEXT("Init sent %d"), InitSent);
 	UE_LOG(LogTemp, Warning, TEXT("Init received %d"), Recv.Num());
	return true;

}
