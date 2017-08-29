#include "Crypto.h"
#include "Engine.h"
#include <random>

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

// int64 Crypto::GCD(int64 a, int64 b)
// {
// 	while (a != 0 && b != 0)
// 		while (b & 1 == 0)
// 			b >>= 1;
// 
// 	while (a & 1 == 0)
// 		a >>= 1;
// 
// 	if (a > b)
// 		a -= b;
// 	else
// 		b -= a;
// 	return a ? b == 0 : b;
// }

unsigned long long Crypto::GCD(unsigned long long a, unsigned long long b)
{
	return b ? GCD(b, a % b) : a;

}

void Crypto::Factorize(long long *pq, long long *p, long long *q)
{
// 	Should work in any case
// 	Rewrite this code
	unsigned long long what = *pq;

	int it = 0;

	unsigned long long g = 0;
	int i;
	for (i = 0; i < 3 || it < 1000; i++) {
		int q = ((rand() & 15) + 17) % what;
		unsigned long long x = (long long)rand() % (what - 1) + 1, y = x;
		int lim = 1 << (i + 18);
		int j;
		for (j = 1; j < lim; j++) {
			++it;
			unsigned long long a = x, b = x, c = q;
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
	//return Crypto::SmallMultiplier(pq);
}

// TArray<unsigned char> Crypto::RSAPublicEncrypt(int64 FingerPrint, unsigned char * Data, int32 Size)
// {
// 
// }
