#pragma once
#include "CoreMinimal.h"
#include "ReplicatedLocation.h"
#include "ReplicatedTrace.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedTrace : public FReplicatedLocation {
    GENERATED_BODY()
public:
    GUNFIRERUNTIME_API FReplicatedTrace();
};

