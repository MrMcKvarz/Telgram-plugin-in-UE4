#pragma once
#include "Engine.h"


class TCPTransport;

class MTProtoPlainSender
{
protected:
	int32 Sequence;
	int32 TimeOffset;
	int64 LastMessageID;
	TCPTransport * Transport;
public:
	MTProtoPlainSender(TCPTransport * Transport);
	bool Connect();
	void Disconnect();
	int32 Send(unsigned char * Data, int32 Size);
	TArray<unsigned char> Receive(int32 Size);
	int64 GetNewMessageID();



};