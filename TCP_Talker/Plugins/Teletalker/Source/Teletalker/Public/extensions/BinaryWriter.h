#pragma once
#include "Engine.h"

#include "BigInt.h"

class TLBaseObject;

class BinaryWriter
{
	const int32 DefaultSize = 2048;
	TArray<unsigned char> Buff;
	int WrittenCount;
public:
	BinaryWriter();
	~BinaryWriter();

	bool WriteByte(const unsigned char * Value);
	/*Writes numbers in little endian*/
	bool WriteInt(int32 Value);
	bool WriteBigInt(int32 Value);
	bool WriteLong(long long Value);
	bool Write(const unsigned char * Value, int32 Size);
	bool WriteBig(const unsigned char * Value, int32 Size);
	void Flush();
	bool TGWriteBytes(const unsigned char * Value, int32 Size);
	bool TGWriteString(FString Value);
	TArray<unsigned char> GetBytes(bool Flush = true);
	TArray<unsigned char> GetBigBytes(bool Flush = true);
	int32 GetWrittenBytesCount();
	bool WriteBool(bool Value);
	bool WriteDouble(double Value);
	bool TGWriteDate(FDateTime Value);
	bool Write128Int(TBigInt<128> Value);
	bool Write256Int(TBigInt<256> Value);
	bool TGWriteObject(TLBaseObject* Value);

	void ReverseByteOrder(char * Value, int32 Size);
};
