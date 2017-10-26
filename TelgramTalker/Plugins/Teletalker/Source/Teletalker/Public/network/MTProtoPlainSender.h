#pragma once
#include "Engine.h"

class TCPTransport;
class Session;

class TELETALKER_API MTProtoPlainSender
{
protected:
	int32 Sequence;
	int32 TimeOffset;
	uint64 LastMessageID;
	TSharedPtr<TCPTransport> Transport;
public:
	MTProtoPlainSender(FString IP, int32 Port);
	bool Connect();
	bool Disconnect();
	int32 Send(unsigned char * Data, int32 Size);
	TArray<unsigned char> Receive(int32 Size);
	uint64 GetNewMessageID();

	void SetTimeOffset(uint64 NewTimeOffset) { TimeOffset = NewTimeOffset; }
	uint64 GetTimeOffset() const { return TimeOffset; }



};