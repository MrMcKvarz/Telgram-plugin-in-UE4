#include "AuthKey.h"
#include "extensions//BinaryReader.h"
#include "extensions//BinaryWriter.h"
#define UI UI_ST
THIRD_PARTY_INCLUDES_START
#include "AllowWindowsPlatformTypes.h"
#include "openssl/sha.h"
#include "HideWindowsPlatformTypes.h"
THIRD_PARTY_INCLUDES_END
#undef UI
AuthKey::AuthKey(unsigned char * Data)
{
	Key.Reserve(DEFAULT_KEY_SIZE);
	SetKey(Data);
}

AuthKey::AuthKey()
{
	Key.Reserve(DEFAULT_KEY_SIZE);
	Key.Empty();
	AuxHash = 0;
	KeyID = 0;
}

TArray<unsigned char> AuthKey::CalculateNewNonceHash(TArray<unsigned char> Nonce, int32 Number)
{
	BinaryWriter Writer;
	Writer.Write(Nonce.GetData(), Nonce.Num());
	Writer.WriteByte((unsigned char *)(&Number));
	Writer.WriteLong(AuxHash);

	unsigned char NewNonceSHA[20];
	SHA1(Writer.GetBytes().GetData(), Writer.GetWrittenBytesCount(), NewNonceSHA);

	TArray<unsigned char> NewNonceHash1;
	NewNonceHash1.Reserve(20);
	for (int32 i = 4; i < 20; i++)
		NewNonceHash1.Add(NewNonceSHA[i]);
	return NewNonceHash1;
}

TArray<unsigned char> AuthKey::GetKey()
{
	return Key;
}

unsigned long long AuthKey::GetAuxHash()
{
	return AuxHash;
}

unsigned long long AuthKey::GetKeyID()
{
	return KeyID;
}

void AuthKey::SetKey(unsigned char * Data)
{
	for (int32 i = 0; i < DEFAULT_KEY_SIZE; i++)
		Key.Add(Data[i]);

	unsigned char KeySHA[20];
	SHA1((unsigned char *)Key.GetData(), DEFAULT_KEY_SIZE, KeySHA);
	BinaryReader Reader(KeySHA, 20);
	AuxHash = Reader.ReadLong();
	Reader.Read(4);
	KeyID = Reader.ReadLong();
}

AuthKey& AuthKey::operator=(const AuthKey& Copy)
{
	this->Key = Copy.Key;
	this->AuxHash = Copy.AuxHash;
	this->KeyID = Copy.KeyID;
	return *this;
}
