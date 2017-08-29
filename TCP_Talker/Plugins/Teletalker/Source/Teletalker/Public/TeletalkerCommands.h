// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "TeletalkerStyle.h"

class FTeletalkerCommands : public TCommands<FTeletalkerCommands>
{
public:

	FTeletalkerCommands()
		: TCommands<FTeletalkerCommands>(TEXT("Teletalker"), NSLOCTEXT("Contexts", "Teletalker", "Teletalker Plugin"), NAME_None, FTeletalkerStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};