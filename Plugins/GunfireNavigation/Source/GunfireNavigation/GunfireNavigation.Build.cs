using UnrealBuildTool;

public class GunfireNavigation : ModuleRules {
    public GunfireNavigation(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "NavigationSystem",
        });
    }
}
