// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TeletalkerCommands.h"

#define LOCTEXT_NAMESPACE "FTeletalkerModule"

void FTeletalkerCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "Teletalker", "Bring up Teletalker window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
