#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LegIkEffector.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FLegIkEffector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IkBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Alpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ComponentSpaceTransform;
    
    FLegIkEffector();
};

