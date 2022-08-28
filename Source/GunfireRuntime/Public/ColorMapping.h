#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColorMapping.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FColorMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    FColorMapping();
};

