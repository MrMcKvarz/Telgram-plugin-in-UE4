#include "TCPTransport.h"
#include "BinaryWriter.h"
#include "BinaryReader.h"
#include <chrono>

TCPTransport::TCPTransport(FIPv4Address IP, int32 Port, int32 Timeout /*= 5*/)
{
	this->IP = IP;
	this->Port = Port;
	this->Client = new TCPClient();
	this->Timeout = Timeout;
	SendCounter = 0;
}

TCPTransport::TCPTransport()
{
	IP.Value = 0;
	Port = 0;
	Client = new TCPClient();
	Timeout = 5;
	SendCounter = 0;
}

bool TCPTransport::Connect()
{
	if (Client == nullptr) return false;
	bool IsConnected = Client->Connect(IP, Port, Timeout);
	return IsConnected;	
}

bool TCPTransport::IsConnected()
{
	return Client->IsConnected();
}

int32 TCPTransport::Send(unsigned char * Packet, int32 Size)
{
	if (!Client->IsConnected()) return false;
	BinaryWriter Writer;
	Writer.WriteInt(Size + 12);
	Writer.WriteInt(SendCounter++);
	Writer.Write(Packet, Size);
	uint32 Hash = GetCrc(Writer.GetBytes().GetData(), Writer.GetWrittenBytesCount());
	Writer.WriteInt(Hash);
	int32 BytesSent = Client->Write(Writer.GetBytes().GetData(), Writer.GetWrittenBytesCount());
	return BytesSent;
}

TArray<unsigned char> TCPTransport::Receive()
{
	auto PacketLengthBytes = Client->Read(4);
	int32 PacketLength = BinaryReader(PacketLengthBytes.GetData(), 4).ReadInt();

 	auto SendCounterBytes = Client->Read(4);
	int32 SendCounter = BinaryReader(SendCounterBytes.GetData(), 4).ReadInt();

	//debug reguion
// 	auto AuthKeyBytes = Client->Read(8);
// 	int64 AuthKey = BinaryReader(AuthKeyBytes.GetData(), 8).ReadLong();
// 
// 	auto MessageIDBytes = Client->Read(8);
// 	int64 MessageID = BinaryReader(MessageIDBytes.GetData(), 8).ReadLong();
// 
// 	auto LengthBytes = Client->Read(4);
// 	int32 Length = BinaryReader(LengthBytes.GetData(), 4).ReadInt();
// 
// 	auto PQConstructorBytes = Client->Read(4);
// 	auto PQConstructor = BinaryReader(PQConstructorBytes.GetData(), 4).ReadInt();
// 
// 	Client->Read(16); //my nonce
// 	Client->Read(16);//server nonce 
// 
// 	auto PQBytes = Client->Read(12);
// 	auto PQ = BinaryReader(PQBytes.GetData(), 12).TGReadBytes();
// 
// 	auto VectorBytes = Client->Read(4);
// 	auto Vector = BinaryReader(VectorBytes.GetData(), 4).ReadInt();
// 
// 	Client->Read(4);
// 	Client->Read(8);
	auto Packet = Client->Read(PacketLength - 12);
// 	if (SendCounter == 1)
// 	{
//  		int32 resp = BinaryReader((unsigned char *)Packet.GetData(), 4).ReadInt();
// 		auto wtf = 1 - 1;
// 
// 	}
	auto HashBytes = Client->Read(4);
	int32 Hash = BinaryReader(HashBytes.GetData(), 4).ReadInt();
// 
	BinaryWriter Writer;
	Writer.WriteInt(PacketLength);
	Writer.WriteInt(SendCounter);
	Writer.Write(Packet.GetData(), Packet.Num());
	uint32 CRC = GetCrc(Writer.GetBytes().GetData(), Writer.GetWrittenBytesCount());
	//if(Hash != CRC) // this should do smth 
		//return TArray<char>();
	return Packet;
	
}

void TCPTransport::Close()
{

}

void TCPTransport::CancelReceive()
{

}

uint32 TCPTransport::GetCrc(const void * Data, int32 Size)
{
	FCrc::Init();
	return FCrc::MemCrc32(Data, Size);
}

// long long TCPTransport::GetNewMessageID()
// {

// }
