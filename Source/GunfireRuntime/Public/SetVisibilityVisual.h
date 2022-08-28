#pragma once
#include "CoreMinimal.h"
#include "SceneVisual.h"
#include "SetVisibilityVisual.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API USetVisibilityVisual : public USceneVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Visible;
    
    USetVisibilityVisual();
};

