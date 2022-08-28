#pragma once
#include "CoreMinimal.h"
#include "ChallengeRankInstance.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FChallengeRankInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> ObjectiveCounters;
    
    FChallengeRankInstance();
};

