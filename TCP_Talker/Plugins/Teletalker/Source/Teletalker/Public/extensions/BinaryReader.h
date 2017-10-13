#pragma once
#include "Engine.h"

#include "BigInt.h"

class TLBaseObject;

class TELETALKER_API BinaryReader
{
	TArray<unsigned char> Buff;
	int32 Size;
	int32 Offset;
public:
	BinaryReader();
	BinaryReader(const unsigned char * Data, int32 Size);
	~BinaryReader();

	unsigned char ReadByte();
	int32 ReadBigInt();
	/*Reads numbers in little endian*/
	int32 ReadInt();
	signed long long ReadLong();
	TArray<unsigned char> Read(int32 Size);
	void Close();
	int32 GetOffset();
	TArray<unsigned char> GetBytes(bool Flush = true);
	TArray<unsigned char> TGReadBytes();
	TLBaseObject * TGReadObject();
	FString TGReadString();
	bool ReadBool();
	double ReadDouble();
	FDateTime TGReadDate();
	TBigInt<128> Read128Int();
	TBigInt<256> Read256Int();
	uint32 GetOffset() const;
	void SetOffset(uint32 Value);
};