#pragma once

#include "Engine.h"

UENUM(BlueprintType)
enum class EMTProtoErrors : uint8
{
	RequestOK,
	NotConnected,
	/*400*/
	PhoneNumberInvalid,
	PhoneCodeEmpty,
	PhodeCodeInvalid,
	PhoneCodeExpired,

	/*401*/
	AuthKeyUnregistered,
	AuthKeyInvalid,
	UserDeactivated,
	SessionRevoked,
	SessionExpired,
	ActiveUsersRequired,
	AuthKeyPermEmpty,
	/**/
	Forbidden,
	NotFound,
	FloodWait,
	Internal
};

class TELETALKER_API UserError
{

	FString ErrorDescription;
	int32 ErrorCode;
	EMTProtoErrors Error;

	bool DefineError();

public:
	UserError(int32 ErrorCode);
	UserError(FString NewErrorDescription, int32 NewErrorCode);

	FString GetErrorDescription() const { return ErrorDescription; }
	
	int32 GetErrorCode() const { return ErrorCode; }

	EMTProtoErrors GetError() const { return Error; }
};