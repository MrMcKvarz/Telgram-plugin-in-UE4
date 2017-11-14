#pragma once
#include "Engine.h"
#include "../../TL/TLObjectBase.h"


class MTProtoSender;

class TELETALKER_API MTError 
{
	FString Error;
	int32 ErrorCode;
	MTProtoSender * Sender;
	TLBaseObject * Request;
	void CreateException(FString NewError, int32 NewErrorCode);
	bool HandeMigrate(FString ErrorMessage);
	bool NotifyRequest();
public:
	MTError(MTProtoSender * NewSender, TLBaseObject * Request);

	bool HandleException(FString NewError, int32 NewErrorCode);
	bool Reconnect(int32 DC);

};
