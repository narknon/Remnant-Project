#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ChallengeList.generated.h"

class UChallenge;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UChallengeList : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UChallenge*> Challenges;
    
    UChallengeList();
};

