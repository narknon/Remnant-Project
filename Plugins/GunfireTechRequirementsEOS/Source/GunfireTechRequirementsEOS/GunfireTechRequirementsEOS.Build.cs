using UnrealBuildTool;

public class GunfireTechRequirementsEOS : ModuleRules {
    public GunfireTechRequirementsEOS(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "GunfireTechRequirements",
        });
    }
}
