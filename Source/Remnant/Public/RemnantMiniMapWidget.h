#pragma once
#include "CoreMinimal.h"
#include "MiniMapWidget.h"
#include "RemnantMiniMapWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class REMNANT_API URemnantMiniMapWidget : public UMiniMapWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreFogOfWar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FogOfWarOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FogOfWarTolerance;
    
public:
    URemnantMiniMapWidget();
    UFUNCTION(BlueprintCallable)
    void UpdateWidgetVisibility();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldIgnoreFogOfWar() const;
    
    UFUNCTION(BlueprintCallable)
    void SetVisibleFromLevel(bool bVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWidgetVisible() const;
    
};

