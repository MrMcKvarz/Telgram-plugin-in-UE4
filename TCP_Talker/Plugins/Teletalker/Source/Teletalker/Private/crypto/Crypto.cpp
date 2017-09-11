#include "crypto/Crypto.h"
#include "Engine.h"
#include <random>
#include "extensions/BinaryReader.h"
#define UI UI_ST
THIRD_PARTY_INCLUDES_START
#include "openssl/rand.h"
#include "openssl/sha.h"
THIRD_PARTY_INCLUDES_END
#undef UI

int64 Crypto::SmallMultiplier(int64 pq)
{
	int64 g = 0;
	for (int32 i = 0; i < 3; i++)
	{
		auto q = (FMath::RandRange(0, 127) & 15) + 17;
		auto x = FMath::RandRange(0, 1000000000) + 1;
		auto y = x;
		auto lim = 1 << (i + 18);
		for (int32 j = 1; j < lim; j++)
		{
			int32 a, b, c;
			a = x;
			b = x;
			c = q;
			while (b != 0)
			{
				if ((b & 1) != 0)
				{
					c += a;
					if (c >= pq)
						c -= pq;
				}
				a += a;
				if (a >= pq)
					a -= pq;
				b >>= 1;
			}

			x = c;
			auto z = y - x ? x < y : x - y;
			g = Crypto::GCD(z, pq);
			if (g != 1)
				break;

			if ((j & (j - 1)) == 0)
				y = x;
		}

		if (g > 1)
			break;
	}

	auto p = pq; // g
	return FMath::Min(p, g);
}

unsigned long long Crypto::GCD(unsigned long long a, unsigned long long b)
{
	/*Greatest common deviser*/
	return b ? GCD(b, a % b) : a;
}

void Crypto::Factorize(long long *pq, long long *p, long long *q)
{
	unsigned long long what = *pq;

	int it = 0;

	unsigned long long g = 0;
	int i;
	for (i = 0; i < 3 || it < 1000; i++) {
		int q1 = ((rand() & 15) + 17) % what;
		unsigned long long x = (long long)rand() % (what - 1) + 1, y = x;
		int lim = 1 << (i + 18);
		int j;
		for (j = 1; j < lim; j++) {
			++it;
			unsigned long long a = x, b = x, c = q1;
			while (b) {
				if (b & 1) {
					c += a;
					if (c >= what) {
						c -= what;
					}
				}
				a += a;
				if (a >= what) {
					a -= what;
				}
				b >>= 1;
			}
			x = c;
			unsigned long long z = x < y ? what + x - y : x - y;
			g = GCD(z, what);
			if (g != 1) {
				break;
			}
			if (!(j & (j - 1))) {
				y = x;
			}
		}
		if (g > 1 && g < what) break;
	}

	unsigned long long p1 = g;
	unsigned long long p2 = what / g;
	if (p1 > p2) {
		unsigned long long t = p1; p1 = p2; p2 = t;
	}

	*p = p1;
	*q = p2;
	return;
}

int64 Crypto::GetRandomLong()
{
	unsigned char Buff[16];
	if (RAND_bytes(Buff, 8))
	{
		BinaryReader Reader(Buff, 8);
		return Reader.ReadLong();
	}
	return 0;
	
}

void Crypto::CalculateKey(TArray<unsigned char> SharedKey, TArray<unsigned char> MessageKey, TArray<unsigned char> &Key, TArray<unsigned char> &IV)
{
	/*https://core.telegram.org/api/end-to-end#serialization-and-encryption-of-outgoing-messages*/
// 		sha1a = sha1(msg_key + shared_key[x:x + 32]).digest()
// 		sha1b = sha1(shared_key[x + 32:x + 48] + msg_key +
// 			shared_key[x + 48:x + 64]).digest()
// 
// 		sha1c = sha1(shared_key[x + 64:x + 96] + msg_key).digest()
// 		sha1d = sha1(msg_key + shared_key[x + 96:x + 128]).digest()
// 
// 		key = sha1a[0:8] + sha1b[8:20] + sha1c[4:16]
// 		iv = sha1a[8:20] + sha1b[0:8] + sha1c[16:20] + sha1d[0:8]

	int32 x = 0; // prob need for non client message
	unsigned char sha1a[20], sha1b[20], sha1c[20], sha1d[20];
	TArray<unsigned char> SHA1A_Array, SHA1B_Array, SHA1C_Array, SHA1D_Array;

	SHA1A_Array += MessageKey;
	for (int32 i = 0; i < 32; i++)
		SHA1A_Array.Add(SharedKey[i]);
	SHA1(SHA1A_Array.GetData(), SHA1A_Array.Num(), sha1a);

	for (int32 i = 32; i < 48; i++)
		SHA1B_Array.Add(SharedKey[i]);
	SHA1B_Array += MessageKey;
	for (int32 i = 48; i < 64; i++)
		SHA1B_Array.Add(SharedKey[i]);
	SHA1(SHA1B_Array.GetData(), SHA1B_Array.Num(), sha1b);

	for (int32 i = 64; i < 96; i++)
		SHA1C_Array.Add(SharedKey[i]);
	SHA1C_Array += MessageKey;
	SHA1(SHA1C_Array.GetData(), SHA1C_Array.Num(), sha1c);

	SHA1D_Array += MessageKey;
	for (int32 i = 96; i < 128; i++)
		SHA1D_Array.Add(SharedKey[i]);
	SHA1(SHA1D_Array.GetData(), SHA1D_Array.Num(), sha1d);

	for (int32 i = 0; i < 8; i++)
		Key.Add(sha1a[i]);
	for (int32 i = 8; i < 20; i++)
		Key.Add(sha1b[i]);
	for (int32 i = 4; i < 16; i++)
		Key.Add(sha1c[i]);

	for (int32 i = 8; i < 20; i++)
		IV.Add(sha1a[i]);
	for (int32 i = 0; i < 8; i++)
		IV.Add(sha1b[i]);
	for (int32 i = 16; i < 20; i++)
		IV.Add(sha1c[i]);
	for (int32 i = 0; i < 8; i++)
		IV.Add(sha1d[i]);
}

// TArray<unsigned char> Crypto::RSAPublicEncrypt(int64 FingerPrint, unsigned char * Data, int32 Size)
// {
// 
// }
