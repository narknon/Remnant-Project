#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AITargetSelector.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAITargetSelector : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScoreUnkownTargets;
    
public:
    UAITargetSelector();
};

