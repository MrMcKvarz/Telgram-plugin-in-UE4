#pragma once 
#include "MTProtoPlainSender.h"


class Session;
class TCPTransport;
class TLBaseObject;

class MTProtoSender : MTProtoPlainSender
{
	Session * MTSession;
	TArray<unsigned long long> ServerMessagesNeedAcknowledges;
	TArray<TLBaseObject> ClientMessagesNeedAcknowledges;
public:
	MTProtoSender(TCPTransport * Transport, Session * NewSession);
	int32 Send(TLBaseObject &Message); // TLObject
	TArray<unsigned char> Receive(TLBaseObject &Message);


	TArray<unsigned char> CalculateMessageKey(unsigned char * Data, int32 Size);

	bool Connect();
private:
	void SendAcknowledges();
	int32 SendPacket(TLBaseObject &Message);
	bool ProcessMessage(TArray<unsigned char> Message, TLBaseObject &Request);
	TArray<unsigned char> DecodeMessage(TArray<unsigned char> Message);
	bool HandleBadServerSalt(TArray<unsigned char> Message, TLBaseObject &Request);
	bool HandleMessageContainer(TArray<unsigned char> Message);
};