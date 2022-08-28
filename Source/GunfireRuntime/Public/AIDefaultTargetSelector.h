#pragma once
#include "CoreMinimal.h"
#include "AITargetSelector.h"
#include "AIDefaultTargetSelector.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAIDefaultTargetSelector : public UAITargetSelector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CullNotVisibleTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CullNotVisibleTargetsWithNoPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CullNoThreatTargetsWithNoPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WoundedAwarenessScalar;
    
    UAIDefaultTargetSelector();
};

