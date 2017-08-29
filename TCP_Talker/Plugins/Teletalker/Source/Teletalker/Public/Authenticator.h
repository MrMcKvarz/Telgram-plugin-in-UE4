#pragma once 
//#include "Engine.h"

class TCPTransport;

static class Authenticator
{
public:
	static TArray<unsigned char> Authenticate(TCPTransport * Transport);
	static void GenerateKeyDataFromNonce(TArray<unsigned char> Nonce, TArray<unsigned char> ServerNonce, TArray<unsigned char> Key, TArray<unsigned char> IV);
};