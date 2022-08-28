#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnedGrenadeRepData.h"
#include "SpawnedGrenade.generated.h"

class AGrenade;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class REMNANT_API ASpawnedGrenade : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AGrenade* Grenade;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_GrenadeRepData, meta=(AllowPrivateAccess=true))
    FSpawnedGrenadeRepData GrenadeRepData;
    
public:
    ASpawnedGrenade();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStoppedMoving();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_GrenadeRepData();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDetonated();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGrenadeLifeSpan() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AGrenade* GetGrenadeItemCDO() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void Detonate();
    
};

