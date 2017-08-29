#include "TCPClient.h"
#include "SharedPointer.h"
#include "Sockets.h"

TCPClient::TCPClient()
{
	Connected = false;
	BytesSent = 0;
	Socket = nullptr;
	RecreateSocket();
}

bool TCPClient::Connect(FIPv4Address IP, int32 Port, int32 Timeout /*= 5*/)
{
	if (Socket == nullptr) return false;
	auto Address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	Address->SetIp(IP.Value);
	Address->SetPort(Port);

	Connected = Socket->Connect(*Address);
	return Connected;
}

void TCPClient::Close()
{

}

int32 TCPClient::Write(unsigned char * Data, int32 Size)
{
	if (Size < 0 || Data == nullptr) return false;
	bool IsSent = Socket->Send((uint8*)Data, Size, BytesSent);
	if(IsSent)
		return BytesSent;
	return -1;
}

TArray<unsigned char> TCPClient::Read(int32 Size, int32 Timeout /*= 5*/)
{
	int32 BytesRead = -1;
	bool Receive = Socket->Recv(Data, Size, BytesRead);
	if (Receive)
	{
		TArray<unsigned char> Temp;
		for (int i = 0; i < Size; i++)
			Temp.Push(Data[i]);
		return Temp;
	}
	return TArray<unsigned char>();
}

bool TCPClient::IsConnected()
{
	
	return Connected;
}

void TCPClient::RecreateSocket()
{
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("TelegramSocket"), false);
}

