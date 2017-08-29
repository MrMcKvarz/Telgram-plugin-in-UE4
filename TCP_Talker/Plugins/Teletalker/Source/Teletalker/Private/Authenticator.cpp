#include "Authenticator.h"
#include "MTProtoPlainSender.h"
#include "BinaryReader.h"
#include "BinaryWriter.h"
#include <bitset>
#include "Crypto.h"

#include "Networking.h"

#include <gsl/gsl_byte>
#include <gsl/span>
#include <thread>
#include <chrono>


#define UI UI_ST
THIRD_PARTY_INCLUDES_START
#include "AllowWindowsPlatformTypes.h"
#include "ThirdParty/OpenSSL/1.0.2g/include/Win64/VS2015/openssl/rsa.h"
#include "ThirdParty/OpenSSL/1.0.2g/include/Win64/VS2015/openssl/sha.h"
#include "ThirdParty/OpenSSL/1.0.2g/include/Win64/VS2015/openssl/rand.h"
#include "ThirdParty/OpenSSL/1.0.2g/include/Win64/VS2015/openssl/err.h"
#include "ThirdParty/OpenSSL/1.0.2g/include/Win64/VS2015/openssl/aes.h"
#include "ThirdParty/OpenSSL/1.0.2g/include/Win64/VS2015/openssl/pem.h"
#include "ThirdParty/OpenSSL/1.0.2g/include/Win64/VS2015/openssl/bn.h"
#include "HideWindowsPlatformTypes.h"
#include "BigInt.h"


#include "IPv4Address.h"
#include "SocketSubsystem.h"
#include "Sockets.h"
THIRD_PARTY_INCLUDES_END
#undef UI

union Byte
{
	unsigned char byte;

	struct
	{
		bool bit1 : 1;
		bool bit2 : 1;
		bool bit3 : 1;
		bool bit4 : 1;
		bool bit5 : 1;
		bool bit6 : 1;
		bool bit7 : 1;
		bool bit8 : 1;
	};
};


int64 GetInt64Big(unsigned char * Value)
{
	if (Value == nullptr) return 0;
	long long result = 0;

	for (int n = 0; n < 8; n++)
		result = (result << 8) + Value[n];

	return result;
}

unsigned char reverse(unsigned char b) {
	//b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	//b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	return b;
}


RSA* loadPUBLICKeyFromString(const char* publicKeyStr)
{
	// A BIO is an I/O abstraction (Byte I/O?)

	// BIO_new_mem_buf: Create a read-only bio buf with data
	// in string passed. -1 means string is null terminated,
	// so BIO_new_mem_buf can find the dataLen itself.
	// Since BIO_new_mem_buf will be READ ONLY, it's fine that publicKeyStr is const.
	BIO* bio = BIO_new_mem_buf(publicKeyStr, strlen(publicKeyStr)); // -1: assume string is null terminated

	//BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); // NO NL
	//BIO_FLAGS

												// Load the RSA key from the BIO
	RSA* rsaPubKey = PEM_read_bio_RSA_PUBKEY(bio, NULL, NULL, NULL);
	if (!rsaPubKey)
		UE_LOG(LogTemp, Error, TEXT("Invalid rsa public key creation"))

	BIO_free(bio);
	return rsaPubKey;
}




bool Prime(unsigned long a)
{
	unsigned long i1, i2, i3, i4, i5, i6, i7, i8, bound;
	if (a == 0 || a == 1)
		return false;
	if (a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || a == 19 || a == 23 || a == 29)
		return true;
	if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0 || a % 7 == 0 || a % 11 == 0 || a % 13 == 0 || a % 17 == 0 || a % 19 == 0 || a % 23 == 0 || a % 29 == 0)
		return false;
	bound = sqrt((double)a);
	i1 = 31; i2 = 37; i3 = 41; i4 = 43; i5 = 47; i6 = 49; i7 = 53; i8 = 59;
	while (i8 <= bound && a%i1 && a%i2 && a%i3 && a%i4 && a%i5 && a%i6 && a%i7 && a%i8)
	{
		i1 += 30; i2 += 30; i3 += 30; i4 += 30; i5 += 30; i6 += 30; i7 += 30; i8 += 30;
	}
	if (i8 <= bound ||
		i1 <= bound && a % i1 == 0 ||
		i2 <= bound && a % i2 == 0 ||
		i3 <= bound && a % i3 == 0 ||
		i4 <= bound && a % i4 == 0 ||
		i5 <= bound && a % i5 == 0 ||
		i6 <= bound && a % i6 == 0 ||
		i7 <= bound && a % i7 == 0)
		return false;
	return true;
}

TArray<unsigned char> Authenticator::Authenticate(TCPTransport * Transport)
{
	MTProtoPlainSender Sender(Transport);

	//Send scheme https://core.telegram.org/mtproto/samples-auth_key

	/*Request for (p,q) Authorization*/
	BinaryWriter PQWriter;
	BinaryWriter HashWriter;
	PQWriter.WriteInt(0x60469778);
	unsigned char Buff[16];
	int32 Random = RAND_bytes(Buff, 16);
	PQWriter.Write(Buff, 16);
	HashWriter.Write(Buff, 16);

	TArray<unsigned char> bytes = PQWriter.GetBytes();
	int32 bytessent = Sender.Send(bytes.GetData(), PQWriter.GetWrittenBytesCount());
	
	/*Response for (p,q) Authorization*/
	BinaryReader PQReader((unsigned char *)Sender.Receive(84).GetData(), 64);
	int32 PQConst = PQReader.ReadInt();
	if (PQConst != 0x05162463)
		UE_LOG(LogTemp, Error, TEXT("Invalid PQ Constructor"));

	TArray<unsigned char> Nonce = PQReader.Read(16);

	if (Nonce != HashWriter.GetBytes())
		UE_LOG(LogTemp, Error, TEXT("Invalid nonce"));

	TArray<unsigned char> ServerNonce = PQReader.Read(16);
	TArray<unsigned char> PQBytes = PQReader.TGReadBytes();
	int64 PQ = GetInt64Big(PQBytes.GetData());
	int32 VectConst = PQReader.ReadInt();
	if (VectConst != 0x1cb5c415)
		UE_LOG(LogTemp, Error, TEXT("Invalid vector constructor"));
	int32 FingerPrintsCount = PQReader.ReadInt();
	TArray<unsigned char> Fingerprint = PQReader.Read(8);

	/*Generate encrypted data*/
	BinaryWriter DataWriter;
	DataWriter.WriteInt(0x83c95aec);
	DataWriter.TGWriteBytes(PQBytes.GetData(), PQBytes.Num());

	int64 Factor;
	int64 Factor2;
	Crypto::Factorize(&PQ, &Factor, &Factor2);

 	int32 Min = FMath::Min(Factor, Factor2);
 	int32 Max = FMath::Max(Factor, Factor2);
	DataWriter.TGWriteBytes((unsigned char *)&Min, 4);
	DataWriter.TGWriteBytes((unsigned char *)&Max, 4);
	DataWriter.Write(Nonce.GetData(), Nonce.Num());
	DataWriter.Write(ServerNonce.GetData(), ServerNonce.Num());

	unsigned char NewNonce[32];
	RAND_bytes(NewNonce, 32);
	DataWriter.Write(NewNonce, 32);

	/*Prepare data for RSA encrypt*/
	unsigned char SHAResult[20];
	SHA1((unsigned char *)DataWriter.GetBytes().GetData(), DataWriter.GetWrittenBytesCount(), SHAResult);
	BinaryWriter EncDataWriter;
	EncDataWriter.Write(SHAResult, 20);
	EncDataWriter.Write(DataWriter.GetBytes().GetData(), DataWriter.GetWrittenBytesCount());
	unsigned char Trash[512];
	int32 TrashSize = 255 - EncDataWriter.GetWrittenBytesCount();
	RAND_bytes(Trash, TrashSize);
	EncDataWriter.Write(Trash, TrashSize);

	/*Python rsa encrypt test area*/
// 	FIPv4Address TeServer(127, 0, 0, 1);
// 	const int32 TePort = 27015;
// 
// 	FSocket *Sock = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("PythonEncrypt"), false);
// 
// 	auto Address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
// 	Address->SetIp(TeServer.Value);
// 	Address->SetPort(TePort);
// 
// 	int32 TestReceive = 256;
// 	uint8 CipherData[256];
// 	Sock->Connect(*Address);
// 	Sock->Send((uint8 *)EncDataWriter.GetBytes().GetData(), EncDataWriter.GetBytes().Num(), bytessent);
// 	//Sock->Send((uint8 *)CipherText, 256, bytessent);
// 	std::this_thread::sleep_for(std::chrono::milliseconds(10));
// 
// 	int32 CipherRead;
// 	Sock->Recv(CipherData, TestReceive, CipherRead);
	/*End test area*/

	/*Since RSA_public_encrypt failed to produce necessary data, with use bare rsa algorithm */
	RSA* rsaPubKey = RSA_new();
	BIGNUM * modulus = BN_new();
	BIGNUM * power = BN_new();
	BIGNUM * message = BN_new();
	BIGNUM * encrypted = BN_new();
	/*Modulus of Telegram public key in hex form*/
	char * TelegramPublicModulus = "C150023E2F70DB7985DED064759CFECF0AF328E69A41DAF4D6F01B538135A6F91F8F8B2A0EC9BA9720CE352EFCF6C5680FFC424BD634864902DE0B4BD6D49F4E580230E3AE97D95C8B19442B3C0A10D8F5633FECEDD6926A7F6DAB0DDB7D457F9EA81B8465FCD6FFFEED114011DF91C059CAEDAF97625F6C96ECC74725556934EF781D866B34F011FCE4D835A090196E9A5F0E4449AF7EB697DDB9076494CA5F81104A305B6DD27665722C46B60E5DF680FB16B210607EF217652E60236C255F6A28315F4083A96791D7214BF64C1DF4FD0DB1944FB26A2A57031B32EEE64AD15A8BA68885CDE74A5BFC920F6ABF59BA5C75506373E7130F9042DA922179251F";
	char * PublicExponent = "10001";
	BN_CTX * BNCTX = BN_CTX_new();

	BN_bin2bn(EncDataWriter.GetBytes().GetData(), 255, message);
	BN_hex2bn(&power, PublicExponent);
	BN_hex2bn(&modulus, TelegramPublicModulus);
	rsaPubKey->n = modulus;
	rsaPubKey->e = power;
	/*RSA is basically r=a^p % m, where a - our message, p - public exponent, m - public key, and r - resulting ecnrypted message*/
	int32 IsRSAValid = BN_mod_exp(encrypted, message, power, modulus, BNCTX);

	//Request to start Diffie-Hellman key exchange
	BinaryWriter DHWriter;
	uint8 CipherData[256];

	DHWriter.WriteInt(0xd712e4be);
 	DHWriter.Write(Nonce.GetData(), Nonce.Num());

 	DHWriter.Write(ServerNonce.GetData(), ServerNonce.Num());

	DHWriter.TGWriteBytes((unsigned char *)&Min, 4);

	DHWriter.TGWriteBytes((unsigned char *)&Max, 4);
	DHWriter.Write(Fingerprint.GetData(), 8);

	BN_bn2bin(encrypted, CipherData);
	//DHWriter.TGWriteBytes(CipherText, 256);
	DHWriter.TGWriteBytes(CipherData, 256);// TestReceive);

	int32 bytessentdh = Sender.Send(DHWriter.GetBytes().GetData(), DHWriter.GetWrittenBytesCount());

	BinaryReader DHReader(Sender.Receive(664).GetData(), 632);

	int32 ServerDHParams = DHReader.ReadInt();
	if(ServerDHParams != 0xd0e8075c)
		UE_LOG(LogTemp, Error, TEXT("DH params failed"));
	if(Nonce != DHReader.Read(16))
		UE_LOG(LogTemp, Error, TEXT("Nonce failed"));
	if(ServerNonce != DHReader.Read(16))
		UE_LOG(LogTemp, Error, TEXT("ServeNonce failed"));

	auto EncryptedAnswer = DHReader.TGReadBytes();
	return TArray<unsigned char>();
}

void Authenticator::GenerateKeyDataFromNonce(TArray<unsigned char> Nonce, TArray<unsigned char> ServerNonce, TArray<unsigned char> Key, TArray<unsigned char> IV)
{
	//unsigned char Hash1[20];
	//SHA1((unsigned char *)DataWriter.GetBytes().GetData(), DataWriter.GetWrittenBytesCount(), Hash1);
}

