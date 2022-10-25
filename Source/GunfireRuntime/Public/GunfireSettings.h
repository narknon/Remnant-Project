#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "UObject/Object.h"
#include "EHitPauseMode.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EAmbientPriorityPolicy.h"
#include "GunfireSettings.generated.h"

class UActorComponent;
class AActor;
class UBlueprint;
class UActionBase;

UCLASS(Blueprintable, DefaultConfig, Config=Engine)
class GUNFIRERUNTIME_API UGunfireSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> GroundChannel;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> WaterChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool bUseComplexCollisionForWaterSurfaceTraces;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TArray<TEnumAsByte<ECollisionChannel>> WaterObjectTypes;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> ProjectileChannel;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> AOEChannel;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> PawnChannel;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> SpecialCollisionChannel;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> CameraChannel;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> SwimmingCameraChannel;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<ECollisionChannel> WallChannel;
    
    UPROPERTY(EditAnywhere, GlobalConfig)
    TEnumAsByte<EPhysicalSurface> WaterSurfaceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FSoftObjectPath UserSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UActorComponent> VisiblitySkipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FSoftObjectPath VisualLoggerDefaultMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    EHitPauseMode HitPauseMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool bAutoMarkDamageAsResisted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float ResistedDamageThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float TargetWeaponPhantomFrameTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float WeaponPhantomIgnoreDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool bPlayForceFeedbackOnEvironmentHits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool bPlayCameraShakeOnEvironmentHits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    int32 RedloadInteractiveMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool EnableInViewTargetChecks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float MinimumTimeDilaton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float TimeDilationStepSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float KeyboardAndMouseAimAdjustScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float KeyboardAndMouseSnapToTargetScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float GlobalTargetableRadiusScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float GlobalSnapRadiusScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float FalloffDamagePenalty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float GlobalSwayScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FColor NoTargetColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FColor HostileTargetColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FColor NeutralTargetColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FColor FriendlyTargetColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FColor ProjectileNoTargetColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FColor ProjectileHostileTargetColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FColor ProjectileNeutralTargetColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FColor ProjectileFriendlyTargetColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> BreakableClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool bUsesUniqueAimSensitivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool bUsesUniqueScopeSensitivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float AreaFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    int32 MaxNodesToOccupy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float PenaltyBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    EAmbientPriorityPolicy AmbientPriorityPolicy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UBlueprint> MinimapThumbnailActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float MinimapCaptureOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float SoftCollisionAbsoluteWeightDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool bDoNotifyRateOptimzations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    int32 GlobalNotifyMaximumRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    bool bEnableMeshActivationOptimizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float MeshActivationLingerTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float MeshActivationBoneOnlyLingerTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UActionBase> PossessedObjectAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FSoftObjectPath Achievements;
    
    UGunfireSettings();
};

