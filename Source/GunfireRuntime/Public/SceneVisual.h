#pragma once
#include "CoreMinimal.h"
#include "ActorVisual.h"
#include "SceneVisual.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API USceneVisual : public UActorVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Component;
    
    USceneVisual();
};

