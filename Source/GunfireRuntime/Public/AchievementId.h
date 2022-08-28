#pragma once
#include "CoreMinimal.h"
#include "AchievementId.generated.h"

USTRUCT(BlueprintType)
struct FAchievementId {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    GUNFIRERUNTIME_API FAchievementId();
};

