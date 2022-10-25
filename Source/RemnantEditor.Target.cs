using UnrealBuildTool;

public class RemnantEditorTarget : TargetRules {
	public RemnantEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange(new string[] {
			"GunfireRuntime",
			"Remnant",
		});
	}
}
