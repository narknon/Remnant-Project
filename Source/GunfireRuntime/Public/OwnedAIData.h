#pragma once
#include "CoreMinimal.h"
#include "OwnedAIData.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FOwnedAIData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint32 OwnerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumTacticalPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FirstTacticalPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumNavLinks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FirstNavLink;
    
    FOwnedAIData();
};

