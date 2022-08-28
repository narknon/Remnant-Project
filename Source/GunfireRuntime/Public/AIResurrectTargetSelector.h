#pragma once
#include "CoreMinimal.h"
#include "AITargetSelector.h"
#include "AIResurrectTargetSelector.generated.h"

UCLASS(Blueprintable)
class UAIResurrectTargetSelector : public UAITargetSelector {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RequireTag;
    
public:
    UAIResurrectTargetSelector();
};

