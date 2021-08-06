// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ape_Inventory_v2 : ModuleRules
{
	public Ape_Inventory_v2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
