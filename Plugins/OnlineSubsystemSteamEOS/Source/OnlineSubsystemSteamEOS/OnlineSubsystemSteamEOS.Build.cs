using UnrealBuildTool;

public class OnlineSubsystemSteamEOS : ModuleRules {
    public OnlineSubsystemSteamEOS(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
        });
    }
}
