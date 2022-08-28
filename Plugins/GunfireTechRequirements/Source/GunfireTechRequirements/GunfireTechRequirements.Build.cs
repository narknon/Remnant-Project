using UnrealBuildTool;

public class GunfireTechRequirements : ModuleRules {
    public GunfireTechRequirements(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
        });
    }
}
