#pragma once
#include "CoreMinimal.h"
#include "InteractiveInfo.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FInteractiveInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* InteractiveOther;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InteractiveSlave;
    
    UPROPERTY(EditAnywhere)
    uint8 InteractiveState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InteractiveMashValue;
    
    GUNFIRERUNTIME_API FInteractiveInfo();
};

