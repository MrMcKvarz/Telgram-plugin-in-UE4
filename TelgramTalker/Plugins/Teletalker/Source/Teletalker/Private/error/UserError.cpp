#include "UserError.h"

// enum class EMTProtoErrors
// {
// 	/*400*/
// 	PhoneNumberInvalid,
// 
// 	/*401*/
// 	AuthKeyUnregistered,
// 	AuthKeyInvalid,
// 	UserDeactivated,
// 	SessionRevoked,
// 	SessionExpired,
// 	ActiveUsersRequired,
// 	AuthKeyPermEmpty,
// 	/**/
// 	Forbidden,
// 	NotFound,
// 	FloodWait,
// 	Internal
// };


bool UserError::DefineError()
{
	if (ErrorCode == 0 && ErrorDescription.IsEmpty())
		Error = EMTProtoErrors::RequestOK;
	switch (ErrorCode)
	{
	case -1:
	{
		Error = EMTProtoErrors::NotConnected;
		return true;
	}
	case 400:
	{
		if (ErrorDescription == "PHONE_NUMBER_INVALID")
		{
			Error = EMTProtoErrors::PhoneNumberInvalid;
			return true;
		}
		if (ErrorDescription == "PHONE_CODE_EMPTY")
		{
			Error = EMTProtoErrors::PhoneCodeEmpty;
			return true;
		}
		if (ErrorDescription == "PHONE_CODE_INVALID")
		{
			Error = EMTProtoErrors::PhodeCodeInvalid;
			return true;
		}
		if (ErrorDescription == "PHONE_CODE_EXPIRED")
		{
			Error = EMTProtoErrors::PhoneCodeExpired;
			return true;
		}
	}
	break;
	case 401:
	{

		if (ErrorDescription == "AUTH_KEY_UNREGISTERED")
		{
			Error = EMTProtoErrors::AuthKeyUnregistered;
			return true;
		}
		if (ErrorDescription == "AUTH_KEY_INVALID")
		{
			Error = EMTProtoErrors::AuthKeyInvalid
				;
			return true;
		}
		if (ErrorDescription == "USER_DEACTIVATED")
		{
			Error = EMTProtoErrors::UserDeactivated;
			return true;
		}
		if (ErrorDescription == "SESSION_REVOKED")
		{
			Error = EMTProtoErrors::SessionRevoked;
			return true;
		}
		if (ErrorDescription == "SESSION_EXPIRED")
		{
			Error = EMTProtoErrors::SessionExpired;
			return true;
		}
		if (ErrorDescription == "ACTIVE_USER_REQUIRED")
		{
			Error = EMTProtoErrors::ActiveUsersRequired;
			return true;
		}
		if (ErrorDescription == "AUTH_KEY_PERM_EMPTY")
		{
			Error = EMTProtoErrors::AuthKeyPermEmpty;
			return true;
		}
	}
	break;

	default:
	{
		if (ErrorDescription == "FORBIDDEN")
		{
			Error = EMTProtoErrors::Forbidden;
			return true;
		}
		if (ErrorDescription == "NOT_FOUND")
		{
			Error = EMTProtoErrors::NotFound;
			return true;
		}
		if (ErrorDescription == "INTERNAL")
		{
			Error = EMTProtoErrors::Internal;
			return true;
		}
		if (ErrorDescription.Contains("FLOOD_WAIT"))
		{
			Error = EMTProtoErrors::FloodWait;
			return true;
		}
	}
		break;
	}
	return false;
}

UserError::UserError(FString NewErrorDescription, int32 NewErrorCode)
{
	ErrorDescription = NewErrorDescription;
	ErrorCode = NewErrorCode;
	DefineError();
}

UserError::UserError(int32 ErrorCode)
{
	this->ErrorCode = ErrorCode;
	DefineError();
}

