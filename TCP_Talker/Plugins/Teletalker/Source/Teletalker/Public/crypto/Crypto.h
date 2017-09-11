#pragma once

class Crypto
{
public:
	//static Factorize
	static int64 SmallMultiplier(int64 pq);
	static unsigned long long GCD(unsigned long long a, unsigned long long b);
//	int64 GCD(int64 a, int64 b);
	static void Factorize(long long *pq, long long *p, long long *q);
	//static int64 Factorize(long long pq);
	static int64 GetRandomLong();

	static void CalculateKey(TArray<unsigned char> SharedKey, TArray<unsigned char> MessageKey, TArray<unsigned char> &Key, TArray<unsigned char> &IV, bool isClient);

	TArray<unsigned char> RSAPublicEncrypt(int64 FingerPrint, unsigned char * Data, int32 Size);
};