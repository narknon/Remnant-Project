#pragma once
#include "CoreMinimal.h"
#include "AITargetSelector.h"
#include "AINearbyPlayerTargetSelector.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAINearbyPlayerTargetSelector : public UAITargetSelector {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CullNotVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPathInvalidTime;
    
public:
    UAINearbyPlayerTargetSelector();
};

