#pragma once
#include "CoreMinimal.h"
#include "ActorVisual.h"
#include "VisualMaterialParam.h"
#include "GlobalMaterialVisual.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UGlobalMaterialVisual : public UActorVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVisualMaterialParam Param;
    
    UGlobalMaterialVisual();
};

