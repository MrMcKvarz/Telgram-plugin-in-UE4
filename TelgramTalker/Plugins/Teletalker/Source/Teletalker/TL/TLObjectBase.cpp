#include "TLObjectBase.h"

TLBaseObject::TLBaseObject()
{
	Sent = false;
	RequestMessageID = 0;
	Dirty = false;
	ConfirmReceived = false;
	 _ContentRelated = false;
	_Responded = false;
	LastErrorCode = 0;
	LastErrorMessage = "";
}

void TLBaseObject::OnSendSuccess()
{
	this->SendTime = FDateTime::Now();
	this->Sent = true;
}

void TLBaseObject::OnConfirm()
{
	this->ConfirmReceived = true;
}

bool TLBaseObject::NeedResend()
{
	return Dirty || (_ContentRelated && !ConfirmReceived && ((FDateTime::Now() - SendTime) > FApp::GetDeltaTime()));
}

TLBaseObject::~TLBaseObject()
{
}

bool TLBaseObject::operator==(const TLBaseObject &Compartment) const
{
	if (
		this->_ConstructorID == Compartment._ConstructorID &&
		this->_ContentRelated == Compartment._ContentRelated &&
		this->_Responded == Compartment._Responded &&
		this->Sent == Compartment.Sent &&
		this->RequestMessageID == Compartment.RequestMessageID &&
		this->Dirty == Compartment.Dirty &&
		this->SendTime == Compartment.SendTime &&
		this->ConfirmReceived == Compartment.ConfirmReceived
		)
		return true;
	else
		return false;
}
