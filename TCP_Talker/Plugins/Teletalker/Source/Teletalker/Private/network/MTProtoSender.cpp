#include "MTProtoSender.h"
#include "network/TCPTransport.h"
#include "Utilities.h"
#define UI UI_ST
#include "tl/Session.h"
#include "openssl/sha.h"
#include "openssl/aes.h"
#undef UI
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "crypto/Crypto.h"
#include "../../TL/AllObjects.h"
#include <zlib.h>
#include "MTError.h"


MTProtoSender::MTProtoSender(TCPTransport * Transport, Session * NewSession)
	: MTProtoPlainSender(Transport)
{
	Connected = false;
	if (NewSession == nullptr)
		MTSession = new Session("MTSession");
	else
		MTSession = NewSession;
}

int32 MTProtoSender::Send(TLBaseObject &Message)
{
	if (Transport == nullptr) return 0;
	SendAcknowledges();
	uint32 BytesSent = SendPacket(Message);
	ClientMessagesNeedAcknowledges.Add(&Message);
	return BytesSent;
}

TArray<uint8 > MTProtoSender::Receive(TLBaseObject &Message)
{
	if (Transport == nullptr) return TArray<uint8 >();
	TArray<uint8 > Received;
	while(!Message.IsConfirmReceived() || !Message.IsResponded())
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
		SendPacket(Acknowledge);
		ServerMessagesNeedAcknowledges.Empty(1);
	}
}

int32 MTProtoSender::SendPacket(TLBaseObject &Message)
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

	TArray<uint8 > MessageKey = CalculateMessageKey(PlainWriter.GetBytes().GetData(), PlainWriter.GetWrittenBytesCount());

	TArray<uint8 > Key, IV;
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

	uint8 CipherText[2048];
	AES_ige_encrypt((uint8 *)PlainWriter.GetBytes().GetData(), CipherText, PlainWriter.GetWrittenBytesCount(), &EncryptAESKey, IV.GetData(), AES_ENCRYPT);

	BinaryWriter CipherWriter;
	CipherWriter.WriteLong(MTSession->GetAuthKey().GetKeyID());
	CipherWriter.Write(MessageKey.GetData(), MessageKey.Num());
	CipherWriter.Write(CipherText, PlainWriter.GetWrittenBytesCount());
	return Transport->Send(CipherWriter.GetBytes().GetData(), CipherWriter.GetWrittenBytesCount());
}

bool MTProtoSender::ProcessMessage(TArray<uint8 > Message, TLBaseObject &Request)
{
	ServerMessagesNeedAcknowledges.Add(MTSession->GetLastMsgID());
	BinaryReader MessageReader(Message.GetData(), Message.Num());
	uint32 Response = MessageReader.ReadInt();

	if (Response == 0xedab447b) // bad server salt
	{
		UE_LOG(LogTemp, Warning, TEXT("Bad server salt"));	
		ServerMessagesNeedAcknowledges.Remove(MTSession->GetLastMsgID());
		return HandleBadServerSalt(Message, Request);
	}
	if (Response == 0xf35c6d01)  // rpc_result, (response of an RPC call, i.e., we sent a request)
	{
		UE_LOG(LogTemp, Warning, TEXT("rpc_result"));
		return HandleRPCResult(Message, Request);
	}
	if (Response == 0x347773c5)  // pong
		UE_LOG(LogTemp, Warning, TEXT("pong"));

	if (Response == 0x73f1f8dc)  // msg_container
	{
		UE_LOG(LogTemp, Warning, TEXT("msg container"));
		return HandleMessageContainer(Message, Request);		
	}
	if (Response == 0x3072cfa1)  // gzip_packed
	{
		UE_LOG(LogTemp, Warning, TEXT("gzip packed"));
		return HandleGzipPacked(Message, Request);
	}
	if (Response == 0xa7eff811)  // bad_msg_notification
	{
		UE_LOG(LogTemp, Warning, TEXT("Bad msg notify"));
		return HandleBadMessageNotify(Message, Request);
	}

	// msgs_ack, it may handle the request we wanted
	if (Response == 0x62d6b459)
	{
		UE_LOG(LogTemp, Warning, TEXT("msg ack"));
		MessageReader.SetOffset(0);
		TLBaseObject * Ack = MessageReader.TGReadObject();
		if (Ack == nullptr) return false;
		else
		{
			COMMON::MsgsAck* MessageAck = reinterpret_cast<COMMON::MsgsAck*>(Ack);
			for (TLBaseObject * ConfirmMessage : ClientMessagesNeedAcknowledges)
			{
				for(uint64 Confirmation : MessageAck->GetMsgIds())
					if (Confirmation == ConfirmMessage->GetRequestMessageID())
						ConfirmMessage->SetConfirmReceived(true);
			}
		}
		return true;
	}

	if (TLObjects().Contains(Response))
	{
		MessageReader.SetOffset(0);
		TLBaseObject *Result = MessageReader.TGReadObject();
		return true;
	}

 	return false;
}

TArray<uint8 > MTProtoSender::DecodeMessage(TArray<uint8> Message)
{
	if(Message.Num() < 8) 
		UE_LOG(LogTemp, Error, TEXT("Packet receive failure"));

	BinaryReader Reader(Message.GetData(), Message.Num());
	unsigned long long RemoteAuthID = Reader.ReadLong();
	if(RemoteAuthID != MTSession->GetAuthKey().GetKeyID())
		UE_LOG(LogTemp, Error, TEXT("Auth id from server is invalid"));
	TArray<uint8 > RemoteMessageKey = Reader.Read(16);

	TArray<uint8 > Key, IV;
	Crypto::CalculateKey(MTSession->GetAuthKey().GetKey(), RemoteMessageKey,/*out*/ Key,/*out*/ IV, false);

	AES_KEY DecryptAESKey;
	if ((AES_set_decrypt_key(Key.GetData(), 256, &DecryptAESKey) != 0))
		UE_LOG(LogTemp, Error, TEXT("Failed creating decrypt key"));

	int32 PlainMessageLength = Reader.GetBytes().Num() - Reader.GetOffset();

	uint8 PlainText[16228];
	AES_ige_encrypt((uint8 *)Reader.Read(PlainMessageLength).GetData(), PlainText, PlainMessageLength, &DecryptAESKey, IV.GetData(), AES_DECRYPT);

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

bool MTProtoSender::HandleBadServerSalt(TArray<uint8> Message, TLBaseObject &Request)
{
	BinaryReader Reader(Message.GetData(), Message.Num());
	int32 Code = Reader.ReadInt();
	unsigned long long BadMessageID = Reader.ReadLong();
	int32 BadSequence =	Reader.ReadInt(); // bad message sequence number
	int32 ErrorCode = Reader.ReadInt(); // error code
	unsigned long long NewSalt = Reader.ReadLong();
 	MTSession->SetSalt(NewSalt);
	if(ClientMessagesNeedAcknowledges.Contains(&Request))
		Send(Request);
	MTSession->Save();
	return true;
}

bool MTProtoSender::HandleMessageContainer(TArray<uint8> Message, TLBaseObject &Request)
{

	BinaryReader Reader(Message.GetData(), Message.Num());
	uint32 Code = Reader.ReadInt();
	uint32 Size = Reader.ReadInt();
	for (uint32 i = 0; i < Size; i++)
	{
		unsigned long long InnerMessageID = Reader.ReadLong();
		Reader.ReadInt(); // inner sequence
		uint32 InnerLength = Reader.ReadInt();
		uint32 BeginPosition = Reader.GetOffset();
		auto ContainedMessage = Reader.Read(InnerLength);
		if (ProcessMessage(ContainedMessage, Request))
			Reader.SetOffset(BeginPosition + InnerLength);
		else
			return false;
	}
	return true;
}

bool MTProtoSender::HandleBadMessageNotify(TArray<uint8> Message, TLBaseObject &Request)
{
// self._logger.debug('Handling bad message notification')
// 	reader.read_int(signed = False)  # code
// 	reader.read_long()  # request_id
// 	reader.read_int()  # request_sequence
// 
// 	error_code = reader.read_int()
// 	error = BadMessageError(error_code)
// 	if error_code in(16, 17) :
// 		# sent msg_id too low or too high(respectively).
// 		# Use the current msg_id to determine the right time offset.
// 		self.session.update_time_offset(correct_msg_id = msg_id)
// 		self.session.save()
// 		self._logger.debug('Read Bad Message error: ' + str(error))
// 		self._logger.debug('Attempting to use the correct time offset.')
// 		return True
// 	else:
// raise error
	BinaryReader Reader(Message.GetData(), Message.Num());
	uint32 Code = Reader.ReadInt();
	uint64 RequestID = Reader.ReadLong();
	Reader.ReadInt();
	uint32 ErrorCode = Reader.ReadInt();
#pragma region Errors
	switch (ErrorCode)
	{
	case 16:
	{
		UE_LOG(LogTemp, Error, TEXT("msg_id too low (most likely, client time is wrong it would be worthwhile to synchronize it using msg_id notifications and re-send the original message with the correct msg_id or wrap it in a container with a new msg_id if the original message had waited too long on the client to be transmitted)."));
		break;
	}
	case 17:
	{
		UE_LOG(LogTemp, Error, TEXT("msg_id too high (similar to the previous case, the client time has to be synchronized, and the message re-sent with the correct msg_id)."));
		break;
	}
	case 18:
	{
		UE_LOG(LogTemp, Error, TEXT("Incorrect two lower order msg_id bits (the server expects client message msg_id to be divisible by 4)."));
		break;
	}
	case 19:
	{
		UE_LOG(LogTemp, Error, TEXT("Container msg_id is the same as msg_id of a previously received message (this must never happen)."));
		break;
	}
	case 20:
	{
		UE_LOG(LogTemp, Error, TEXT("Message too old, and it cannot be verified whether the server has received a message with this msg_id or not."));
		break;
	}
	case 32:
	{
		UE_LOG(LogTemp, Error, TEXT("msg_seqno too low (the server has already received a message with a lower 'msg_id but with either a higher or an equal and odd seqno)."));
		break;
	}
	case 33:
	{
		UE_LOG(LogTemp, Error, TEXT("msg_seqno too high (similarly, there is a message with a higher msg_id but with either a lower or an equal and odd seqno)."));
		break;
	}
	case 34:
	{
		UE_LOG(LogTemp, Error, TEXT("An even msg_seqno expected (irrelevant message), but odd received."));
		break;
	}
	case 35: 	
	{
		UE_LOG(LogTemp, Error, TEXT("Odd msg_seqno expected (relevant message), but even received."));
		break;
	}
	case 48:
	{
		UE_LOG(LogTemp, Error, TEXT("Incorrect server salt (in this case, the bad_server_salt response is received with the correct salt, and the message is to be re-sent with it)."));
		break;
	}
	case 64: 	
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid container."));
		break;
	}
	default:
		break;
	}
#pragma endregion
	return true;
}

bool MTProtoSender::HandleRPCResult(TArray<uint8> Message, TLBaseObject &Request)
{

	BinaryReader Reader(Message.GetData(), Message.Num());
	int32 Code = Reader.ReadInt();
	uint64 RequestID = Reader.ReadLong();
	uint32 InnerCode = Reader.ReadInt();

	for (TLBaseObject * ConfirmMessage : ClientMessagesNeedAcknowledges)
	{
		if (RequestID == ConfirmMessage->GetRequestMessageID())
		{
			ConfirmMessage->SetConfirmReceived(true);
			break;
		}
	}

	if (InnerCode == 0x2144ca19) //RPC Error
	{
		uint32 ErrorLength = Reader.ReadInt();
		FString Error = Reader.TGReadString();
  		ServerMessagesNeedAcknowledges.Add(RequestID);
		SendAcknowledges();
		Request.SetDirty(true);

		HandleRPCError(Error, Request);
			
		return false;

	}

	if (InnerCode == 0x3072cfa1) //GZip packed
	{
		const uint32 CHUNK = 16384;
		TArray<uint8> CompressedData;
		TArray<uint8> DecompressedData;
		CompressedData = Reader.TGReadBytes();
		int32 Result = Utilities::Decompress(CompressedData, DecompressedData);;

		BinaryReader GzipReader(DecompressedData.GetData(), DecompressedData.Num());
		Request.OnResponce(GzipReader);
	}
	else
	{
		Reader.SetOffset(12);
		Request.OnResponce(Reader);
	}

	return true;
}

bool MTProtoSender::HandleGzipPacked(TArray<uint8> Message, TLBaseObject &Request)
{
	BinaryReader Reader(Message.GetData(), Message.Num());
	TArray<uint8> CompressedData = Reader.TGReadBytes();
	TArray<uint8> DecompressedData;
	int32 UnzipResult = Utilities::Decompress(CompressedData, DecompressedData);
	if (UnzipResult < 0) return false;
	return ProcessMessage(DecompressedData, Request);
}

bool MTProtoSender::HandlePong(TArray<uint8> Message, TLBaseObject &Request)
{
	BinaryReader Reader(Message.GetData(), Message.Num());
	uint64 ReceivedMessageID = Reader.ReadLong();
	for (TLBaseObject * ConfirmMessage : ClientMessagesNeedAcknowledges)
	{
		if (ReceivedMessageID == ConfirmMessage->GetRequestMessageID())
			ConfirmMessage->SetConfirmReceived(true);
	}
	return true;
}

bool MTProtoSender::HandleRPCError(FString Message, TLBaseObject &Request)
{
	if (Message == L"AUTH_KEY_UNREGISTERED")
	{
		throw(std::system_error(EDOM, std::generic_category()));
		return false;
	}
	FString PhoneMigrateError("PHONE_MIGRATE");
	if (Message.Contains(PhoneMigrateError))
	{
		int32 DataCenterToMigrate = FCString::Atoi(*Message.Right(PhoneMigrateError.Len()));
		for (auto DC : MTSession->DCOptions)
			if (DC->Getid() == DataCenterToMigrate)
			{
				MTSession->SetServerAddress(DC->GetIpAddress());
				MTSession->SetPort(DC->Getport());
				MTSession->Save();
			}
		return true;
	}
	return false;
}

TArray<uint8 > MTProtoSender::CalculateMessageKey(uint8 * Data, int32 Size)
{
	uint8 SHAResult[20];
	SHA1(Data, Size, SHAResult);
	TArray<uint8 > Temp;
	for (int32 i = 4; i < 20; i++)
		Temp.Add(SHAResult[i]);
	return Temp;
}

bool MTProtoSender::Connect()
{
	if (Transport == nullptr) return false;
	Connected = true;
	return Transport->Connect();
}

bool MTProtoSender::IsConnected()
{
	if (!Transport) return false;
	return Connected;
}
