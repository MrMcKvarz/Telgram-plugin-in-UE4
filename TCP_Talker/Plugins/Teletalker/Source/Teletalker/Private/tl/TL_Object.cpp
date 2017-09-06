#include "tl/TL_Object.h"

void TLObject::OnSendSuccess()
{
	SentTime = FDateTime::Now();
	Sent = true;
}

void TLObject::OnConfirm()
{
	ConfirmReceived = true;
}

bool TLObject::NeedResend()
{
	return (Dirty || (ContentRetated && !ConfirmReceived && FDateTime::Now().GetSecond() - SentTime.GetSecond() > (FDateTime::Now().GetSecond() + 3)));
}
