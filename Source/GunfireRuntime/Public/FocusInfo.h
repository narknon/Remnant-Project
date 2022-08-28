#pragma once
#include "CoreMinimal.h"
#include "FocusInfo.generated.h"

class UPanelWidget;
class UFocusButtonWidget;

USTRUCT(BlueprintType)
struct FFocusInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPanelWidget* Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UFocusButtonWidget* Widget;
    
    GUNFIRERUNTIME_API FFocusInfo();
};

