#pragma once
#include "CoreMinimal.h"
#include "StatData.h"
#include "Cooldown.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FCooldown : public FStatData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndTime;
    
    FCooldown();
};

