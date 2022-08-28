#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HitLocationInfo.h"
#include "DamageInfo.h"
#include "UObject/NoExportTypes.h"
#include "HitLogComponent.generated.h"

class UAnimInstanceGunfire;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UHitLogComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeakSpotDamageScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResistSpotDamageScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FHitLocationInfo> HitLocations;
    
protected:
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_DestroyedFlags)
    uint32 RepDestroyedFlags;
    
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_LastHitLocation)
    uint8 LastHitLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDamageInfo LastHitInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDamageInfo LastDamageInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimInstanceGunfire* AnimInstance;
    
public:
    UHitLogComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void ResetAllHitLocationHealth();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_LastHitLocation();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_DestroyedFlags();
    
public:
    UFUNCTION(BlueprintCallable)
    FDamageInfo GetLastHitInfo();
    
    UFUNCTION(BlueprintCallable)
    FDamageInfo GetLastDamageInfo();
    
    UFUNCTION(BlueprintCallable)
    float GetImpactDamageForHitLocation(const FDateTime& Time, const FName& HitLocation, bool bIgnoreImpactScalar);
    
    UFUNCTION(BlueprintCallable)
    float GetDamageForHitLocation(const FDateTime& Time, const FName& HitLocation);
    
    UFUNCTION(BlueprintCallable)
    float GetDamage(const FDateTime& Time);
    
    UFUNCTION(BlueprintCallable)
    void ClearHitLog();
    
};

