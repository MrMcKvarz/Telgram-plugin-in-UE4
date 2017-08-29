#pragma once 
//#include "Engine.h"

class TCPTransport;

static class Authenticator
{
public:
	static TArray<unsigned char> Authenticate(TCPTransport * Transport);
};