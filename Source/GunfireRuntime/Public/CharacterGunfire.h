#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnTargetChangedDelegateDelegate.h"
#include "GameFramework/Character.h"
#include "FocusChangedDelegateDelegate.h"
#include "DamageableInterface.h"
#include "EDecalReceiverType.h"
#include "DamageSourceInterface.h"
#include "EventHandlerInterface.h"
#include "Engine/EngineTypes.h"
#include "OnFactionChangeDelegateDelegate.h"
#include "Engine/DataTable.h"
#include "OnTargetedDelegateDelegate.h"
#include "OnDeadDelegateDelegate.h"
#include "ActiveRagdollInfo.h"
#include "SpectateChangeEventDelegate.h"
#include "DamageEventDelegateDelegate.h"
#include "OnHealthChangedDelegateDelegate.h"
#include "EventDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "EEffectSpawnDirection.h"
#include "WeaponPhantomProvider.h"
#include "UObject/NoExportTypes.h"
#include "EDeadReason.h"
#include "InspectStat.h"
#include "InspectInfo.h"
#include "CharacterGunfire.generated.h"

class UReplicatedMovementComponent;
class UObject;
class UStatsComponent;
class UActionComponent;
class AActor;
class UHitLogComponent;
class UDataTable;
class UStateMachineComponent;
class UStats;
class UFaction;
class UDamageTypeGunfire;
class UCharacterManager;
class AImpactEffect;
class UInventoryComponent;
class ACharacterGunfire;
class UShapeComponent;
class UImpactDirection;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ACharacterGunfire : public ACharacter, public IDamageableInterface, public IDamageSourceInterface, public IEventHandlerInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActionComponent* ActionComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitLogComponent* HitLogComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReplicatedMovementComponent* ReplicatedMovementComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDataTable*> AdditionalStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStats> InspectStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFaction> Faction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> DefaultDamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> DefaultImpactEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> DefaultBlockEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> FootEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> FootSprintEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> HandEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> HandSprintEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> LandEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> SlamEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> BodyEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GlobalFootImpactOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveRagdollInfo ActiveRagdollInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDecalReceiverType ReceiveDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NetNotifyHitTarget;
    
    UPROPERTY(EditAnywhere, Transient)
    uint32 SpawnID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName AggroGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName SpawnState;
    
    UPROPERTY(EditAnywhere, Replicated, SaveGame)
    uint8 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Health, meta=(AllowPrivateAccess=true))
    float HealthNormalized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTargetChangedDelegate OnTargetChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTargetedDelegate OnTargeted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpectateChangeEvent OnSpectatorAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpectateChangeEvent OnSpectatorRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFactionChangeDelegate OnFactionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnNotifyHitTarget;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnNotifyTakeDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHealthChangedDelegate OnNotifyHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeadDelegate OnPreDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeadDelegate OnDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventDelegate OnEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFocusChangedDelegate OnViewportFocusEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableCharacterOptimizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationHalfHeightInflation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationRadiusInflation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumTimeDilation;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStateMachineComponent* CachedStateMachine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInventoryComponent* CachedInventory;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator ViewRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Target, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* CharacterTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* AimTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeaponPhantomProvider WeaponPhantomProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipWallChecks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseClothSimulationOnTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetAnimDynamicsOnResumeClothingSim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClothSimulationPauseThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCharacterManager* CharacterManager;
    
public:
    ACharacterGunfire();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void StopWeaponPhantom(UShapeComponent* Shape);
    
    UFUNCTION(BlueprintCallable)
    void StopAllWeaponPhantoms();
    
    UFUNCTION(BlueprintCallable)
    void StartWeaponPhantom(UShapeComponent* Shape, AActor* Cause, TSubclassOf<UDamageTypeGunfire> DamageType, TSubclassOf<UImpactDirection> ImpactDirection, TSubclassOf<AImpactEffect> ImpactEffect, const FName& EffectBone, EEffectSpawnDirection EffectSpawnDirection, FRotator EffectOrientation, float DamageMod, float DamageScalar, bool Blockable, bool Evadable, int32 PowerOverride, float HitCooldown);
    
    UFUNCTION(BlueprintCallable)
    void SortTags();
    
    UFUNCTION(BlueprintCallable)
    void SetWeaponPhantomsSuspended(bool bIsSuspended);
    
    UFUNCTION(BlueprintCallable)
    void SetTarget(AActor* Character);
    
    UFUNCTION(BlueprintCallable)
    void SetIsTargetable(bool Targetable);
    
    UFUNCTION(BlueprintCallable)
    void SetHealth(float Health);
    
    UFUNCTION(BlueprintCallable)
    void SetGlobalCooldown(float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetFaction(TSubclassOf<UFaction> NewFaction);
    
    UFUNCTION(BlueprintCallable)
    void SetCooldown(const FName& Cooldown, float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetAimTarget(AActor* InTarget);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetAimTarget(AActor* InTarget);
    
    UFUNCTION(BlueprintCallable)
    void ScaleStat(FName Stat, float Scalar, bool AutoInitValue);
    
    UFUNCTION(BlueprintCallable)
    void RestoreAggroGroup(FName PreviousAggroGroup, bool bRemoveAll);
    
    UFUNCTION(BlueprintCallable)
    void ResetHealth(bool bResetHitLocations);
    
    UFUNCTION(BlueprintCallable)
    void ResetClothingSimulation(bool FullReset);
    
    UFUNCTION(BlueprintCallable)
    void RemoveTag(const FName& Tag, bool bRemoveAll);
    
    UFUNCTION(BlueprintCallable)
    void ReinitializeCloth();
    
    UFUNCTION(BlueprintCallable)
    void Ragdoll(const FName RootBoneName);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PostComputeStats();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Target(AActor* PreviousTarget);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Health();
    
    UFUNCTION(BlueprintCallable)
    void OnRagdollHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLocallyControlled();
    
    UFUNCTION(BlueprintCallable)
    void OnGameViewportFocusChanged(bool HasFocus);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnComputeStats();
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterStateChanged(const FName& StateName, const FName& PreviousStateName);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnCharacterDead(EDeadReason Reason, AActor* Cause);
    
    UFUNCTION(BlueprintCallable)
    void ModifyStat(FName Stat, float Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void MarkActorHit(UObject* WorldContextObject, UShapeComponent* Shape, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWounded() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsEditor();
    
    UFUNCTION(BlueprintCallable)
    bool IsCinematicCharacter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAlive() const;
    
    UFUNCTION(BlueprintCallable)
    void HitPause(float Duration, float Dilation, float EaseInTime, float EaseOutTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool HasRecentlyHitActor(UObject* WorldContextObject, UShapeComponent* Shape, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyOverlappingDamageable(TArray<AActor*> IgnoredActors, bool bIgnoreDeadActors) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetViewRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStateMachineComponent* GetStateMachine() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStat(FName Stat);
    
    UFUNCTION(BlueprintCallable)
    bool GetIsTargetable();
    
    UFUNCTION(BlueprintCallable)
    FInspectStat GetInspectStatInfo(const FName& Stat);
    
    UFUNCTION(BlueprintCallable)
    FInspectInfo GetInspectInfo();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthPercentage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthMax() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealth() const;
    
    UFUNCTION(BlueprintCallable)
    float GetCooldownPct(const FName& Cooldown);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetCharacterInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetAimTarget();
    
    UFUNCTION(BlueprintCallable)
    FName GetAggroGroup();
    
    UFUNCTION(BlueprintCallable)
    void EnableClothingSimulation();
    
    UFUNCTION(BlueprintCallable)
    void DisableClothingSimulation();
    
protected:
    UFUNCTION(BlueprintCallable)
    void DifficultyChanged();
    
    UFUNCTION(BlueprintCallable)
    void ComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyTakeDamage(AActor* Source, float Damage, int32 Power);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyHitTarget(AActor* Cause, AActor* InTarget, const FVector& ImpactPoint, float Damage, bool Killed, bool Critical, bool WeakSpot, bool Resisted);
    
    UFUNCTION(BlueprintCallable)
    void ClearAggroGroup();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckTags(const TArray<FName>& TagsToCheck, bool AllOrNothing) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckTag(FName Tag) const;
    
    UFUNCTION(BlueprintCallable)
    bool CheckCooldown(const FName& Cooldown);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreWeaponPhantomsSuspended() const;
    
    UFUNCTION(BlueprintCallable)
    bool AreCharacterOptimizationsEnabled();
    
    UFUNCTION(BlueprintCallable)
    void ApplyHealthDelta(float Delta);
    
    UFUNCTION(BlueprintCallable)
    void AddTag(const FName& Tag);
    
    UFUNCTION(BlueprintCallable)
    void AddAggroGroup(FName NewAggroGroup, bool bUniqueOnly);
    
    
    // Fix for true pure virtual functions not being implemented
};

