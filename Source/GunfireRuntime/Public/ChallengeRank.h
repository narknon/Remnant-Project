#pragma once
#include "CoreMinimal.h"
#include "ChallengeRank.generated.h"

class UChallengeObjective;
class UChallengeReward;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FChallengeRank {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UChallengeObjective*> Objectives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UChallengeReward*> Rewards;
    
    FChallengeRank();
};

