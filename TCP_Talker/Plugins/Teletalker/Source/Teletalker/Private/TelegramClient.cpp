#include "TelegramClient.h"
#include "network/Authenticator.h"
#include "network/TCPTransport.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "MTProtoSender.h"
#include "crypto/AuthKey.h"

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
			UE_LOG(LogTemp, Warning, TEXT("Session prob saved"));
	}

	/*This data is valid for request*/
	BinaryWriter InitConnection;
	/*TL init with layer*/
	InitConnection.WriteInt(0xda9b0d0d);
	InitConnection.WriteInt(70);
	/*TL init connection*/
	InitConnection.WriteInt(0xc7481da6);
	InitConnection.WriteInt(API_ID);
	InitConnection.TGWriteString(ClientSession->GetDeviceModel());
	InitConnection.TGWriteString(ClientSession->GetSystemVersion());
	InitConnection.TGWriteString(ClientSession->GetAppVersion());
	InitConnection.TGWriteString(ClientSession->GetSystemLangCode());
	InitConnection.TGWriteString(ClientSession->GetLangPack());
	InitConnection.TGWriteString(ClientSession->GetLangCode());
	/*TL get config*/
 	InitConnection.WriteInt(0xc4f9186b); // get config request constructor
 
// 	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 	/*Python rsa encrypt test area*/
// 	FIPv4Address TeServer(127, 0, 0, 1);
// 	const int32 TePort = 27015;
// 
// 	FSocket *Sock = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("PythonEncrypt"), false);
// 
// 	auto Address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
// 	Address->SetIp(TeServer.Value);
// 	Address->SetPort(TePort);
// 
// 	const int32 TestReceive = 88;
// 	uint8 RecvKey[88];
// 	uint8 AuthRecv[256];
// 	Sock->Connect(*Address);
// 	int32 bytessent = -1;
// 	//Sock->Send((uint8 *)AuthKeyData.GetData(), AuthKeyData.Num(), bytessent);
// 	//std::this_thread::sleep_for(std::chrono::milliseconds(10));
// 	int32 CipherRead;
// 	Sock->Recv(RecvKey, TestReceive, CipherRead);
// 	TArray<unsigned char> MessageKey = CalculateMessageKey(RecvKey, CipherRead);
/*	Sock->Recv(AuthRecv, 256, teasd);*/
	// 	/*End test area*/
	// 	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	MTProtoSender Sender(&Transport, ClientSession);

	int32 InitSent = Sender.Send(InitConnection.GetBytes().GetData(), InitConnection.GetWrittenBytesCount());
	auto Recv = Sender.Receive();
	InitSent = Sender.Send(InitConnection.GetBytes().GetData(), InitConnection.GetWrittenBytesCount());
	Recv = Sender.Receive();
	BinaryReader NEwReader(Recv.GetData(), Recv.Num());
	uint32 BadResponse = NEwReader.ReadInt();

	if (ClientSession->Save())
		UE_LOG(LogTemp, Warning, TEXT("Session prob saved 2"));

	return true;

}



