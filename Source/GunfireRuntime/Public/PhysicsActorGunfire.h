#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsImpactSoundInfo.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "PhysicsActorGunfire.generated.h"

class UObject;
class UPhysicsSoundInstance;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APhysicsActorGunfire : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPhysicsImpactSoundInfo> ActivePhysicsSoundInfoList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPhysicsSoundInstance*> SpawnedSoundInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SleepThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VelocityNoiseFloor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LowVelocityEncountered;
    
public:
    APhysicsActorGunfire();
private:
    UFUNCTION(BlueprintCallable)
    void SoundInstanceFinished(UObject* AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnHitCallback(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
};

