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
	SendAcknowledges();
	return SendPacket(Data, Size);
}

TArray<unsigned char> MTProtoSender::Receive()
{
	if (Transport == nullptr) return TArray<unsigned char>();

	auto Response = Transport->Receive();
	auto Decoded = DecodeMessage(Response);
	return ProcessMessage(Decoded);
}

void MTProtoSender::SendAcknowledges()
{
	if (NeedConfirmation.Num() != 0)
	{
		BinaryWriter Writer;
		Writer.WriteInt(0x62d6b459); // Message acknowledge constructor
		Writer.WriteInt(0x1cb5c415); //Vector constructor
		Writer.WriteInt(NeedConfirmation.Num());
		for (auto Message : NeedConfirmation)
			Writer.WriteLong(Message);
		SendPacket(Writer.GetBytes().GetData(), Writer.GetWrittenBytesCount());
		NeedConfirmation.Empty(1);
	}
}

int32 MTProtoSender::SendPacket(unsigned char * Data, int32 Size)
{
	BinaryWriter PlainWriter;

	PlainWriter.WriteLong(MTSession->GetSalt());
	PlainWriter.WriteLong(MTSession->GetID());
	PlainWriter.WriteLong(GetNewMessageID());
	PlainWriter.WriteInt(MTSession->GetSequence());
	PlainWriter.WriteInt(Size);
	PlainWriter.Write(Data, Size);

	TArray<unsigned char> MessageKey = CalculateMessageKey(PlainWriter.GetBytes().GetData(), PlainWriter.GetWrittenBytesCount());

	TArray<unsigned char> Key, IV;
	Crypto::CalculateKey(MTSession->GetAuthKey().GetKey(), MessageKey,/*out*/ Key,/*out*/ IV, true);
	
	AES_KEY EncryptAESKey;
	if ((AES_set_encrypt_key(Key.GetData(), 256, &EncryptAESKey) != 0))
		return 0;

	int32 DHEncDataPadding;
	if (PlainWriter.GetWrittenBytesCount() % 16 != 0)
	{
		DHEncDataPadding = 16 - (PlainWriter.GetWrittenBytesCount() % 16);
		PlainWriter.Write(Data, DHEncDataPadding); //writing random(from data) padding bytes
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
	NeedConfirmation.Add(MTSession->GetLastMsgID());
	BinaryReader MessageReader(Message.GetData(), Message.Num());
	int32 Response = MessageReader.ReadInt();

	if (Response == 0xedab447b) // bad server salt
	{
		UE_LOG(LogTemp, Warning, TEXT("Bad server salt"));
		HandleBadServerSalt(Message);	
	}
	if (Response == 0xf35c6d01)  // rpc_result, (response of an RPC call, i.e., we sent a request)
		UE_LOG(LogTemp, Warning, TEXT("rpc_result"));
	if (Response == 0x347773c5)  // pong
		UE_LOG(LogTemp, Warning, TEXT("pong"));
	if (Response == 0x73f1f8dc)  // msg_container
		UE_LOG(LogTemp, Warning, TEXT("msg container"));
	if (Response == 0x3072cfa1)  // gzip_packed
		UE_LOG(LogTemp, Warning, TEXT("gzip packed"));
	if (Response == 0xa7eff811)  // bad_msg_notification
		UE_LOG(LogTemp, Warning, TEXT("Bad msg notify"));
	// msgs_ack, it may handle the request we wanted
	if (Response == 0x62d6b459)
		UE_LOG(LogTemp, Warning, TEXT("Bad msg ack"));

	return Message;
}

TArray<unsigned char> MTProtoSender::DecodeMessage(TArray<unsigned char> Message)
{
	if(Message.Num() < 8) 
		UE_LOG(LogTemp, Error, TEXT("Packet receive failure"));

	BinaryReader Reader(Message.GetData(), Message.Num());
	unsigned long long RemoteAuthID = Reader.ReadLong();
	if(RemoteAuthID != MTSession->GetAuthKey().GetKeyID())
		UE_LOG(LogTemp, Error, TEXT("Auth id from server is invalid"));
	TArray<unsigned char> RemoteMessageKey = Reader.Read(16);

	TArray<unsigned char> Key, IV;
	Crypto::CalculateKey(MTSession->GetAuthKey().GetKey(), RemoteMessageKey,/*out*/ Key,/*out*/ IV, false);

	AES_KEY DecryptAESKey;
	if ((AES_set_decrypt_key(Key.GetData(), 256, &DecryptAESKey) != 0))
		UE_LOG(LogTemp, Error, TEXT("Failed creating decrypt key"));

	int32 PlainMessageLength = Reader.GetBytes().Num() - Reader.GetOffset();

	unsigned char PlainText[2048];
	AES_ige_encrypt((unsigned char *)Reader.Read(PlainMessageLength).GetData(), PlainText, PlainMessageLength, &DecryptAESKey, IV.GetData(), AES_DECRYPT);

	BinaryReader PlainReader(PlainText, PlainMessageLength);
	PlainReader.ReadLong(); // remote salt
	PlainReader.ReadLong(); // remote session id
	unsigned long long RemoteMessageID = PlainReader.ReadLong();
	MTSession->SetLastMsgID(RemoteMessageID);
	uint32 RemoteSequence = PlainReader.ReadInt();
	uint32 MessageLength = PlainReader.ReadInt();
	auto RemoteMessage = PlainReader.Read(MessageLength);

	return RemoteMessage;
}

bool MTProtoSender::HandleBadServerSalt(TArray<unsigned char> Message)
{
// 	reader.read_int(signed = False)  # code
// 		bad_msg_id = reader.read_long()
// 		reader.read_int()  # bad_msg_seq_no
// 		reader.read_int()  # error_code
// 		new_salt = reader.read_long(signed = False)
// 		self.session.salt = new_salt
// 
// 		try :
// 		request = next(r for r in self._pending_receive
// 			if r.request_msg_id == bad_msg_id)
// 
// 		self.send(request)
	BinaryReader Reader(Message.GetData(), Message.Num());
	unsigned long long BadMessageID = Reader.ReadLong();
	Reader.ReadInt(); // bad message sequence number
	Reader.ReadInt(); // error code
	unsigned long long NewSalt = Reader.ReadLong();
 	MTSession->SetSalt(NewSalt);
	MTSession->Save();
	return true;
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
