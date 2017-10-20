#include "MTProtoPlainSender.h"
#include "network/TCPTransport.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "Session.h"
#include <chrono>
#include <thread>

MTProtoPlainSender::MTProtoPlainSender(FString IP, int32 Port)
{
	Sequence = 0;
	TimeOffset = 0;
	LastMessageID = 0;

	FIPv4Address TelegramServer;
	FIPv4Address::Parse(IP, TelegramServer);

	Transport = MakeShareable(new TCPTransport(TelegramServer, Port));
}

bool MTProtoPlainSender::Connect()
{
	if (!Transport.IsValid()) return false;
	return Transport->Connect();	
}

bool MTProtoPlainSender::Disconnect()
{
	return Transport->Close();
}

int32 MTProtoPlainSender::Send(unsigned char * Data, int32 Size)
{
	if (!Transport.IsValid()) return 0;
	BinaryWriter Writer;
	Writer.WriteLong(0); //auth key id = 0 since we sending plain text message
	Writer.WriteLong(GetNewMessageID()); //long
	Writer.WriteInt(Size);
	Writer.Write(Data, Size);

	auto Packet = Writer.GetBytes();
	
	return Transport->Send(Packet.GetData(), Writer.GetWrittenBytesCount());
}

TArray<unsigned char> MTProtoPlainSender::Receive(int32 Size)
{
	if (!Transport.IsValid()) return TArray<unsigned char>();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	BinaryReader Reader(Transport->Receive().GetData(), Size);
	int64 auth = Reader.ReadLong(); // auth_key_id
	int64 msgid = Reader.ReadLong(); // msg_id
	int32 MessageLength = Reader.ReadInt();
	TArray<unsigned char> Response = Reader.Read(MessageLength);

	return Response;
}

int64 MTProtoPlainSender::GetNewMessageID()
{
	auto nano = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
	auto sec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());

	double nanoseconds = nano.count() - (sec.count() * 1e+9);
	long long new_msg_id = ((sec.count() << 32) | int32(nanoseconds * 2));

	if (LastMessageID >= new_msg_id)
		new_msg_id = LastMessageID + 4;
	LastMessageID = new_msg_id;

	return new_msg_id;
}

