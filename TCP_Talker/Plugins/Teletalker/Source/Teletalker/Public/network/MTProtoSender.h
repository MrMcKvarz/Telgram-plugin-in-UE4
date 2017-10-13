#pragma once 
#include "MTProtoPlainSender.h"


class Session;
class TCPTransport;
class TLBaseObject;
class TelegramClient;

class TELETALKER_API MTProtoSender : public MTProtoPlainSender
{
	Session * MTSession;
	TelegramClient *Client;
	TArray<uint64> ServerMessagesNeedAcknowledges;
	TArray<TLBaseObject*> ClientMessagesNeedAcknowledges;
public:
	MTProtoSender(Session * NewSession);
	int32 Send(TLBaseObject &Message); // TLObject
	TArray<uint8> Receive(TLBaseObject &Message);

	TArray<uint8> CalculateMessageKey(uint8 * Data, int32 Size);

	bool Connect();

	bool IsConnected();

	void SetClient(TelegramClient *Client);

	bool UpdateTransport(Session * NewSession);
private:
	bool Connected;
	void SendAcknowledges();
	int32 SendPacket(TLBaseObject &Message);
	bool ProcessMessage(TArray<uint8> Message, TLBaseObject &Request);
	TArray<uint8> DecodeMessage(TArray<uint8> Message);
	bool HandleBadServerSalt(TArray<uint8> Message, TLBaseObject &Request);
	bool HandleMessageContainer(TArray<uint8> Message, TLBaseObject &Request);
	bool HandleBadMessageNotify(TArray<uint8> Message, TLBaseObject &Request);
	bool HandleRPCResult(TArray<uint8> Message, TLBaseObject &Request);
	bool HandleGzipPacked(TArray<uint8> Message, TLBaseObject &Request);
	bool HandlePong(TArray<uint8> Message, TLBaseObject &Request);
	bool HandleRPCError(FString Message, TLBaseObject &Request);
};