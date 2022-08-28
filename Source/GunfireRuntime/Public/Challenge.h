#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ChallengeRank.h"
#include "Challenge.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UChallenge : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Blocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVisibleByDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FChallengeRank> ChallengeRanks;
    
    UChallenge();
};

