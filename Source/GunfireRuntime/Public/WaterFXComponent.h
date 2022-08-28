#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "WaterFXOverride.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "WaterFXEntry.h"
#include "WaterFXComponent.generated.h"

class UPhysicsBoundsType;
class UParticleSystemComponent;
class UAudioComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UWaterFXComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWaterFXEntry> WaterEnterFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWaterFXEntry> WaterWakeFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWaterFXEntry> WaterExitFX;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ECollisionChannel> Channel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactFXThreshold;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWaterFXOverride> Overrides;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPhysicsBoundsType> LastWaterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* WakeVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* WakeSFX;
    
public:
    UWaterFXComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInWater() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UPhysicsBoundsType> GetWaterType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWaterLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWaterDepth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSubmergeDepth() const;
    
};

