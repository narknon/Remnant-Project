#pragma once
#include "CoreMinimal.h"
#include "ChallengeRankInstance.h"
#include "ChallengeInstance.generated.h"

class UChallenge;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FChallengeInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName ChallengeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FChallengeRankInstance> Ranks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UChallenge* Challenge;
    
    FChallengeInstance();
};

