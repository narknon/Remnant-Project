#pragma once
#include "CoreMinimal.h"
#include "ReplicatedTrace.h"
#include "ReplicatedHit.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedHit : public FReplicatedTrace {
    GENERATED_BODY()
public:
    GUNFIRERUNTIME_API FReplicatedHit();
};

