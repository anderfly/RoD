// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class River_of_Death : ModuleRules
{
	public River_of_Death(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"AIModule",
			"Niagara", 
			"GameplayTasks",
			"NavigationSystem"
			
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] 
		{
			"River_of_Death/Public/Player",
			"River_of_Death/Public/Component",
			"River_of_Death/Public/AI",
			"River_of_Death/Public/AI/Task",
			"River_of_Death/Public/AI/Services",
			"River_of_Death/Public/Weapon"
		});
		
	}
}
