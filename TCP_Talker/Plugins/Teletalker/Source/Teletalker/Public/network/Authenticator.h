#pragma once 

class TCPTransport;
class AuthKey;

static class TELETALKER_API Authenticator
{
public:
	static AuthKey Authenticate(FString IP, int32 Port);
	static void GenerateKeyDataFromNonce(TArray<unsigned char> Nonce, TArray<unsigned char> ServerNonce, TArray<unsigned char> &Key, TArray<unsigned char> &IV);
};