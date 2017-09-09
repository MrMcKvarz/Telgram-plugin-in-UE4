#pragma once
#include "Engine.h"

using namespace std;

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
	FString AppVersion;
	FString LangCode;
	FString SystemLangCode;
	FString LangPack;

	FString UserID;

public:
	Session(FString SessionUserdID);
	bool Save();
	bool Load();
	bool Delete();

	FString GetServerAddress() { return ServerAddress; }
	void SetServerAddress(FString NewServerAddress) { if (!NewServerAddress.IsEmpty()) ServerAddress = NewServerAddress; }

	TArray<unsigned char> GetAuthKey() { return AuthKey; }
	void SetAuthKey(TArray<unsigned char> NewAuthKey) { AuthKey = NewAuthKey; }

	int32 GetPort() { return Port; }
	void SetPort(int32 NewPort) { if (NewPort > 0) Port = NewPort; }

	unsigned long long GetSalt() { return Salt; }
	void SetSalt(unsigned long long NewSalt) { if (NewSalt > 0) Salt = NewSalt; }

	unsigned long long GetID() { return ID; }
	void SetID(unsigned long long NewID) { if (NewID > 0) ID = NewID; }

	FString GetDeviceModel() { return DeviceModel; }
	void SetDeviceModel(FString NewDeviceModel) { DeviceModel = NewDeviceModel; }

	FString GetSystemVersion() { return SystemVersion; }
	void SetSystemVersion(FString NewSystemVersion) { SystemVersion = NewSystemVersion; }

	FString GetAppVersion() { return AppVersion; }
	void SetAppVersion(FString NewAppVersion) { AppVersion = NewAppVersion; }

	FString GetLangCode() { return LangCode; }
	void SetLangCode(FString NewLangCode) { LangCode = NewLangCode; }

	FString GetSystemLangCode() { return SystemLangCode; }
	void SetSystemLangCode(FString NewSystemLangCode) { SystemLangCode = NewSystemLangCode; }

	FString GetLangPack() { return LangPack; }
	void SetLangPack(FString NewLangPack) { LangPack = NewLangPack; }

	FString GetUserID() { return UserID; }
	void SetUserID(FString NewUserID) { UserID = NewUserID; }
};