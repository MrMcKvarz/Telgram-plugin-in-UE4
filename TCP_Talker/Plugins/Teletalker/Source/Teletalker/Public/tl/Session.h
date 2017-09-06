#pragma once
#include "Engine.h"

class Session
{
	FString ServerAddress;
	int32 Port;
	TArray<unsigned char> AuthKey;
	unsigned long long ID;
	int32 Sequence;
	unsigned long long Salt;
	int64 LastMsgID;
	
	FString DeviceModel;
	FString SystemVersion;
	FString AppVerison;
	FString LangCode;
	FString SystemLangCode;
	FString LangPack;

	FString UserID;

public:
	Session(FString SessionUserdID);
	bool Save();
	bool Delete();

	FString GetServerAddress() { return ServerAddress; }
	void SetServerAddress(FString NewServerAddress) { if (!NewServerAddress.IsEmpty()) ServerAddress = NewServerAddress; }

	TArray<unsigned char> GetAuthKey() { return AuthKey; }
	void SetAuthKey(TArray<unsigned char> NewAuthKey) { AuthKey = NewAuthKey; }

	int32 GetPort() { return Port; }
	void SetPort(int32 NewPort) { if (NewPort > 0) Port = NewPort; }
};