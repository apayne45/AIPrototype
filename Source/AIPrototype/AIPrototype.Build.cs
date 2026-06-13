// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AIPrototype : ModuleRules
{
	public AIPrototype(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"AIPrototype",
			"AIPrototype/Variant_Platforming",
			"AIPrototype/Variant_Platforming/Animation",
			"AIPrototype/Variant_Combat",
			"AIPrototype/Variant_Combat/AI",
			"AIPrototype/Variant_Combat/Animation",
			"AIPrototype/Variant_Combat/Gameplay",
			"AIPrototype/Variant_Combat/Interfaces",
			"AIPrototype/Variant_Combat/UI",
			"AIPrototype/Variant_SideScrolling",
			"AIPrototype/Variant_SideScrolling/AI",
			"AIPrototype/Variant_SideScrolling/Gameplay",
			"AIPrototype/Variant_SideScrolling/Interfaces",
			"AIPrototype/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
