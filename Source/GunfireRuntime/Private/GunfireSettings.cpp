#include "GunfireSettings.h"

UGunfireSettings::UGunfireSettings() {
    this->GroundChannel = ECC_GameTraceChannel5;
    this->WaterChannel = ECC_WorldStatic;
    this->bUseComplexCollisionForWaterSurfaceTraces = true;
    this->ProjectileChannel = ECC_GameTraceChannel2;
    this->AOEChannel = ECC_GameTraceChannel6;
    this->PawnChannel = ECC_GameTraceChannel8;
    this->SpecialCollisionChannel = ECC_GameTraceChannel16;
    this->CameraChannel = ECC_Camera;
    this->SwimmingCameraChannel = ECC_GameTraceChannel10;
    this->WallChannel = ECC_Visibility;
    this->WaterSurfaceType = SurfaceType14;
    this->HitPauseMode = EHitPauseMode::AnyDamage;
    this->bAutoMarkDamageAsResisted = true;
    this->ResistedDamageThreshold = 0.50f;
    this->TargetWeaponPhantomFrameTime = 0.01f;
    this->WeaponPhantomIgnoreDelay = 0.50f;
    this->bPlayForceFeedbackOnEvironmentHits = true;
    this->bPlayCameraShakeOnEvironmentHits = true;
    this->RedloadInteractiveMode = 6;
    this->EnableInViewTargetChecks = true;
    this->MinimumTimeDilaton = 0.00f;
    this->TimeDilationStepSize = 0.00f;
    this->KeyboardAndMouseAimAdjustScale = 0.20f;
    this->KeyboardAndMouseSnapToTargetScale = 0.00f;
    this->GlobalTargetableRadiusScale = 1.00f;
    this->GlobalSnapRadiusScale = 1.30f;
    this->FalloffDamagePenalty = 0.20f;
    this->GlobalSwayScale = 1.00f;
    this->BreakableClasses.AddDefaulted(1);
    this->bUsesUniqueAimSensitivity = true;
    this->bUsesUniqueScopeSensitivity = true;
    this->AreaFactor = 3.00f;
    this->MaxNodesToOccupy = -1;
    this->PenaltyBase = 1.70f;
    this->AmbientPriorityPolicy = EAmbientPriorityPolicy::ManualLevelDepth;
    this->MinimapCaptureOffset = 45800.00f;
    this->SoftCollisionAbsoluteWeightDifference = 500.00f;
    this->bDoNotifyRateOptimzations = false;
    this->GlobalNotifyMaximumRate = 10;
    this->bEnableMeshActivationOptimizations = true;
    this->MeshActivationLingerTime = 1.00f;
    this->MeshActivationBoneOnlyLingerTime = 0.20f;
}

