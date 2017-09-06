#include "MTProtoSender.h"
#include "network/TCPTransport.h"
#define UI UI_ST
#include "tl/Session.h"
#undef UI
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"


MTProtoSender::MTProtoSender(TCPTransport * Transport, Session * NewSession)
	: MTProtoPlainSender(Transport)
{
	if (NewSession == nullptr)
		MTSession = new Session("MTSession");
	else
		MTSession = NewSession;
}

int32 MTProtoSender::Send(unsigned char * Data, int32 Size)
{
	if (Transport == nullptr) return 0;
	BinaryWriter Writer;
	Writer.Write(Data, Size);
	auto Packet = Writer.GetBytes();

	return Transport->Send(Packet.GetData(), Writer.GetWrittenBytesCount());
}

TArray<unsigned char> MTProtoSender::Receive(int32 Size)
{
	return TArray<unsigned char>();
}
