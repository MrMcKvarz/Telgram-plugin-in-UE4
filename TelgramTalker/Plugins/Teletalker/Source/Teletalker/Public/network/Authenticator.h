#pragma once 

class TCPTransport;
class AuthKey;

class TELETALKER_API Authenticator
{

public:
	static int32 TimeOffset;

	static AuthKey Authenticate(FString IP, int32 Port);
	static void GenerateKeyDataFromNonce(TArray<unsigned char> Nonce, TArray<unsigned char> ServerNonce, TArray<unsigned char> &Key, TArray<unsigned char> &IV);
private:
	Authenticator() {}
	Authenticator(const Authenticator&) {}
	Authenticator(Authenticator&&) {}
	Authenticator& operator=(const Authenticator& rh) { return *this; }
};