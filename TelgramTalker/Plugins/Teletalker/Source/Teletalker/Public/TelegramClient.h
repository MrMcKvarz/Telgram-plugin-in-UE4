#pragma once 
#include "Engine.h"
#include "UserError.h"
#include "../TL/Types/COMMON/Public/User.h"
#include "../TL/Types/COMMON/Public/Chat.h"

class Session;
class TLBaseObject;
class TCPTransport;
class MTProtoSender;

// namespace COMMON
// {
// 	class User;
// 	class Chat;
// };


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

	TArray<COMMON::User> Users;
	TArray<COMMON::Chat> Chats;
public:
	bool bUserAuthorized; // presentation only
	TelegramClient(FString SessionName, int32 API_id, FString API_hash);
	~TelegramClient();
	UserError Connect();
	UserError SendCode(FString PhoneNumber);
	bool Invoke(TLBaseObject &Request);
	bool Reconnect();
	UserError GetDialogSlice(int32 SliceNumber, TArray<FString> &OutTitles);
	UserError SingIn(FString Code);
	
	UserError SendMessage(FString UserSendTo, FString Message);
	UserError IsUserAuthorized();
	UserError LogOut();

	/*We stay on the same DC but creating new session*/
	bool CreateNewSession();
protected:
	void GenerateNewAuthKey();
};
