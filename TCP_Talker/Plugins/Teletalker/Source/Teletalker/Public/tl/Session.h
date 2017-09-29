#pragma once
#include "Engine.h"
#include "AuthKey.h"
#include "../../TL/Types/COMMON/Public/DcOption.h"

class Session
{
	FString ServerAddress;
	int32 Port;
	AuthKey SessionAuthKey;
	uint64 ID;
	int32 Sequence;
	uint64 Salt;
	int64 LastMsgID;
	
	FString DeviceModel;
	FString SystemVersion;
	FString AppVersion;
	FString LangCode;
	FString SystemLangCode;
	FString LangPack;

	FString UserID;
	FString SessionFilePath;

public:
	Session(FString SessionUserdID);
	bool Save();
	bool Load();
	bool Delete();
	
	TArray<COMMON::DcOption*> DCOptions;

	/*get/set area*/
	FString GetServerAddress() { return ServerAddress; }
	void SetServerAddress(FString NewServerAddress) { if (!NewServerAddress.IsEmpty()) ServerAddress = NewServerAddress; }

	AuthKey GetAuthKey() { return SessionAuthKey; }
	void SetAuthKey(AuthKey NewAuthKey) { SessionAuthKey = NewAuthKey; }

	int32 GetPort() { return Port; }
	void SetPort(int32 NewPort) { if (NewPort > 0) Port = NewPort; }

	unsigned long long GetID() { return ID; }
	void SetID(unsigned long long NewID) { if (NewID > 0) ID = NewID; }

	int32 GetSequence(bool IsContentRelated) 
	{ 
		if (IsContentRelated)
		{
			uint32 Result = Sequence * 2 + 1;
			Sequence++;
			return Result;
		}
		return Sequence * 2; 
	}
	void SetSequence(int32 NewSequence) { if (NewSequence > 0) Sequence = NewSequence; }

	int64 GetLastMsgID() { return LastMsgID; }
	void SetLastMsgID(int64 NewLastMsgID) { LastMsgID = NewLastMsgID; }

	unsigned long long GetSalt() { return Salt; }
	void SetSalt(unsigned long long NewSalt) { if (NewSalt > 0) Salt = NewSalt; }

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