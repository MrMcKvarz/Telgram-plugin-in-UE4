#include "BinaryWriter.h"
#include <algorithm> 
BinaryWriter::BinaryWriter()
{
	Buff.Reserve(DefaultSize * 4);
	WrittenCount = 0;
}
BinaryWriter::~BinaryWriter()
{
	Buff.Empty();
}
bool BinaryWriter::WriteByte(const unsigned char * Value)
{
	Buff.Push(*Value);
	WrittenCount++;
	return true;
}

bool BinaryWriter::WriteInt(int Value)
{
	unsigned char * CValue = (unsigned char *)(&Value);
	for (int i = 0; i < sizeof(Value); i++)
	{
		Buff.Push(CValue[i]);
	}
	WrittenCount += 4;
	return true;
}

bool BinaryWriter::WriteBigInt(unsigned int Value)
{
	unsigned char * CValue = (unsigned char *)(&Value);
	//if (CValue == nullptr) return false;
	for (int i = 3; i >= 0; i--)
	{
		Buff.Push(CValue[i]);
	}
	WrittenCount += 4;
	return true;
}

bool BinaryWriter::WriteLong(long long Value)
{
	unsigned char * CValue = (unsigned char *)(&Value);
	//ReverseByteOrder(CValue, sizeof(Value));
	for (int i = 0; i < sizeof(Value); i++)
	{
		Buff.Push(CValue[i]);
	}
	WrittenCount += 8;
	return true;
}

bool BinaryWriter::Write(const unsigned char * Value, int Size)
{
	if (Value == nullptr || Size <= 0) return false;
	for (int i = 0; i < Size; i++)
	{
		Buff.Push(Value[i]);
	}
	WrittenCount += Size;
	return true;
}

bool BinaryWriter::WriteBig(const unsigned char * Value, int Size)
{
	if (Value == nullptr || Size <= 0) return false;
	for (int i = Size - 1; i >= 0 ; i--)
	{
		Buff.Push(Value[i]);
	}
	WrittenCount += Size;
	return true;
}

void BinaryWriter::Flush()
{
	Buff.Empty();
}


bool BinaryWriter::TGWriteBytes(const unsigned char * Value, int32 Size)
{ 
	/*We write data in little endianess if size < 254 and big endianess otherwise*/
	if (Value == nullptr || Size < 0) return false;
	int32 padding;
	if (Size < 254)
	{
		/*Writing mtproto string: first byte - length, Size bytes data, and some bytes of padding so that overall length is divisible by 4 */
		padding = (Size + 1) % 4;
		if (padding != 0)
			padding = 4 - padding;
		int32 length = Size;
		if (!WriteByte((unsigned char *)(&length))) return false;
		if (!WriteBig(Value, Size)) return false;
	}
	else
	{
		/*Writing mtproto string: first four bytes - length, Size bytes data, and some bytes of padding so that overall length is divisible by 4 */
		padding = Size % 4;
		if (padding != 0)
			padding = 4 - padding;
		int32 NewSize = 254;
		if (!WriteByte((unsigned char *)(&NewSize))) return false;
		int32 SecondBitSize = Size % 256;
		if (!WriteByte((unsigned char *)(&SecondBitSize))) return false;
		int32 ThirdBitSize = (Size >> 8) % 256;
		if (!WriteByte((unsigned char *)(&ThirdBitSize))) return false;
		int32 FourthBitSize = (Size >> 16) % 256;
		if (!WriteByte((unsigned char *)(&FourthBitSize))) return false;
		//WriteBig(Value, Size);
		if (!Write(Value, Size)) return false;
	}
	const unsigned char bytespadding[] = ("\0\0\0\0");
	if (!Write(bytespadding, padding)) return false;
	return true;
}

TArray<unsigned char> BinaryWriter::GetBytes(bool Flush /*= true*/)
{
	return Buff;
}

TArray<unsigned char> BinaryWriter::GetBigBytes(bool Flush /*= true*/)
{
	TArray<unsigned char> Temp;
	
	for (int i = 0; i < Buff.Num(); i++)
		Temp.Add(Buff[Buff.Num() - i - 1]);
	return Temp;
}

int32 BinaryWriter::GetWrittenBytesCount()
{
	return WrittenCount;
} 


void BinaryWriter::ReverseByteOrder(char * Value, int Size)
{
	char* start = Value;
	char *istart = start, *iend = istart + Size;
	std::reverse(istart, iend);
}
