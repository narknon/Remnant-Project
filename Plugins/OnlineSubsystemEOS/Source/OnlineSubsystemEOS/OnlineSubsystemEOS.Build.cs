using UnrealBuildTool;

public class OnlineSubsystemEOS : ModuleRules {
    public OnlineSubsystemEOS(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AudioMixer",
            "Core",
            "CoreUObject",
            "Engine",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
        });
    }
}
