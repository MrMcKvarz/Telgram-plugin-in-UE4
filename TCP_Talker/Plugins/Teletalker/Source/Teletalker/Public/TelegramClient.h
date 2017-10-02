#pragma once 
#include "Engine.h"


class Session;
class TLBaseObject;
class TCPTransport;


class TelegramClient
{
	Session * ClientSession;
	int32 API_ID;
	FString API_Hash;

	TCPTransport * Transport;
	TSharedPtr<MTProtoSender> Sender;
	bool bAuthorized;
public:
	TelegramClient(FString SessionName, int32 API_id, FString API_hash);
	~TelegramClient();
	bool Connect();
	bool Authorize();
	bool Invoke(TLBaseObject &Request);
	void Reconnect();
	
};
