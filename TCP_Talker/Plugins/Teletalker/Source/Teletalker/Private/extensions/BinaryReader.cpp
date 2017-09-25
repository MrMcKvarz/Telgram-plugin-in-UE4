#include "extensions/BinaryReader.h"
#include "../../TL/TLObjectBase.h"
#include "../../TL/AllObjects.h"

BinaryReader::BinaryReader(const unsigned char * Data, int Size)
{
	if (Data != nullptr && Size > 0)
	{
		Buff.Reserve(Size * 2);
		for(int i = 0; i < Size; i++)
			Buff.Push(Data[i]);
	}
	this->Size = Size;
	Offset = 0;
}

BinaryReader::BinaryReader()
{
	Buff.Reserve(2048);
}

BinaryReader::~BinaryReader()
{
	Buff.Empty();
}

unsigned char BinaryReader::ReadByte()
{
	if (Offset < Size)
		return Buff[Offset++];
	return 0;
}

int BinaryReader::ReadInt()
{
	int result = 0;
	if (Offset < Size)
	{
		unsigned char * bits = (unsigned char *) Buff.GetData();
		/*read little endian*/
		for (int n = 3 + Offset; n >= 0 + Offset; n--)
			result = (result << 8) + bits[n];
		Offset += 4;
	}
	return result;
}

signed long long BinaryReader::ReadLong()
{
	long long result = 0;
	if (Offset < Size)
	{
		unsigned char * bits = (unsigned char *)Buff.GetData();
		/*read little endian*/
		for (int n = 7 + Offset; n >= 0 + Offset; n--)
			result = (result << 8) + bits[n];
		Offset += 8;
	}
	return result;
}

TArray<unsigned char> BinaryReader::Read(int Size)
{
	int result = 0;
	TArray<unsigned char> Temp;
	if (Offset < this->Size)
	{
		Temp.Reserve(Size);
		for (int i = Offset; i < Size + Offset; i++)
			Temp.Push(Buff[i]);
		Offset += Size;
		return Temp;
	}
	return Temp;
}

void BinaryReader::Close()
{

}

int32 BinaryReader::GetOffset()
{
	return Offset;
}

uint32 BinaryReader::GetOffset() const
{
	return Offset;
}

void BinaryReader::SetOffset(uint32 Value)
{
	Offset = Value;
}

TArray<unsigned char> BinaryReader::GetBytes(bool Flush /*= true*/)
{
	return Buff;
}

TArray<unsigned char> BinaryReader::TGReadBytes()
{
	int32 length;
	int32 padding;
	TArray<uint8> data;
	unsigned char FirstByte = this->ReadByte();
	if(FirstByte >= 254)
	{
		length = this->ReadByte() + (this->ReadByte() << 8) + (this->ReadByte() << 16) - 1;
		padding = length % 4;

	}
	else
	{
		length = FirstByte;
		padding = (length + 1) % 4;
	}
	data = this->Read(length);
	if(padding > 0)
	{
		padding = 4 - padding;
		this->Read(padding);
	}
	return data;
}

TLBaseObject* BinaryReader::TGReadObject()
{
	uint32 ConstructorID = ReadInt();
	TLBaseObject * Result = TLObjects()[ConstructorID];
	if (Result == nullptr) 
		return nullptr;
	else
		Result->OnResponce(*this);

	return Result;
}


FString BinaryReader::TGReadString()
{
// 	auto UTF8Value = TCHAR_TO_UTF8(*Value);
// 	return TGWriteBytes((unsigned char *)UTF8Value, Value.Len());

	auto String = TGReadBytes();
	FString Result;
	for (auto Letter : String)
		Result.AppendChar(Letter);
	return Result;// .Reverse();
}

bool BinaryReader::ReadBool()
{
	uint32 BoolCode = ReadInt();
	bool Result = false;
	if (BoolCode == 0x997275b5)
		Result = true;
	if (BoolCode == 0xbc799737)
		Result = false;
	return Result;
}

double BinaryReader::ReadDouble()
{
	return 0.;
}

FDateTime BinaryReader::TGReadDate()
{
	uint32 DateValue = ReadInt();
	return FDateTime::FromUnixTimestamp(DateValue);
}

TBigInt<128> BinaryReader::Read128Int()
{
	TBigInt<128> Test;
	return Test;
}

TBigInt<256> BinaryReader::Read256Int()
{
	TBigInt<256> Test;
	return Test;
}

// TArray<char> BinaryReader::GetBytes(bool Flush /*= true*/)
// {
// 	return void;
// }

