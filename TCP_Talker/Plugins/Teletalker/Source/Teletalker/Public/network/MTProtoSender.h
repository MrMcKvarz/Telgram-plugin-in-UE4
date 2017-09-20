#pragma once 
#include "MTProtoPlainSender.h"

class Session;
class TCPTransport;

class MTProtoSender : MTProtoPlainSender
{
	Session * MTSession;
	TSet<unsigned long long> ServerMessagesNeedAcknowledges;
	TSet<unsigned long long> ClientMessagesNeedAcknowledges;
public:
	MTProtoSender(TCPTransport * Transport, Session * NewSession);
	int32 Send(unsigned char * Data, int32 Size); // TLObject
	TArray<unsigned char> Receive();


	TArray<unsigned char> CalculateMessageKey(unsigned char * Data, int32 Size);

	bool Connect();
private:
	void SendAcknowledges();
	int32 SendPacket(unsigned char * Data, int32 Size);
	bool ProcessMessage(TArray<unsigned char> Message);
	TArray<unsigned char> DecodeMessage(TArray<unsigned char> Message);
	bool HandleBadServerSalt(TArray<unsigned char> Message);
	bool HandleMessageContainer(TArray<unsigned char> Message);
};