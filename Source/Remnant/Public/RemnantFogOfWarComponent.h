#pragma once
#include "CoreMinimal.h"
#include "FogOfWarComponent.h"
#include "UObject/NoExportTypes.h"
#include "RemnantFogOfWarComponent.generated.h"

class AActor;
class AZoneActor;
class UMaterialInstanceDynamic;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantFogOfWarComponent : public UFogOfWarComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumWorldBoundsDimension;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorldPaddingScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PanOffset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* LockedActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AZoneActor* VisitedCoordinatesOwner;
    
public:
    URemnantFogOfWarComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void UpdateMaterial(UMaterialInstanceDynamic* MaterialInstance, FVector WorldLocation, bool bSetMask, float ScaleOverride) const;
    
    UFUNCTION(BlueprintCallable)
    void SetDebugLocation(const FVector& NewLocation);
    
    UFUNCTION(BlueprintCallable)
    void LockToActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDebugLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetLockActor() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearDebugLocation();
    
};

