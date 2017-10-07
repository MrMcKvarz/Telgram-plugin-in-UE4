#include "network/Authenticator.h"
#include "network/MTProtoPlainSender.h"
#include "extensions/BinaryReader.h"
#include "extensions/BinaryWriter.h"
#include <bitset>
#include "crypto/Crypto.h"
#include "crypto/AuthKey.h"

#include "Networking.h"

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


int64 GetInt64Big(uint8 * Value)
{
	if (Value == nullptr) return 0;
	int64 result = 0;

	for (int n = 0; n < 8; n++)
		result = (result << 8) + Value[n];

	return result;
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

AuthKey Authenticator::Authenticate(FString IP, int32 Port)
{
	MTProtoPlainSender Sender(IP, Port);//Transport is already connected

	//Send scheme https://core.telegram.org/mtproto/samples-auth_key

	/*Request for (p,q) Authorization*/
	Sender.Connect();
	BinaryWriter PQWriter;
	BinaryWriter HashWriter;
	PQWriter.WriteInt(0x60469778);
	uint8 Buff[16];
	int32 Random = RAND_bytes(Buff, 16);
	PQWriter.Write(Buff, 16);
	HashWriter.Write(Buff, 16);

	TArray<uint8> bytes = PQWriter.GetBytes();
	int32 bytessent = Sender.Send(bytes.GetData(), PQWriter.GetWrittenBytesCount());
	
	/*Response for (p,q) Authorization*/
	BinaryReader PQReader((uint8 *)Sender.Receive(84).GetData(), 64);
	int32 PQConst = PQReader.ReadInt();
	if (PQConst != 0x05162463)
		UE_LOG(LogTemp, Error, TEXT("Invalid PQ Constructor"));

	TArray<uint8> Nonce = PQReader.Read(16);

	if (Nonce != HashWriter.GetBytes())
		UE_LOG(LogTemp, Error, TEXT("Invalid nonce"));

	TArray<uint8> ServerNonce = PQReader.Read(16);
	TArray<uint8> PQBytes = PQReader.TGReadBytes();
	int64 PQ = GetInt64Big(PQBytes.GetData());
	int32 VectConst = PQReader.ReadInt();
	if (VectConst != 0x1cb5c415)
		UE_LOG(LogTemp, Error, TEXT("Invalid vector constructor"));
	int32 FingerPrintsCount = PQReader.ReadInt();
	TArray<uint8> Fingerprint = PQReader.Read(8);

	/*Generate encrypted data*/
	BinaryWriter DataWriter;
	DataWriter.WriteInt(0x83c95aec);
	DataWriter.TGWriteBytes(PQBytes.GetData(), PQBytes.Num());

	int64 Factor;
	int64 Factor2;
	Crypto::Factorize(&PQ, &Factor, &Factor2);

 	int32 Min = FMath::Min(Factor, Factor2);
 	int32 Max = FMath::Max(Factor, Factor2);
	DataWriter.TGWriteBytes((uint8 *)&Min, 4);
	DataWriter.TGWriteBytes((uint8 *)&Max, 4);
	DataWriter.Write(Nonce.GetData(), Nonce.Num());
	DataWriter.Write(ServerNonce.GetData(), ServerNonce.Num());

	uint8 RandBytes[32];
	RAND_bytes(RandBytes, 32);
	DataWriter.Write(RandBytes, 32);
	TArray<uint8> NewNonce;
	NewNonce.Reserve(32);
	for (int32 i = 0; i < 32; i++)
		NewNonce.Add(RandBytes[i]);

	/*Prepare data for RSA encrypt*/
	uint8 SHAResult[20];
	SHA1((uint8 *)DataWriter.GetBytes().GetData(), DataWriter.GetWrittenBytesCount(), SHAResult);
	BinaryWriter EncDataWriter;
	EncDataWriter.Write(SHAResult, 20);
	EncDataWriter.Write(DataWriter.GetBytes().GetData(), DataWriter.GetWrittenBytesCount());
	uint8 Trash[512];
	int32 TrashSize = 255 - EncDataWriter.GetWrittenBytesCount();
	RAND_bytes(Trash, TrashSize);
	EncDataWriter.Write(Trash, TrashSize);

	/*Since RSA_public_encrypt failed to produce necessary data, with use bare rsa algorithm */
	RSA* rsaPubKey = RSA_new();
	BIGNUM * modulus = BN_new();
	BIGNUM * power = BN_new();
	BIGNUM * message = BN_new();
	BIGNUM * encrypted = BN_new();
	/*Telegram public key in hex form*/
	char * TelegramPublicKey = "C150023E2F70DB7985DED064759CFECF0AF328E69A41DAF4D6F01B538135A6F91F8F8B2A0EC9BA9720CE352EFCF6C5680FFC424BD634864902DE0B4BD6D49F4E580230E3AE97D95C8B19442B3C0A10D8F5633FECEDD6926A7F6DAB0DDB7D457F9EA81B8465FCD6FFFEED114011DF91C059CAEDAF97625F6C96ECC74725556934EF781D866B34F011FCE4D835A090196E9A5F0E4449AF7EB697DDB9076494CA5F81104A305B6DD27665722C46B60E5DF680FB16B210607EF217652E60236C255F6A28315F4083A96791D7214BF64C1DF4FD0DB1944FB26A2A57031B32EEE64AD15A8BA68885CDE74A5BFC920F6ABF59BA5C75506373E7130F9042DA922179251F";
	char * PublicExponent = "10001";
	BN_CTX * BNCTX = BN_CTX_new();

	BN_bin2bn(EncDataWriter.GetBytes().GetData(), 255, message);
	BN_hex2bn(&power, PublicExponent);
	BN_hex2bn(&modulus, TelegramPublicKey);
	rsaPubKey->n = modulus;
	rsaPubKey->e = power;
	/*RSA is basically r=a^p % m, where a - our message, p - public exponent, m - public key, and r - resulting encrypted message*/
	int32 IsRSAValid = BN_mod_exp(encrypted, message, power, modulus, BNCTX);

	//Request to start Diffie-Hellman key exchange
	BinaryWriter DHWriter;
	uint8 CipherData[256];

	DHWriter.WriteInt(0xd712e4be);
 	DHWriter.Write(Nonce.GetData(), Nonce.Num());

 	DHWriter.Write(ServerNonce.GetData(), ServerNonce.Num());

	DHWriter.TGWriteBytes((uint8 *)&Min, 4);

	DHWriter.TGWriteBytes((uint8 *)&Max, 4);
	DHWriter.Write(Fingerprint.GetData(), 8);

	BN_bn2bin(encrypted, CipherData);
	DHWriter.TGWriteBytes(CipherData, 256);

	int32 bytessentdh = Sender.Send(DHWriter.GetBytes().GetData(), DHWriter.GetWrittenBytesCount());

	BinaryReader DHReader(Sender.Receive(664).GetData(), 632);

	uint32 ServerDHParams = DHReader.ReadInt();
	if(ServerDHParams != 0xd0e8075c)
		UE_LOG(LogTemp, Error, TEXT("DH params failed"));
	if(Nonce != DHReader.Read(16))
		UE_LOG(LogTemp, Error, TEXT("Nonce failed"));
	if(ServerNonce != DHReader.Read(16))
		UE_LOG(LogTemp, Error, TEXT("ServeNonce failed"));

	TArray<uint8> Key, IV;
	uint8 Answer[1024];
	GenerateKeyDataFromNonce(NewNonce, ServerNonce,/*out*/ Key, /*out*/ IV);

	AES_KEY DecryptAESKey;
	/*WARNING: unlike other OpenSSL functions, this returns zero on success and a negative number on error */
	AES_set_decrypt_key(Key.GetData(), 256, &DecryptAESKey);

	TArray<uint8> EncryptedAnswer = DHReader.TGReadBytes();
	TArray<uint8> IV2;
	IV2 = IV;
	const size_t encslength = ((EncryptedAnswer.Num() + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
	AES_ige_encrypt(EncryptedAnswer.GetData(), Answer, encslength, &DecryptAESKey, IV.GetData(), AES_DECRYPT);

	BinaryReader DHInnerDataReader(Answer, 584);

	DHInnerDataReader.Read(20); // hash sum
	uint32 DHInnerConstructor = DHInnerDataReader.ReadInt();
	if(DHInnerConstructor != 0xb5890dba)
 		UE_LOG(LogTemp, Error, TEXT("DH inner constructor error"));
	if (Nonce != DHInnerDataReader.Read(16))
		UE_LOG(LogTemp, Error, TEXT("Nonce failed"));
	if (ServerNonce != DHInnerDataReader.Read(16))
		UE_LOG(LogTemp, Error, TEXT("ServeNonce failed"));

	int32 G = DHInnerDataReader.ReadInt();
	auto DHPrime = DHInnerDataReader.TGReadBytes();
	auto GA = DHInnerDataReader.TGReadBytes();
	int32 ServerTime = DHInnerDataReader.ReadInt();

	BIGNUM * b = BN_new();
	uint8 BHash[256];
	RAND_bytes(BHash, 256);
	BN_bin2bn(BHash, 256, b);

	BIGNUM * dh_prime = BN_new();
	BN_bin2bn(DHPrime.GetData(), DHPrime.Num(), dh_prime);

	BIGNUM * ga = BN_new();
	BN_bin2bn(GA.GetData(), GA.Num(), ga);

	BIGNUM * g = BN_new();
	BN_bin2bn((uint8 *)(&G), 1, g);
	BIGNUM * gb = BN_new();
	BIGNUM * gab = BN_new();

	BN_CTX * BNCTXGBDH = BN_CTX_new();
	BN_CTX * BNCTXGABDH = BN_CTX_new();

	int32 IsGBDH = BN_mod_exp(gb, g, b, dh_prime, BNCTXGBDH);
	int32 IsGABDH = BN_mod_exp(gab, ga, b, dh_prime, BNCTXGABDH); //calculating auth key
	uint8 gbBytes[256];
	if(!BN_bn2bin(gb, gbBytes))
		UE_LOG(LogTemp, Error, TEXT("Failed BIGNUM conversion"));
	uint8 gabBytes[256];
	if (!BN_bn2bin(gab, gabBytes))
	if((IsGBDH && IsGABDH))
		UE_LOG(LogTemp, Error, TEXT("Computation Ok"));

	/*Client DH inner data generation*/
	BinaryWriter DHInnerDataWriter;
	DHInnerDataWriter.WriteInt(0x6643b654);
	DHInnerDataWriter.Write(Nonce.GetData(), Nonce.Num());
	DHInnerDataWriter.Write(ServerNonce.GetData(), ServerNonce.Num());
	DHInnerDataWriter.WriteLong(0); // TODO Retry id 
	DHInnerDataWriter.TGWriteBytes(gbBytes, 256);

	BinaryWriter DHInnerEncDataWriter;
	uint8 SHADHInner[20];
	SHA1(DHInnerDataWriter.GetBytes().GetData(), DHInnerDataWriter.GetWrittenBytesCount(), SHADHInner);
	DHInnerEncDataWriter.Write(SHADHInner, 20);
	DHInnerEncDataWriter.Write(DHInnerDataWriter.GetBytes().GetData(), DHInnerDataWriter.GetWrittenBytesCount());
	int32 DHEncDataPadding;
	if(DHInnerEncDataWriter.GetWrittenBytesCount() % 16 != 0)
	{
		DHEncDataPadding = 16 - (DHInnerEncDataWriter.GetWrittenBytesCount() % 16);
		DHInnerEncDataWriter.Write(gbBytes, DHEncDataPadding); // We using SHADHInner, but all we need just to write padding bytes
	}

	AES_KEY EncryptAESKey;
	if ((AES_set_encrypt_key(Key.GetData(), 256, &EncryptAESKey) != 0))
		UE_LOG(LogTemp, Error, TEXT("Error setting encrypt key"));
	uint8 DH_AESEncrypted[336];
	if (DHInnerEncDataWriter.GetWrittenBytesCount() % 16 != 0)
		UE_LOG(LogTemp, Error, TEXT("AES encrypt data size not divisible by 16"));

	const size_t InputLength = DHInnerEncDataWriter.GetWrittenBytesCount();
	AES_ige_encrypt((uint8 *)DHInnerEncDataWriter.GetBytes().GetData(), DH_AESEncrypted, InputLength, &EncryptAESKey, IV2.GetData(), AES_ENCRYPT);

	BinaryWriter DHInnerRequestWriter;
	DHInnerRequestWriter.WriteInt(0xf5045f1f);
	DHInnerRequestWriter.Write(Nonce.GetData(), Nonce.Num());
	DHInnerRequestWriter.Write(ServerNonce.GetData(), ServerNonce.Num());
	DHInnerRequestWriter.TGWriteBytes(DH_AESEncrypted, 336);
 
	bytessent = Sender.Send(DHInnerRequestWriter.GetBytes().GetData(), DHInnerRequestWriter.GetWrittenBytesCount());

	BinaryReader DHCompleteReader(Sender.Receive(84).GetData(), 52);
	int32 CompleteDHConst = DHCompleteReader.ReadInt();
	if (CompleteDHConst != 0x3bcbf734)
		UE_LOG(LogTemp, Error, TEXT("Wrong DH complete constructor"));
	if (Nonce != DHCompleteReader.Read(16))
		UE_LOG(LogTemp, Error, TEXT("Nonce failed"));
	if (ServerNonce != DHCompleteReader.Read(16))
		UE_LOG(LogTemp, Error, TEXT("ServeNonce failed"));
	TArray<uint8> NewNonceHash1 = DHCompleteReader.Read(16);

	AuthKey NewKey(gabBytes);

	TArray<uint8> NewNonceHashCheck = NewKey.CalculateNewNonceHash(NewNonce, 1);
	if(NewNonceHash1 != NewNonceHashCheck)
		UE_LOG(LogTemp, Error, TEXT("NewNonce hash check failed"));

	return NewKey;
}

void Authenticator::GenerateKeyDataFromNonce(TArray<uint8> NewNonce, TArray<uint8> ServerNonce, TArray<uint8> &Key, TArray<uint8> &IV)
{
	TArray<uint8> NewNServer;
	NewNServer += NewNonce;
	NewNServer += ServerNonce;

	TArray<uint8> ServerNNew;
	ServerNNew += ServerNonce;
	ServerNNew += NewNonce;

	TArray<uint8> NewNNew;
	NewNNew += NewNonce;
	NewNNew += NewNonce;

	uint8 Hash1[20], Hash2[20], Hash3[20];
	SHA1((uint8 *)NewNServer.GetData(), NewNServer.Num(), Hash1);
	SHA1((uint8 *)ServerNNew.GetData(), ServerNNew.Num(), Hash2);
	SHA1((uint8 *)NewNNew.GetData(), NewNNew.Num(), Hash3);

	for (int32 i = 0; i < 20; i++)
		Key.Add(Hash1[i]);
	for (int32 i = 0; i < 12; i++)
		Key.Add(Hash2[i]);

	for (int32 i = 12; i < 20; i++)
		IV.Add(Hash2[i]);
	for (int32 i = 0; i < 20; i++)
		IV.Add(Hash3[i]);
	for (int32 i = 0; i < 4; i++)
		IV.Add(NewNonce[i]);
	return;
}

