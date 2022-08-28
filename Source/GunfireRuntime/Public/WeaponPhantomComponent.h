#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "WeaponPhantomProvider.h"
#include "EEffectSpawnDirection.h"
#include "UObject/NoExportTypes.h"
#include "WeaponPhantomComponent.generated.h"

class UImpactDirection;
class UDamageTypeGunfire;
class AImpactEffect;
class UShapeComponent;
class AActor;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UWeaponPhantomComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> DefaultDamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> DefaultImpactEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> DefaultBlockEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultHitCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultWeaponDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipLagSupersampling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipEnvironmentHits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipWallChecks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoHitPause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPausePhantomsDuringHitPause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxHitPauses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitPausePenalty;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeaponPhantomProvider WeaponPhantomProvider;
    
public:
    UWeaponPhantomComponent();
    UFUNCTION(BlueprintCallable)
    void StopWeaponPhantom(UShapeComponent* Shape);
    
    UFUNCTION(BlueprintCallable)
    void StopAllWeaponPhantoms();
    
    UFUNCTION(BlueprintCallable)
    void StartWeaponPhantom(UShapeComponent* Shape, AActor* Cause, TSubclassOf<UDamageTypeGunfire> DamageType, TSubclassOf<UImpactDirection> ImpactDirection, TSubclassOf<AImpactEffect> ImpactEffect, const FName& EffectBone, EEffectSpawnDirection EffectSpawnDirection, FRotator EffectOrientation, float DamageMod, float DamageScalar, bool Blockable, bool Evadable, int32 PowerOverride, float HitCooldown);
    
    UFUNCTION(BlueprintCallable)
    void SetSuspended(bool bIsSuspended);
    
    UFUNCTION(BlueprintCallable)
    void MarkActorHit(UObject* WorldContextObject, UShapeComponent* Shape, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSuspended() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRecentlyHitActor(UObject* WorldContextObject, UShapeComponent* Shape, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyOverlappingDamageable(TArray<AActor*> IgnoredActors, bool bIgnoreDeadActors) const;
    
};

