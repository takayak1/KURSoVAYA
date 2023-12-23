// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BoolAlgebraTrainer : ModuleRules
{
	public BoolAlgebraTrainer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CommonUI", "UMG"});

		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"Settings",
			}
		);
		
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
