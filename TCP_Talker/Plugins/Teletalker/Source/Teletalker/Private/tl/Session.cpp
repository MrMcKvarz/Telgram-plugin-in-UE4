#include "tl/Session.h"
#include <windows.h>
#include "Engine.h"
#include "crypto/Crypto.h"


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
		GetVersionExW(&osvi);
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

	ServerAddress = "149. 154. 167. 40";
	Port = 443;
	AuthKey.Empty();
	ID = Crypto::GetRandomLong();
	Sequence = 0;
	Salt = 0;
	LastMsgID = 0;
}

bool Session::Save()
{

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	
	JsonObject->SetStringField("ID",FString::SanitizeFloat(ID));
	JsonObject->SetNumberField("Port", Port);
	JsonObject->SetNumberField("Salt", Salt);
	JsonObject->SetNumberField("Sequence", Sequence);
	JsonObject->SetStringField("ServerAddress", ServerAddress);
	FString AuthKeyString = FString::FromHexBlob(AuthKey.GetData(), AuthKey.Num());
	JsonObject->SetStringField("AuthKeyData", AuthKeyString);

	FString FileName;

	FileName += FPaths::GameContentDir();
	FileName += UserID;
	FileName += ".session";

	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	return FFileHelper::SaveStringToFile(OutputString, FileName.GetCharArray().GetData());

}

bool Session::Delete()
{
	return true;
}
