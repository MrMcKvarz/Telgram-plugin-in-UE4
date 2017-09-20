#include "extensions/BinaryWriter.h"
#include <algorithm> 
#include "../../TL/TLObjectBase.h"
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

bool BinaryWriter::WriteInt(int32 Value)
{
	unsigned char * CValue = (unsigned char *)(&Value);
	for (int32 i = 0; i < sizeof(Value); i++)
	{
		Buff.Push(CValue[i]);
	}
	WrittenCount += 4;
	return true;
}

bool BinaryWriter::WriteBigInt(int32 Value)
{
	unsigned char * CValue = (unsigned char *)(&Value);
	//if (CValue == nullptr) return false;
	for (int32 i = 3; i >= 0; i--)
	{
		Buff.Push(CValue[i]);
	}
	WrittenCount += 4;
	return true;
}

bool BinaryWriter::WriteLong(long long Value)
{
	unsigned char * CValue = (unsigned char *)(&Value);
	for (int32 i = 0; i < sizeof(Value); i++)
	{
		Buff.Push(CValue[i]);
	}
	WrittenCount += 8;
	return true;
}

bool BinaryWriter::Write(const unsigned char * Value, int32 Size)
{
	if (Value == nullptr || Size <= 0) return false;
	for (int32 i = 0; i < Size; i++)
	{
		Buff.Push(Value[i]);
	}
	WrittenCount += Size;
	return true;
}

bool BinaryWriter::WriteBig(const unsigned char * Value, int32 Size)
{
	if (Value == nullptr || Size <= 0) return false;
	for (int32 i = Size - 1; i >= 0 ; i--)
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
		WriteBig(Value, Size);
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

bool BinaryWriter::TGWriteString(FString Value)
{
	auto UTF8Value = TCHAR_TO_UTF8(*Value);
	return TGWriteBytes((unsigned char *)UTF8Value, Value.Len());
}

TArray<unsigned char> BinaryWriter::GetBytes(bool Flush /*= true*/)
{
	return Buff;
}

TArray<unsigned char> BinaryWriter::GetBigBytes(bool Flush /*= true*/)
{
	TArray<unsigned char> Temp;
	/*get reverse byte order from what we store*/
	for (int32 i = 0; i < Buff.Num(); i++)
		Temp.Add(Buff[Buff.Num() - i - 1]);
	return Temp;
}

int32 BinaryWriter::GetWrittenBytesCount()
{
	return WrittenCount;
} 


bool BinaryWriter::WriteBool(bool Value)
{
	return true;
}

bool BinaryWriter::WriteDouble(double Value)
{
	return true;
}

bool BinaryWriter::TGWriteDate(FDateTime Value)
{
	return true;
}

bool BinaryWriter::Write128Int(TBigInt<128> Value)
{
	return true;
}

bool BinaryWriter::Write256Int(TBigInt<256> Value)
{
	return true;
}

bool BinaryWriter::TGWriteObject(TLObjAbstract* Value)
{
	return true;
}

void BinaryWriter::ReverseByteOrder(char * Value, int32 Size)
{
	char* start = Value;
	char *istart = start, *iend = istart + Size;
	std::reverse(istart, iend);
}
