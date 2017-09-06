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

	//return Transport->Send(Packet.GetData(), Writer.GetWrittenBytesCount());
}

TArray<unsigned char> MTProtoSender::Receive(int32 Size)
{
	if (Transport == nullptr) return TArray<unsigned char>();
	auto Response = Transport->Receive();
	return ProcessMessage(Response);
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
	Crypto::CalculateKey(MTSession->GetAuthKey(), MessageKey, Key, IV);
	
	AES_KEY EncryptAESKey;
	if ((AES_set_encrypt_key(Key.GetData(), 256, &EncryptAESKey) != 0))
		return 0;

	int32 DHEncDataPadding;
	if (PlainWriter.GetWrittenBytesCount() % 16 != 0)
	{
		DHEncDataPadding = 16 - (PlainWriter.GetWrittenBytesCount() % 16);
		PlainWriter.Write(Data, DHEncDataPadding);
	}

	unsigned char CipherText[256];
	AES_ige_encrypt((unsigned char *)PlainWriter.GetBytes().GetData(), CipherText, PlainWriter.GetWrittenBytesCount(), &EncryptAESKey, IV.GetData(), AES_ENCRYPT);

	unsigned char AuthSHA[20];
	SHA1((unsigned char *)MTSession->GetAuthKey().GetData(), MTSession->GetAuthKey().Num(), AuthSHA);
	BinaryReader Reader(AuthSHA, 20);
	unsigned long long Aux_Hash = Reader.ReadLong();
	Reader.Read(4);
	unsigned long long Key_ID = Reader.ReadLong();

	BinaryWriter CipherWriter;
	CipherWriter.WriteLong(Key_ID);
	CipherWriter.Write(MessageKey.GetData(), MessageKey.Num());
	CipherWriter.Write(CipherText, 256);
	return Transport->Send(CipherWriter.GetBytes().GetData(), CipherWriter.GetWrittenBytesCount());
}

TArray<unsigned char> MTProtoSender::ProcessMessage(TArray<unsigned char> Message)
{
	BinaryReader MessageReader(Message.GetData(), Message.Num());
}

TArray<unsigned char> MTProtoSender::DecodeMessage(TArray<unsigned char> Message)
{

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
