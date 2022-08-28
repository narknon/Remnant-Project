#pragma once
#include "CoreMinimal.h"
#include "EActionType.h"
#include "NodeDisplayData.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FNodeDisplayData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EActionType> ActionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActionText;
    
    FNodeDisplayData();
};

