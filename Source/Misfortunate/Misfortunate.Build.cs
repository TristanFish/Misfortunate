// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Misfortunate : ModuleRules
{
	public Misfortunate(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AdvancedSessions", "AdvancedSteamSessions", "OnlineSubsystem", "OnlineSubsystemUtils", "OnlineSubsystemSteam", "Networking", "Sockets", "MetasoundEngine", "EnhancedInput", "GameplayTags" });
	}
}
