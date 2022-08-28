#pragma once
#include "CoreMinimal.h"
#include "StateID.generated.h"

USTRUCT(BlueprintType)
struct FStateID {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint16 StateID;
    
    UPROPERTY(EditAnywhere)
    uint16 StateRuntimeID;
    
    GUNFIRERUNTIME_API FStateID();
};

