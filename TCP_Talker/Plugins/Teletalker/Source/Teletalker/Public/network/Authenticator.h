#pragma once 

class TCPTransport;
class AuthKey;

static class Authenticator
{
public:
	static AuthKey Authenticate(TCPTransport * Transport);
	static void GenerateKeyDataFromNonce(TArray<unsigned char> Nonce, TArray<unsigned char> ServerNonce, TArray<unsigned char> &Key, TArray<unsigned char> &IV);
};