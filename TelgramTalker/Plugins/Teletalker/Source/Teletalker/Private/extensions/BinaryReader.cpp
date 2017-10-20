#include "extensions/BinaryReader.h"
#include "../../TL/TLObjectBase.h"
#include "../../TL/AllObjects.h"

BinaryReader::BinaryReader(const unsigned char * Data, int32 Size)
{
	if (Data != nullptr && Size > 0)
	{
		Buff.Reserve(Size * 2);
		for(int32 i = 0; i < Size; i++)
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

int32 BinaryReader::ReadBigInt()
{
	int32 result = 0;
	if (Offset < Size)
	{
		unsigned char * bits = (unsigned char *)Buff.GetData();
		/*read little endian*/
		for (int32 n = Offset; n < Offset + 4; n++)
			result = (result << 8) + bits[n];
		Offset += 4;
	}
	return result;
}

int32 BinaryReader::ReadInt()
{
	int32 result = 0;
	if (Offset < Size)
	{
		unsigned char * bits = (unsigned char *) Buff.GetData();
		/*read little endian*/
		for (int32 n = 3 + Offset; n >= 0 + Offset; n--)
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
		for (int32 n = 7 + Offset; n >= 0 + Offset; n--)
			result = (result << 8) + bits[n];
		Offset += 8;
	}
	return result;
}

TArray<unsigned char> BinaryReader::Read(int32 NewSize)
{
	int32 result = 0;
	TArray<unsigned char> Temp;
	if (Offset < this->Size)
	{
		Temp.Reserve(NewSize);
		for (int32 i = Offset; i < NewSize + Offset; i++)
			Temp.Push(Buff[i]);
		Offset += NewSize;
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
	UE_LOG(LogTemp, Warning, TEXT("tgread fisrt byte len %d"), FirstByte)
	if(FirstByte >= 254)
	{
		length = this->ReadByte() + (this->ReadByte() << 8) + (this->ReadByte() << 16);
		padding = length % 4;
		UE_LOG(LogTemp, Warning, TEXT("tgread bytes len %d"), length);
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
		UE_LOG(LogTemp, Warning, TEXT("tgread padding len %d"), padding);
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
	TArray<uint8> String = TGReadBytes();
	String.Add(0);
	FString Result = FString(UTF8_TO_TCHAR(String.GetData()));
	return Result;
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

