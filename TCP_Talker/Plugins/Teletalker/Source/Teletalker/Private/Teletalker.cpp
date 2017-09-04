// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Teletalker.h"
#include "TeletalkerStyle.h"
#include "TeletalkerCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include <Widgets/DeclarativeSyntaxSupport.h>
#include "Widgets/Text/STextBlock.h"
#include <Widgets/Input/SButton.h>
#include "Reply.h"
#include "SlateDelegates.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "BinaryWriter.h"
#include "BinaryReader.h"
#include "TCPTransport.h"
#include "Authenticator.h"
#include "Networking.h"
#include "UnrealMathUtility.h"

static const FName TeletalkerTabName("Teletalker");

#define LOCTEXT_NAMESPACE "FTeletalkerModule"

void FTeletalkerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FTeletalkerStyle::Initialize();
	FTeletalkerStyle::ReloadTextures();

	FTeletalkerCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FTeletalkerCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FTeletalkerModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FTeletalkerModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FTeletalkerModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TeletalkerTabName, FOnSpawnTab::CreateRaw(this, &FTeletalkerModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FTeletalkerTabTitle", "Teletalker"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FTeletalkerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FTeletalkerStyle::Shutdown();

	FTeletalkerCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TeletalkerTabName);
}

TSharedRef<SDockTab> FTeletalkerModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FOnClicked wtf;
	wtf.BindRaw(this, &FTeletalkerModule::ButtonClicked);
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					.Text(FText::FromString("Connect"))
					.OnClicked(wtf)
				]
			]
		];
}

FReply FTeletalkerModule::ButtonClicked()
{
	FIPv4Address TelegramServer(149, 154, 167, 40);
	const int32 TelegramPort = 443;

	TCPTransport Transport(TelegramServer, TelegramPort);
	if (Transport.Connect())
		UE_LOG(LogTemp, Log, TEXT("Connected"))

	TArray<unsigned char> AuthKey = Authenticator::Authenticate(&Transport);



	return FReply::Handled();
}

void FTeletalkerModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(TeletalkerTabName);
}

void FTeletalkerModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FTeletalkerCommands::Get().OpenPluginWindow);
}

void FTeletalkerModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FTeletalkerCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTeletalkerModule, Teletalker)