// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class FastTween : ModuleRules
{
	public FastTween(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
			});
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
			});
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"UMG",
				"AssetRegistry",
				"CoreUObject"
			});
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"AssetTools",
				"AssetRegistry",
				"UnrealEd"
			});
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{ });
	}
}
