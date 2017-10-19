#pragma once
#include "Engine.h"
#include "../../TL/TLObjectBase.h"

enum class ErrorSeeOther303
{
	FileMigrate,
	PhoneMigrate,
	NetworkMigrate,
	UserMigrate
};

enum class BadRequest400 
{
	
};

enum class Unauthorized401
{
	AuthKeyUnregistered,
	AuthKeyInvalid,
	UserDeactivated,
	SessionRevoked,
	SessionExpired,
	ActiveUsersRequired,
	AuthKeyPermEmpty
};

enum class NetworkingError
{
	NotFound404,
	FloodWait420,
	Internal500
};

class MTProtoSender;

class TELETALKER_API Exception 
{
	FString Error;
	int32 ErrorCode;
	MTProtoSender * Sender;
	TLBaseObject * Request;
	void CreateException(FString NewError, int32 NewErrorCode);
	bool HandeMigrate(FString ErrorMessage);
	bool HandleAuthKeyUnregistered();
public:
	Exception(MTProtoSender * NewSender, TLBaseObject * Request);

	bool HandleException(FString NewError, int32 NewErrorCode);

};
