#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/NoExportTypes.h"
#include "FogOfWarChangedEventDelegate.h"
#include "VisibleCoordinate.h"
#include "UObject/NoExportTypes.h"
#include "FogOfWarComponent.generated.h"

class UMaterialInstanceDynamic;
class UTexture2D;
class ACharacter;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UFogOfWarComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VisibilityRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MiniMapDimension;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFogOfWarChangedEvent OnFogOfWarChanged;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockChanges;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MatInst;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTexture2D* FogOfWarMaskTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter* OwningCharacter;
    
public:
    UFogOfWarComponent();
    UFUNCTION(BlueprintCallable)
    void ToggeleFogOfWar();
    
    UFUNCTION(BlueprintCallable)
    void ShowVisitedCoordinates();
    
    UFUNCTION(BlueprintCallable)
    void SetFogOfWar(bool bHasFog);
    
    UFUNCTION(BlueprintCallable)
    void Init(FBox RelevantWorldBounds);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasFogOfWar() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWorldMaxDimension() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox GetWorldBounds() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVisibilityAtLocation(FVector WorldLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetLocationAtCoordinate(FVisibleCoordinate Coordinate) const;
    
    UFUNCTION(BlueprintCallable)
    void AddVisibleLocation(FVector Location);
    
};

