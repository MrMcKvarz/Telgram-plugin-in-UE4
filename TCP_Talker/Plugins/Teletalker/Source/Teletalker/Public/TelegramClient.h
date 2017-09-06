#pragma once 
#include "Engine.h"

class Session;

class TelegramClient
{
	Session * ClientSession;
	int32 API_ID;
	FString API_Hash;
public:
	TelegramClient(FString SessionName, int32 API_id, FString API_hash);
	bool Connect(FString AuthKey = "");
};