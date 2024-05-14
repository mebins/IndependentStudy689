// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IndependentStudyProj : ModuleRules
{
	public IndependentStudyProj(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
