#pragma once
#include "CoreMinimal.h"
#include "AITargetSelector.h"
#include "AICharacterNearbyTargetSelector.generated.h"

UCLASS(Blueprintable)
class UAICharacterNearbyTargetSelector : public UAITargetSelector {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RequireTag;
    
public:
    UAICharacterNearbyTargetSelector();
};

