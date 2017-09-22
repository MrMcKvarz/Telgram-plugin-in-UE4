#pragma once 
#include "Engine.h"

class Session;
class TLBaseObject;

class TelegramClient
{
	Session * ClientSession;
	int32 API_ID;
	FString API_Hash;
public:
	TelegramClient(FString SessionName, int32 API_id, FString API_hash);
	bool Connect();
	bool Invoke(TLBaseObject &Request);
};