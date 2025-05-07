// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Burlesca : ModuleRules
{
	public Burlesca(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
            "EnhancedInput",
            "Slate",
			"SlateCore",
			"DialogueGraphRuntime",
			"FastTween",
			"MetasoundEngine"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"UnrealEd", 
			"EditorStyle",
			"GraphEditor",
			"Kismet",  
			"Slate",
			"SlateCore",
			"MetasoundEngine",
		});
	}
}
