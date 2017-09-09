#include "network/TCPTransport.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"
#include "extensions//TCPClient.h"
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

TCPTransport::~TCPTransport()
{
	Close();
	delete Client;
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
	/*Following TCP protocol*/
	Writer.WriteInt(Size + 12); //message length
	Writer.WriteInt(SendCounter++); //send number
	Writer.Write(Packet, Size); //packet
	uint32 Hash = GetCrc(Writer.GetBytes().GetData(), Writer.GetWrittenBytesCount());
	Writer.WriteInt(Hash); //crc32 hash
	int32 BytesSent = Client->Write(Writer.GetBytes().GetData(), Writer.GetWrittenBytesCount());
	return BytesSent;
}

TArray<unsigned char> TCPTransport::Receive()
{
	auto PacketLengthBytes = Client->Read(4);
	int32 PacketLength = BinaryReader(PacketLengthBytes.GetData(), 4).ReadInt();

 	auto SendCounterBytes = Client->Read(4);
	int32 SendCounter = BinaryReader(SendCounterBytes.GetData(), 4).ReadInt();

	auto Packet = Client->Read(PacketLength - 12);

	auto HashBytes = Client->Read(4);
	uint32 Hash = BinaryReader(HashBytes.GetData(), 4).ReadInt();
 
	BinaryWriter Writer;
	Writer.WriteInt(PacketLength);
	Writer.WriteInt(SendCounter);
	Writer.Write(Packet.GetData(), Packet.Num());
	uint32 CRC = GetCrc(Writer.GetBytes().GetData(), Writer.GetWrittenBytesCount());
	if(Hash != CRC) // this should do smth reasonable
		UE_LOG(LogTemp, Error, TEXT("Hash tcp error"));
	return Packet;
	
}

void TCPTransport::Close()
{
	Client->Close();
}

void TCPTransport::CancelReceive()
{

}

uint32 TCPTransport::GetCrc(const void * Data, int32 Size)
{
	FCrc::Init();
	return FCrc::MemCrc32(Data, Size);
}
