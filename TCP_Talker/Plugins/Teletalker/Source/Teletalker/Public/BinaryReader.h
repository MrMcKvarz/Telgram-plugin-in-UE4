#pragma once
#include "Engine.h"
class BinaryReader
{
	TArray<unsigned char> Buff;
	int Size;
	int Offset;
public:
	BinaryReader(const unsigned char * Data, int Size);
	~BinaryReader();

	unsigned char ReadByte();
	/*Reads numbers in little endian*/
	int ReadInt();
	signed long long ReadLong();
	TArray<unsigned char> Read(int Size);
	void Close();
	TArray<unsigned char> GetBytes(bool Flush = true);
	TArray<unsigned char> TGReadBytes();
};