using UnrealBuildTool;

public class RemnantTarget : TargetRules {
	public RemnantTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;
		ExtraModuleNames.AddRange(new string[] {
			"ClothingSystemRuntime",
			"GunfireRuntime",
			"Remnant",
		});
	}
}
