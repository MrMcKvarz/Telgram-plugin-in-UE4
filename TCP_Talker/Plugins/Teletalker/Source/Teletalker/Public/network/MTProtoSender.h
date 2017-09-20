#pragma once 
#include "MTProtoPlainSender.h"


class Session;
class TCPTransport;
class TLObject;

class MTProtoSender : MTProtoPlainSender
{
	Session * MTSession;
	TArray<unsigned long long> ServerMessagesNeedAcknowledges;
	TArray<TLObject> ClientMessagesNeedAcknowledges;
public:
	MTProtoSender(TCPTransport * Transport, Session * NewSession);
	int32 Send(TLObject &Message); // TLObject
	TArray<unsigned char> Receive(TLObject &Message);


	TArray<unsigned char> CalculateMessageKey(unsigned char * Data, int32 Size);

	bool Connect();
private:
	void SendAcknowledges();
	int32 SendPacket(TLObject &Message);
	bool ProcessMessage(TArray<unsigned char> Message, TLObject &Request);
	TArray<unsigned char> DecodeMessage(TArray<unsigned char> Message);
	bool HandleBadServerSalt(TArray<unsigned char> Message, TLObject &Request);
	bool HandleMessageContainer(TArray<unsigned char> Message);
};