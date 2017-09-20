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
#include "../../TL/TLObjectBase.h"
#include "../../TL/Types/COMMON//Public/MsgsAck.h"

MTProtoSender::MTProtoSender(TCPTransport * Transport, Session * NewSession)
	: MTProtoPlainSender(Transport)
{
	if (NewSession == nullptr)
		MTSession = new Session("MTSession");
	else
		MTSession = NewSession;
}

int32 MTProtoSender::Send(TLObject &Message)
{
	if (Transport == nullptr) return 0;
	SendAcknowledges();
	uint32 BytesSent = SendPacket(Message);
	ClientMessagesNeedAcknowledges.Add(Message);
	return BytesSent;
}

TArray<unsigned char> MTProtoSender::Receive(TLObject &Message)
{
	if (Transport == nullptr) return TArray<unsigned char>();
	TArray<unsigned char> Received;
	while(!Message.IsConfirmReceived())
	{
		auto Response = Transport->Receive();
		auto Decoded = DecodeMessage(Response);
		ProcessMessage(Decoded, Message);
	}
	return Received;
}

void MTProtoSender::SendAcknowledges()
{
	if (ServerMessagesNeedAcknowledges.Num() != 0)
	{
		COMMON::MsgsAck Acknowledge(ServerMessagesNeedAcknowledges);
// 		Writer.WriteInt(0x62d6b459); // Message acknowledge constructor
// 		Writer.WriteInt(0x1cb5c415); //Vector constructor
// 		Writer.WriteInt(ServerMessagesNeedAcknowledges.Num());
// 		for (uint64 Message : ServerMessagesNeedAcknowledges)
// 			Writer.WriteLong(Message);
		SendPacket(Acknowledge);
		ServerMessagesNeedAcknowledges.Empty(1);
	}
}

int32 MTProtoSender::SendPacket(TLObject &Message)
{
	BinaryWriter PlainWriter;

	Message.SetRequestMessageID(GetNewMessageID());
	PlainWriter.WriteLong(MTSession->GetSalt());
	PlainWriter.WriteLong(MTSession->GetID());
	PlainWriter.WriteLong(Message.GetRequestMessageID());

	bool ContentRelated = Message.IsContentRelated();
	PlainWriter.WriteInt(MTSession->GetSequence(ContentRelated));

	BinaryWriter MessageDataWriter;
	Message.OnSend(MessageDataWriter);
	uint32 MessageLength = MessageDataWriter.GetWrittenBytesCount();
	PlainWriter.WriteInt(MessageLength);
	PlainWriter.Write(MessageDataWriter.GetBytes().GetData(), MessageLength);

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
		PlainWriter.Write(MessageKey.GetData(), DHEncDataPadding); //writing random(from data) padding bytes
	}

	unsigned char CipherText[2048];
	AES_ige_encrypt((unsigned char *)PlainWriter.GetBytes().GetData(), CipherText, PlainWriter.GetWrittenBytesCount(), &EncryptAESKey, IV.GetData(), AES_ENCRYPT);

	BinaryWriter CipherWriter;
	CipherWriter.WriteLong(MTSession->GetAuthKey().GetKeyID());
	CipherWriter.Write(MessageKey.GetData(), MessageKey.Num());
	CipherWriter.Write(CipherText, PlainWriter.GetWrittenBytesCount());
	return Transport->Send(CipherWriter.GetBytes().GetData(), CipherWriter.GetWrittenBytesCount());
}

bool MTProtoSender::ProcessMessage(TArray<unsigned char> Message, TLObject &Request)
{
	ServerMessagesNeedAcknowledges.Add(MTSession->GetLastMsgID());
	BinaryReader MessageReader(Message.GetData(), Message.Num());
	int32 Response = MessageReader.ReadInt();

	if (Response == 0xedab447b) // bad server salt
	{
		UE_LOG(LogTemp, Warning, TEXT("Bad server salt"));	
		ServerMessagesNeedAcknowledges.Remove(MTSession->GetLastMsgID());
		return HandleBadServerSalt(Message, Request);
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
	if (Response == 0x9ec20908)
	{
		UE_LOG(LogTemp, Warning, TEXT("Session created"));
		return true;
	}
// 	if code == 0x62d6b459:
// 	ack = reader.tgread_object()
// 		for r in self._pending_receive :
// 			if r.request_msg_id in ack.msg_ids :
// 				self._logger.debug('Ack found for the a request')
// 
// 				if self.logging_out :
// 					r.confirm_received = True
// 
// 					return True
	if (Response == 0x62d6b459)
		0; 
	return false;
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
	unsigned long long BadSalt = PlainReader.ReadLong(); // remote salt
	unsigned long long RemoteSeesionID = PlainReader.ReadLong(); // remote session id
	unsigned long long RemoteMessageID = PlainReader.ReadLong();
	MTSession->SetLastMsgID(RemoteMessageID);
	uint32 RemoteSequence = PlainReader.ReadInt();
	uint32 MessageLength = PlainReader.ReadInt();
	auto RemoteMessage = PlainReader.Read(MessageLength);

	return RemoteMessage;
}

bool MTProtoSender::HandleBadServerSalt(TArray<unsigned char> Message, TLObject &Request)
{
	BinaryReader Reader(Message.GetData(), Message.Num());
	int32 Code = Reader.ReadInt();
	unsigned long long BadMessageID = Reader.ReadLong();
	int32 BadSequence =	Reader.ReadInt(); // bad message sequence number
	int32 ErrorCode = Reader.ReadInt(); // error code
	unsigned long long NewSalt = Reader.ReadLong();
 	MTSession->SetSalt(NewSalt);
	if(ClientMessagesNeedAcknowledges.Contains(Request))
		Send(Request);
	MTSession->Save();
	return true;
}

bool MTProtoSender::HandleMessageContainer(TArray<unsigned char> Message)
{
// 	reader.read_int(signed = False)  # code
// 	size = reader.read_int()
// 	for _ in range(size) :
// 		inner_msg_id = reader.read_long()
// 		reader.read_int()  # inner_sequence
// 		inner_length = reader.read_int()
// 		begin_position = reader.tell_position()
// 
// 		# Note that this code is IMPORTANT for skipping RPC results of
// 		# lost requests(i.e., ones from the previous connection session)
// 		try :
// 		if not self._process_msg(
// 			inner_msg_id, sequence, reader, updates) :
// 			reader.set_position(begin_position + inner_length)
// 			except :
// 			# If any error is raised, something went wrong; skip the packet
// 			reader.set_position(begin_position + inner_length)
// 			raise
// 
// 			return True

	BinaryReader Reader(Message.GetData(), Message.Num());
	uint32 Code = Reader.ReadInt();
	uint32 Size = Reader.ReadInt();
	for (uint32 i = 0; i < Size; i++)
	{
		unsigned long long InnerMessageID = Reader.ReadLong();
		Reader.ReadInt(); // inner sequence
		uint32 InnerLength = Reader.ReadInt();
		uint32 BeginPosition = Reader.GetOffset();
// 		if (ProcessMessage(Reader.GetBytes(), TLObject())) // change
// 			Reader.SetOffset(BeginPosition + InnerLength);
	}
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
