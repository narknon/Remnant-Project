using UnrealBuildTool;

public class GunfireRuntime : ModuleRules {
    public GunfireRuntime(ReadOnlyTargetRules Target) : base(Target) {
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
