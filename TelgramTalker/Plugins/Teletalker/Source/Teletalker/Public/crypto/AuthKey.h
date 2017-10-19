#pragma once
#include "Engine.h"
class TELETALKER_API AuthKey
{
	TArray<unsigned char> Key;
	unsigned long long AuxHash;
	unsigned long long KeyID;
	const int32 DEFAULT_KEY_SIZE = 256;
public:
	AuthKey();
	AuthKey(unsigned char * Data);
	TArray<unsigned char> CalculateNewNonceHash(TArray<unsigned char> Nonce, int32 Number);

	TArray<unsigned char> GetKey();
	unsigned long long GetAuxHash();
	unsigned long long GetKeyID();
	void SetKey(unsigned char * Data);
	void ClearAuthKey();
	AuthKey& operator=(const AuthKey& other);

};