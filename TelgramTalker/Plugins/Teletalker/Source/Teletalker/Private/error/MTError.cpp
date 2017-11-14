#include "MTError.h"
#include "MTProtoSender.h"
#include "Session.h"
#include "TelegramClient.h"
#include "Regex.h"
//#include "../../TL/Types/COMMON/Public/DcOption.h"


MTError::MTError(MTProtoSender * NewSender, TLBaseObject * NewRequest)
{
	Sender = NewSender;
	Request = NewRequest;
}

bool MTError::HandleException(FString NewError, int32 NewErrorCode)
{
	CreateException(NewError, NewErrorCode);
	switch (ErrorCode)
	{
	case 303:
	{
		if (Error.Contains("PHONE_MIGRATE_") || Error.Contains("NETWORK_MIGRATE_") || Error.Contains("FILE_MIGRATE_") || Error.Contains("USER_MIGRATE_"))
		{
			return HandeMigrate(Error);
		}

	}
	break;
	case (401, 400, 403, 404, 420):
		return NotifyRequest();
	break;
	default:
	{
		return NotifyRequest();
	}
		break;
	}
	return true;
}

bool MTError::Reconnect(int32 DataCenterToMigrate)
{
	Session * MTSession = Sender->GetSession();
	if (!MTSession || !Request) return false;
	for (auto DC : MTSession->DCOptions)
		if (DC.GetId() == DataCenterToMigrate && !DC.GetIpv6())
		{
			MTSession->SetServerAddress(DC.GetIpAddress());
			MTSession->GetAuthKey().ClearAuthKey();
			MTSession->SetPort(DC.GetPort());
			MTSession->SetCurrentDC(DataCenterToMigrate);
			MTSession->Save();
			Sender->GetClient()->Reconnect();
			return true;
		}
	return false;
}

void MTError::CreateException(FString NewError, int32 NewErrorCode)
{
	Error = NewError;
	ErrorCode = NewErrorCode;
	UE_LOG(LogTemp, Error, TEXT("Code: %d, Error: %s"), ErrorCode, *Error);
}

bool MTError::HandeMigrate(FString ErrorMessage)
{
	FRegexPattern Pattern(TEXT("(\\d+)"));
	FRegexMatcher Match(Pattern, ErrorMessage);
	int32 DataCenterToMigrate = -1;
	if (Match.FindNext())
	{
		FString DC_ID = Match.GetCaptureGroup(1);
		DataCenterToMigrate = FCString::Atoi(*DC_ID);
	}
	if (Reconnect(DataCenterToMigrate))
		Sender->Send(*Request);

	return true;
}

bool MTError::NotifyRequest()
{
	if (!Request) return false;
	Request->SetLastErrorMessage(Error);
	Request->SetLastErrorCode(ErrorCode);
	return true;
}

