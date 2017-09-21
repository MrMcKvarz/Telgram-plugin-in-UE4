#pragma once
#pragma warning(disable:4946)
#include "Engine.h"
#include "../Public/extensions/BinaryReader.h"
#include "../Public/extensions/BinaryWriter.h"

// class BinaryWriter;
// class BinaryReader;

class TLBaseObject 
{
public:

	TLBaseObject();
	void OnSendSuccess();
	void OnConfirm();
	bool NeedResend();

// 	virtual void DoDict()
// 	{
// 
// 	}

	virtual void OnSend(BinaryWriter& Writer)
	{

	}

	virtual void OnResponce(BinaryReader& Reader)
	{

	}

protected:
	uint32 _ConstructorID;
	bool _ContentRelated;
	bool _Responded;

private:
	bool Sent;
	int64 RequestMessageID;
	bool Dirty;
	FDateTime SendTime;
	bool ConfirmReceived;
public:
	bool IsContentRelated(){ return _ContentRelated; }
	void SetContentRelated(bool Value) { _ContentRelated = Value; }

	bool IsResponded(){ return _Responded; }
	void SetResponded(bool Value) { _Responded = Value; }

	bool IsSent() { return Sent; }
	void SetSent(bool Value) { Sent = Value; }

	int64 GetRequestMessageID() { return RequestMessageID; }
	void SetRequestMessageID(int64 Value) { RequestMessageID = Value; }

	bool IsDirty() { return Dirty; }
	void SetDirty(bool Value) { Dirty = Value; }

	FDateTime GetSendTime() { return SendTime; }
	void SetSendTimee(FDateTime Value) { SendTime = Value; }

	bool IsConfirmReceived() { return ConfirmReceived; }
	void SetConfirmReceived(bool Value) { ConfirmReceived = Value; }

	bool operator==(const TLBaseObject &Compartment) const;

};

