#include "Session.h"
#include <windows.h>
#include "Engine.h"
#include "crypto/Crypto.h"
#include "extensions/BinaryWriter.h"
#include "extensions/BinaryReader.h"

FString GetOSName()
{
	#ifdef _WIN32
		return "Windows 32-bit";
	#elif _WIN64
		return "Windows 64-bit";
	#elif __unix || __unix__
		return "Unix";
	#elif __APPLE__ || __MACH__
		return "Mac OSX";
	#elif __linux__
		return "Linux";
	#elif __FreeBSD__
		return "FreeBSD";
	#else
		return "Unknown";
	#endif
}

FString GetOSVersion()
{
	#ifdef _WIN32
		OSVERSIONINFO osvi;
		ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		GetVersionEx(&osvi);
		return FString::FromInt(osvi.dwMajorVersion);
 	#else
 		return "1.0";
	#endif
}

Session::Session(FString SessionUserdID)
{
	UserID = SessionUserdID;
	DeviceModel = GetOSName();
	SystemVersion = GetOSVersion();
	AppVersion = "1.0";
	LangCode = "en";
	SystemLangCode = LangCode;
	LangPack = "";

	ServerAddress = "149.154.167.51";//"149.154.167.51"; /*This is address of some data center of Telegram*/
	Port = 443;
	Sequence = 0;
	Salt = 0;
	GenerateNewSessionID();
	LastMsgID = 0;
	SessionFilePath = FString(L"D:\\TeleRealTest\\");
}

bool Session::Save()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

	BinaryWriter IDWriter;
	IDWriter.WriteLong(ID);	
	/*This write string that itself is invalid, but contains right bytes, and we are able to load it correctly*/
	/*this is actually not that bad, since it provide some kind of protection to session file*/
	JsonObject->SetNumberField("Port", Port);

	BinaryWriter SaltWriter;
	SaltWriter.WriteLong(Salt);
	JsonObject->SetStringField("Salt", FString::FromBlob(SaltWriter.GetBytes().GetData(), SaltWriter.GetWrittenBytesCount()));
	JsonObject->SetStringField("ServerAddress", ServerAddress);
	FString AuthKeyString = FString::FromHexBlob(SessionAuthKey.GetKey().GetData(), SessionAuthKey.GetKey().Num());
	JsonObject->SetStringField("AuthKeyData", AuthKeyString);

	FString FileName;
	FileName += SessionFilePath;
	FileName += UserID;
	FileName += ".session";

	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	return FFileHelper::SaveStringToFile(OutputString, FileName.GetCharArray().GetData(), FFileHelper::EEncodingOptions::AutoDetect,&IFileManager::Get(),2);
}

bool Session::Load()
{

	FString JsonString;
	FString FilePath = SessionFilePath + UserID + ".session";
	if(!FFileHelper::LoadFileToString(JsonString, FilePath.GetCharArray().GetData())) return false;

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		Port = JsonObject->GetNumberField(TEXT("Port"));

		FString SaltString = JsonObject->GetStringField(TEXT("Salt"));
		uint8 SaltBuffer[2048];
		FString::ToBlob(SaltString, SaltBuffer, SaltString.Len());
		Salt = BinaryReader(SaltBuffer, SaltString.Len()).ReadLong();

		ServerAddress = JsonObject->GetStringField(TEXT("ServerAddress"));
		FString AuthKeyString = JsonObject->GetStringField(TEXT("AuthKeyData"));

		uint8 AuthKeyBuffer[2048];
		FString::ToHexBlob(AuthKeyString, AuthKeyBuffer, AuthKeyString.Len());
		SessionAuthKey.SetKey(AuthKeyBuffer);
		return true;
	}
	return false;
}

bool Session::Delete()
{
	return true;
}

void Session::GenerateNewSessionID()
{
	ID = Crypto::GetRandomLong();
}

