#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "DamageableInterface.h"
#include "Engine/EngineTypes.h"
#include "DamageInfo.h"
#include "ReplicatedHit.h"
#include "ProjectileBase.generated.h"

class UActionBase;
class UActionComponent;
class UShapeComponent;
class UReplicatedMovementComponent;
class UProjectileMovementComponentGunfire;
class UDamageTypeGunfire;
class UAudioComponent;
class UCameraShake;
class USoundBase;
class AImpactEffect;
class UParticleSystem;
class UWorld;
class AProjectileBase;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API AProjectileBase : public AActor, public IDamageableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Cause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLifetime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* Collision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileMovementComponentGunfire* ProjectileMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReplicatedMovementComponent* ProjectileReplication;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActionComponent* ActionComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* Loop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DestroyAfterImpactEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AttachOnHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AttachIgnoreBones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetCooldownTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UActionBase>> Actions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UActionBase>> PostImpactActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DestroyBreakables;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActivateNearbyCharacters;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalActivateRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ApplyDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> DamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PowerOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Evadable;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPenetrate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxPenetrations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PenetrateDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PenetrationDamageScalarInitial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PenetrationDamageScalarIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> PenetratableClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> IgnoreClasses;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraShake> CameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Falloff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoopFadeInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ImpactSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> ImpactEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ImpactVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorld* SimulationWorld;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDamageable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AProjectileBase*> ProjectileGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHasGroupDoneHit;
    
    AProjectileBase();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateHit(const FHitResult& Hit, bool bSimulating);
    
    UFUNCTION(BlueprintCallable)
    void SetMaxLifeTime(float NewMaxLifeTime);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStop(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnProjectileStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnProjectilePenetrate(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnProjectileHit(const FHitResult& Hit);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNotifyTakeDamage(const FDamageInfo& DamageInfo);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnHit(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastStop();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastImpactEffect(const FReplicatedHit& ReplicatedHit, bool bFinalHit);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsSprayHit(const FHitResult& Hit);
    
public:
    UFUNCTION(BlueprintCallable)
    void IncrementNumPenetrations();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumPenetrations();
    
    
    // Fix for true pure virtual functions not being implemented
};

