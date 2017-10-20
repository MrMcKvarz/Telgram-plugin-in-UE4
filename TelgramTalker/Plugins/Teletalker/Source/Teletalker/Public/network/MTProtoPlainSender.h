#pragma once
#include "Engine.h"

class TCPTransport;
class Session;

class TELETALKER_API MTProtoPlainSender
{
protected:
	int32 Sequence;
	int32 TimeOffset;
	int64 LastMessageID;
	TSharedPtr<TCPTransport> Transport;
public:
	MTProtoPlainSender(FString IP, int32 Port);
	bool Connect();
	bool Disconnect();
	int32 Send(unsigned char * Data, int32 Size);
	TArray<unsigned char> Receive(int32 Size);
	int64 GetNewMessageID();



};