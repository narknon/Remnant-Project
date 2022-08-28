using UnrealBuildTool;

public class GunfireTechRequirementsSteam : ModuleRules {
    public GunfireTechRequirementsSteam(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "GunfireTechRequirements",
        });
    }
}
