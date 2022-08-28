#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ERangedWeaponTrajectoryMode.h"
#include "WeaponBase.h"
#include "UObject/NoExportTypes.h"
#include "ProjectileVisualizationParams.h"
#include "OnReloadDelegateDelegate.h"
#include "CustomWeaponSpread.h"
#include "ReplicatedHits.h"
#include "ProjectileVisualizationContext.h"
#include "RangedWeaponMode.h"
#include "Engine/NetSerialization.h"
#include "ReplicatedLocation.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "RangedWeapon.generated.h"

class AItem;
class URangedWeaponProfile;
class UReticule;
class AActor;
class UUserWidget;
class UMaterialInterface;
class USoundBase;
class UParticleSystem;
class UVitalityComponent;
class USceneComponent;
class AProjectileBase;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ARangedWeapon : public AWeaponBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URangedWeaponProfile> Profile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UReticule* Reticule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FireWhileAimingOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowActionOnFlinch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ReloadAfterStartLoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERangedWeaponTrajectoryMode TrajectoryMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ProjectileExtent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ProjectileSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MuzzleObstructionDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ProjectileToVisualize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProjectileVisualizationParams VisualizationParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> AmmoType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AmmoPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FireInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ReloadInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ReloadOnRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ScopeInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DoubleClickScopeInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumAimTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UReticule* ScopeReticule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> ScopeWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> ScopePostProcess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ScopeInSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ScopeOutSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCameraWhenAimingWithScope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CameraRelativeScopeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimScopeInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumAimDelayForScope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomWeaponSpread CustomSpread;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReadyTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadLoopTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadEndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MuzzleAttachPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* MuzzleFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AttachMuzzleFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OutOfAmmoSoundIDName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* OutOfAmmoSoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseLowAmmoSounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LowAmmoCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* BulletWhizBySoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulletWhizByRadius;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReloadDelegate OnReload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UVitalityComponent* AmmoPoolComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* Muzzle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FProjectileVisualizationContext VisualizationContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRangedWeaponMode DefaultWeaponMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRangedWeaponMode OverrideWeaponMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AProjectileBase*> FiredProjectiles;
    
public:
    ARangedWeapon();
    UFUNCTION(BlueprintCallable)
    void TriggerSoundAwareness(float Radius);
    
    UFUNCTION(BlueprintCallable)
    void ToggleScopeInput(bool bRequiresAimInput);
    
    UFUNCTION(BlueprintCallable)
    void SetFireInput(FName FireInputName);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetState(uint8 InState);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerFire(FVector_NetQuantize from, const FReplicatedLocation& to, float WeaponSpread, uint32 RandomSeed, const FReplicatedHits& ClientHits);
    
    UFUNCTION(BlueprintCallable)
    void Reload();
    
public:
    UFUNCTION(BlueprintCallable)
    void PlayMuzzleFX(UParticleSystem* WeaponMuzzleFX, bool Attach);
    
    UFUNCTION(BlueprintCallable)
    void PlayFireAnimation(FName AnimationID);
    
    UFUNCTION(BlueprintCallable)
    void OnScopeInputPressed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReloaded();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreFireEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreFireBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFire(const FVector& from, const FVector& to, float WeaponSpread);
    
    UFUNCTION(BlueprintCallable)
    void OnFinishLoadingScopePostProcess();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnDoubleClickScopeInputReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnDoubleClickScopeInputPressed();
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastSetStateNS(uint8 InState);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastSetState(uint8 InState);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastFire(FVector_NetQuantize from, const FReplicatedLocation& to, float WeaponSpread, uint32 RandomSeed);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsScopeInputEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReloading() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFiring() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBusy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAimingWithScope() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAiming() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasScope() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRangedWeaponMode GetWeaponMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSprayCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetScopeFOV() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRateOfFire() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRange(bool bIncludeFalloff) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRandomStream GetRandomStream();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FProjectileVisualizationContext GetProjectileVisualization();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNormalizedSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetMuzzleObstruction();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMuzzleFXPointAndDirection(FVector& MuzzlePoint, FVector& MuzzleDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxAmmo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFalloff(bool bPrimaryFalloffOnly) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamageScalar(float Distance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBurstRateOfFire() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBurstCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmmoPerReload() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmmoPerClip() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmmoInClip() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmmo() const;
    
    UFUNCTION(BlueprintCallable)
    void GetAimVector(FVector& from, FVector& to, bool bApplyAimAssist, bool bOverrideTrajectoryMode, ERangedWeaponTrajectoryMode TrajectoryModeOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetAimTargetLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetAimTarget();
    
    UFUNCTION(BlueprintCallable)
    AActor* FireProjectile(AActor* Cause, const FVector& Origin, const FVector& End, float WeaponSpread, TSubclassOf<AActor> ProjectileBP, float Velocity, bool bGroup);
    
    UFUNCTION(BlueprintCallable)
    void FillClip(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void EndUse();
    
    UFUNCTION(BlueprintCallable)
    void DoInstantHit(const FVector& Origin, const FVector& End, float WeaponSpread);
    
    UFUNCTION(BlueprintCallable)
    void DoImpact(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void ConsumeAmmo(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void ClearDoubleClickTimer();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanStopAiming() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanReload() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanFire() const;
    
    UFUNCTION(BlueprintCallable)
    void BeginUse();
    
    UFUNCTION(BlueprintCallable)
    void BeginReload();
    
    UFUNCTION(BlueprintCallable)
    void ApplySpread(float Scalar);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyRecoil(float Scalar);
    
    UFUNCTION(BlueprintCallable)
    void AddAmmo(int32 Amount, bool NewFillClip);
    
};

