#pragma once 
#include "MTProtoPlainSender.h"

class Session;
class TCPTransport;

class MTProtoSender : MTProtoPlainSender
{
	Session * MTSession;
public:
	MTProtoSender(TCPTransport * Transport, Session * NewSession);
	int32 Send(unsigned char * Data, int32 Size); // TLObject
	TArray<unsigned char> Receive(int32 Size);
	bool SendPacket();
};