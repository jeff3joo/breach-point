// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BreachPoint : ModuleRules
{
	public BreachPoint(ReadOnlyTargetRules Target) : base(Target)
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
			"BreachPoint",
			"BreachPoint/Variant_Platforming",
			"BreachPoint/Variant_Platforming/Animation",
			"BreachPoint/Variant_Combat",
			"BreachPoint/Variant_Combat/AI",
			"BreachPoint/Variant_Combat/Animation",
			"BreachPoint/Variant_Combat/Gameplay",
			"BreachPoint/Variant_Combat/Interfaces",
			"BreachPoint/Variant_Combat/UI",
			"BreachPoint/Variant_SideScrolling",
			"BreachPoint/Variant_SideScrolling/AI",
			"BreachPoint/Variant_SideScrolling/Gameplay",
			"BreachPoint/Variant_SideScrolling/Interfaces",
			"BreachPoint/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
