#pragma once
#include "Engine.h"

class BinaryReader;
class BinaryWriter;

class TLObject
{
	bool Sent = false;
	unsigned long long RequestMessageID;
	int32 Sequence = 0;
	bool Dirty = false; // idk what this should do yet
	bool ConfirmReceived = false;
	FDateTime SentTime;

	int32 ConstructorID = 0;
	bool ContentRetated = false;
	bool Responded = false;
public:
	void OnSendSuccess();
	void OnConfirm();
	bool NeedResend();

	virtual void OnSend(BinaryWriter Writer);

	virtual void OnResponse(BinaryReader Reader);

};