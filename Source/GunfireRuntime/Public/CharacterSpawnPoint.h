#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CharacterSpawnedEventDelegate.h"
#include "SpawnPointBase.h"
#include "SpawnPointEnabledEventDelegate.h"
#include "CharacterDiedEventDelegate.h"
#include "ESpawnDelayType.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "CharacterSpawnPoint.generated.h"

class USkeletalMeshComponent;
class ACharacterGunfire;
class UCapsuleComponent;
class UArrowComponent;
class AAIPathPoint;
class ATriggerVolume;
class USphereComponent;
class USpawnPointManager;
class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ACharacterSpawnPoint : public ASpawnPointBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacterGunfire> EnemyType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnPointEnabledEvent OnEnabled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterSpawnedEvent OnCharacterSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterDiedEvent OnCharacterDied;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* VisualComponent;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UArrowComponent* ArrowComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAIPathPoint* PatrolPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAIPathPoint* SpawnPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyThreat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThreatToApply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnDelayType DelaySetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDelayMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDelayMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CharacterTags;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DesiredCharacters;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesDeferredSpawnOptimization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnFromTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOneTimeTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ATriggerVolume*> TriggerVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnOnProximity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOneTimeProximity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnSphereRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USphereComponent* Sphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* SpawnedCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle DeferredSpawnHandle;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEditorVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxRespawns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RespawnDelayMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RespawnDelayMax;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSpawningEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SpawnCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPaused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USpawnPointManager* SpawnPointManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacterGunfire*> SpawnedCharactersList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SpawnedCharacterProxies;
    
public:
    ACharacterSpawnPoint();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Spawn(float InDelay, bool IsRespawn, bool bUseDeferredOptimization);
    
    UFUNCTION(BlueprintCallable)
    void ResumeSpawner();
    
    UFUNCTION(BlueprintCallable)
    void ResetSpawn(bool ResetOneTimeEvents, bool ResetSpawnTimer, bool DestroySpawnedActors);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCharacterProxy(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PostInitSpawnPoint();
    
    UFUNCTION(BlueprintCallable)
    void PauseSpawner();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTriggerEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnTriggerBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnProxyDestroyed(AActor* DestroyedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterDestroyed(AActor* DestroyedActor);
    
    UFUNCTION()
    void OnCharacterDead(uint8 Reason, ACharacterGunfire* Character, AActor* Cause);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumAliveSpawns();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<ACharacterGunfire> GetEnemyTypeOverride();
    
    UFUNCTION(BlueprintCallable)
    void EnableSpawnPoint(bool InEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanSpawnFromTriggers();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanSpawnFromDelay();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanSpawn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanRespawn() const;
    
    UFUNCTION(BlueprintCallable)
    void AddCharacterProxy(AActor* Actor);
    
};

