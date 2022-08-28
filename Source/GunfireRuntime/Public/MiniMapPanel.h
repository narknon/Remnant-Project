#pragma once
#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "EMiniMapPanelScalingMethod.h"
#include "MiniMapPanel.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UMiniMapPanel : public UCanvasPanel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetPixelSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WidgetScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMiniMapPanelScalingMethod ScalingMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ZAdjustPerLevel;
    
    UMiniMapPanel();
};

