#pragma once
#include "Engine.h"

#include "BigInt.h"

class TLBaseObject;

class BinaryReader
{
	TArray<unsigned char> Buff;
	int Size;
	int Offset;
public:
	BinaryReader();
	BinaryReader(const unsigned char * Data, int Size);
	~BinaryReader();

	unsigned char ReadByte();
	/*Reads numbers in little endian*/
	int ReadInt();
	signed long long ReadLong();
	TArray<unsigned char> Read(int Size);
	void Close();
	int32 GetOffset();
	TArray<unsigned char> GetBytes(bool Flush = true);
	TArray<unsigned char> TGReadBytes();
	TLBaseObject * TGReadObject();
	bool TGReadBool();
	FString TGReadString();
	bool ReadBool();
	double ReadDouble();
	FDateTime TGReadDate();
	TBigInt<128> Read128Int();
	TBigInt<256> Read256Int();
	uint32 GetOffset() const;
	void SetOffset(uint32 Value);
};