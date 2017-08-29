#pragma once
#include "Engine.h"

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
	bool WriteInt(int Value);
	bool WriteBigInt(unsigned int Value);
	bool WriteLong(long long Value);
	bool Write(const unsigned char * Value, int Size);
	bool WriteBig(const unsigned char * Value, int Size);
	void Flush();
	bool TGWriteBytes(const unsigned char * Value, int32 Size);
	TArray<unsigned char> GetBytes(bool Flush = true);
	TArray<unsigned char> GetBigBytes(bool Flush = true);
	int32 GetWrittenBytesCount();

	void ReverseByteOrder(char * Value, int Size);
};
