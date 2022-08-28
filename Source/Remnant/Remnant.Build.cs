using UnrealBuildTool;

public class Remnant : ModuleRules {
    public Remnant(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AnimGraphRuntime",
            "AnimationCore",
            "AudioMixer",
            "CinematicCamera",
            "Core",
            "CoreUObject",
            "Engine",
            "GameplayTags",
            "GameplayTasks",
            "GunfireRuntime",
            "GunfireSaveSystem",
            "GunfireTechRequirements",
            "InputCore",
            "LevelSequence",
            "MovieScene",
            "MovieSceneTracks",
            "NavigationSystem",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
            "ProceduralMeshComponent",
            "PropertyPath",
            "Slate",
            "SlateCore",
            "UMG",
        });
    }
}
