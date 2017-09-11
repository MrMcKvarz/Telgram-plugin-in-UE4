#include "MTProtoSender.h"
#include "network/TCPTransport.h"
#define UI UI_ST
#include "tl/Session.h"
#include "openssl/sha.h"
#include "openssl/aes.h"
#undef UI
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "crypto/Crypto.h"

MTProtoSender::MTProtoSender(TCPTransport * Transport, Session * NewSession)
	: MTProtoPlainSender(Transport)
{
	if (NewSession == nullptr)
		MTSession = new Session("MTSession");
	else
		MTSession = NewSession;
}

int32 MTProtoSender::Send(unsigned char * Data, int32 Size)
{
	if (Transport == nullptr) return 0;
	return SendPacket(Data, Size);
}

TArray<unsigned char> MTProtoSender::Receive()
{
	if (Transport == nullptr) return TArray<unsigned char>();
	auto Response = Transport->Receive();
	return ProcessMessage(DecodeMessage(Response));
}

int32 MTProtoSender::SendPacket(unsigned char * Data, int32 Size)
{
	BinaryWriter PlainWriter;

	PlainWriter.WriteLong(MTSession->GetSalt());
	PlainWriter.WriteLong(MTSession->GetID());
	PlainWriter.WriteLong(GetNewMessageID());
	PlainWriter.WriteInt(Sequence++);
	PlainWriter.WriteInt(Size);
	PlainWriter.Write(Data, Size);

	TArray<unsigned char> MessageKey = CalculateMessageKey(PlainWriter.GetBytes().GetData(), PlainWriter.GetWrittenBytesCount());

	TArray<unsigned char> Key, IV;
	Crypto::CalculateKey(MTSession->GetAuthKey().GetKey(), MessageKey,/*out*/ Key,/*out*/ IV);
	
	AES_KEY EncryptAESKey;
	if ((AES_set_encrypt_key(Key.GetData(), 256, &EncryptAESKey) != 0))
		return 0;

	int32 DHEncDataPadding;
	if (PlainWriter.GetWrittenBytesCount() % 16 != 0)
	{
		DHEncDataPadding = 16 - (PlainWriter.GetWrittenBytesCount() % 16);
		PlainWriter.Write(Data, DHEncDataPadding); //write padding bytes
	}

	unsigned char CipherText[2048];
	AES_ige_encrypt((unsigned char *)PlainWriter.GetBytes().GetData(), CipherText, PlainWriter.GetWrittenBytesCount(), &EncryptAESKey, IV.GetData(), AES_ENCRYPT);

	BinaryWriter CipherWriter;
	CipherWriter.WriteLong(MTSession->GetAuthKey().GetKeyID());
	CipherWriter.Write(MessageKey.GetData(), MessageKey.Num());
	CipherWriter.Write(CipherText, PlainWriter.GetWrittenBytesCount());
	return Transport->Send(CipherWriter.GetBytes().GetData(), CipherWriter.GetWrittenBytesCount());
}

TArray<unsigned char> MTProtoSender::ProcessMessage(TArray<unsigned char> Message)
{
// 	BinaryReader MessageReader(Message.GetData(), Message.Num());
// 	int32 Response = MessageReader.ReadInt();
// 
// 	if (Response == 0xedab447b)
// 		UE_LOG(LogTemp, Warning, TEXT("Bad server salt"));
// 	if (Response == 0xf35c6d01)  // rpc_result, (response of an RPC call, i.e., we sent a request)
// 		UE_LOG(LogTemp, Warning, TEXT("rpc_result"));
// 	if (Response == 0x347773c5)  // pong
// 		UE_LOG(LogTemp, Warning, TEXT("pong"));
// 	if (Response == 0x73f1f8dc)  // msg_container
// 		UE_LOG(LogTemp, Warning, TEXT("msg container"));
// 	if (Response == 0x3072cfa1)  // gzip_packed
// 		UE_LOG(LogTemp, Warning, TEXT("gzip packed"));
// 	if (Response == 0xa7eff811)  // bad_msg_notification
// 		UE_LOG(LogTemp, Warning, TEXT("Bad msg notify"));
// 	// msgs_ack, it may handle the request we wanted
// 	if (Response == 0x62d6b459)
// 		UE_LOG(LogTemp, Warning, TEXT("Bad msg ack"));

	return TArray<unsigned char>();
}

TArray<unsigned char> MTProtoSender::DecodeMessage(TArray<unsigned char> Message)
{
	if(Message.Num() < 8) 
		UE_LOG(LogTemp, Error, TEXT("Packet receive failure"));

	BinaryReader Reader(Message.GetData(), Message.Num());
	unsigned long long RemoteAuthID = Reader.ReadLong();
	TArray<unsigned char> RemoteMessageKey = Reader.Read(16);

	TArray<unsigned char> Key, IV;
	Crypto::CalculateKey(MTSession->GetAuthKey().GetKey(), RemoteMessageKey,/*out*/ Key,/*out*/ IV);

	AES_KEY DecryptAESKey;
	if ((AES_set_decrypt_key(Key.GetData(), 256, &DecryptAESKey) != 0))
		UE_LOG(LogTemp, Error, TEXT("Failed creating dectypt key"));

	int32 PlainMessageLength = Reader.GetBytes().Num() - Reader.GetOffset();

	unsigned char PlainText[2048];
	AES_ige_encrypt((unsigned char *)Reader.Read(PlainMessageLength).GetData(), PlainText, PlainMessageLength, &DecryptAESKey, IV.GetData(), AES_DECRYPT);

	BinaryReader PlainReader(PlainText, PlainMessageLength);
	PlainReader.ReadLong(); // remote salt
	PlainReader.ReadLong(); // remote session id
	unsigned long long RemoteMessageID = PlainReader.ReadLong();
	uint32 RemoteSequence = PlainReader.ReadInt();
	uint32 MessageLength = PlainReader.ReadInt();
	//auto RemoteMessage = PlainReader.Read(MessageLength);

	return TArray<unsigned char>();
}

TArray<unsigned char> MTProtoSender::CalculateMessageKey(unsigned char * Data, int32 Size)
{
	unsigned char SHAResult[20];
	SHA1(Data, Size, SHAResult);
	TArray<unsigned char> Temp;
	for (int32 i = 4; i < 20; i++)
		Temp.Add(SHAResult[i]);
	return Temp;
}

bool MTProtoSender::Connect()
{
	if (Transport == nullptr) return false;
	return Transport->Connect();
}
