#pragma once 
#include "Engine.h"

class Session;
class TLBaseObject;
class TCPTransport;
class MTProtoSender;

namespace COMMON
{
	class User;
	class Chat;
};


class TELETALKER_API TelegramClient
{
	TSharedPtr<Session> ClientSession;
	int32 API_ID;
	FString API_Hash;

	TSharedPtr<MTProtoSender> Sender;
	bool bAuthorized;
	bool bAuthanticated;
	FString PhoneHashCode;
	FString PhoneNumber;

	TArray<COMMON::User*> Users;
	TArray<COMMON::Chat *> Chats;
public:
	bool bUserAuthorized; // presentation only
	TelegramClient(FString SessionName, int32 API_id, FString API_hash);
	~TelegramClient();
	bool Connect();
	bool SendCode(FString PhoneNumber);
	bool Invoke(TLBaseObject &Request);
	void Reconnect();
	TArray<FString> GetDialogSlice(int32 SliceNumber);
	bool SingIn(FString Code);
	
	bool SendMessage(FString UserSendTo, FString Message);
	bool IsUserAuthorized();
	bool LogOut();
protected:
	void GenerateNewAuthKey();
};
