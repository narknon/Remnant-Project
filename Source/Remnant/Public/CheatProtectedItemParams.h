#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EOnAddCheatValidationType.h"
#include "CheatProtectedItemParams.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FCheatProtectedItemParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ProtectedType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QuantityTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ValidateOnRemove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ValidateOnAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOnAddCheatValidationType ValidationType;
    
    REMNANT_API FCheatProtectedItemParams();
};

