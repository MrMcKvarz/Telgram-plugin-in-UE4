#include "extensions/TCPClient.h"
#include "SharedPointer.h"

TCPClient::TCPClient()
{
	Connected = false;
	BytesSent = 0;
	Socket = nullptr;
	RecreateSocket();
}

TCPClient::~TCPClient()
{
	Close();
	delete Socket;
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

bool TCPClient::Close()
{
	/*Once you invoke this you cannot reconnect*/
	/*This is FSocket issue, it can't handle its own state*/
	/*https://answers.unrealengine.com/questions/451319/4125-fsocketgetconnectionstate-returns-incorrect-v.html */
	return Socket->Close();
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
	int32 BytesToReceive = Size;
	uint8 Data[500000];
	TArray<unsigned char> Temp;
	Temp.Reserve(Size);
	do
	{
		int32 BytesRead = -1;
		bool Receive = Socket->Recv(Data, BytesToReceive, BytesRead);

		if (Receive)
		{

			for (int i = 0; i < BytesRead; i++)
				Temp.Add(Data[i]);
		}
		BytesToReceive -= BytesRead;
	} while (BytesToReceive != 0);
	return Temp;
}

bool TCPClient::IsConnected()
{
	return Connected;
}

void TCPClient::RecreateSocket()
{
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("TelegramSocket"), false);
}

