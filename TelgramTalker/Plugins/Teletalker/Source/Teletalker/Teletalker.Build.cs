// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Teletalker : ModuleRules
{
	public Teletalker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"Teletalker/Public",
                "Teletalker/Public/crypto",
                "Teletalker/Public/extensions",
                "Teletalker/Public/network",
                "Teletalker/Public/tl",
                "Teletalker/Public/error"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"Teletalker/Private",
				"Teletalker/Private/crypto",
                "Teletalker/Private/extensions",
                "Teletalker/Private/network",
                "Teletalker/Private/tl",
                "Teletalker/Private/error"
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Sockets",
                "Networking",
                "OpenSSL",
                "Json",
                "JsonUtilities",
                "zlib"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
