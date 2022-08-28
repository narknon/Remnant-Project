#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "WeaponBase.h"
#include "EUsableActivationType.h"
#include "Engine/NetSerialization.h"
#include "EGrenadeState.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "Grenade.generated.h"

class AActor;
class USkeletalMeshComponent;
class ASpawnedGrenade;
class UWeaponAffinityComponent;
class AGrenade;

UCLASS(Blueprintable)
class REMNANT_API AGrenade : public AWeaponBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUsableActivationType ActivationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsumeInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ThrowInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DrawPathVisualization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ProximityVisualActorBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponAffinityComponent* WeaponAffinity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASpawnedGrenade> SpawnedGrenadeBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EquipAnimID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ThrowAnimID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ThrowSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxBounces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StopSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergyLossAlongNormal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergyLossAgainstNormal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThrowSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumTargetDistance;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EGrenadeState State;
    
public:
    AGrenade();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateUse();
    
    UFUNCTION(BlueprintCallable)
    void Throw();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerThrowPressed(FVector_NetQuantize TargetLocation);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerKeyPressed(FVector_NetQuantize TargetLocation);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_State(EGrenadeState PreviousState);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastThrown();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPlayThrowAnim();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPlayEquipAnim();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalGrenadeLifeSpan() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRemainingGrenadeLifeSpan() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDetonatesWhenStoppedMoving() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamageRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamage() const;
    
    UFUNCTION(BlueprintCallable)
    static void CalculateGrenadePath(AActor* Projectile, AActor* Thrower, AGrenade* GrenadeItem, const FVector& StartLocation, const FVector& StartVelocity, float SimulationTime, TArray<FPredictProjectilePathPointData>& OutPath, int32& OutNumBounces);
    
};

