#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "IngredientInfo.generated.h"

class AItem;

USTRUCT(BlueprintType)
struct FIngredientInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> ItemBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredQuantity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredLevel;
    
    GUNFIRERUNTIME_API FIngredientInfo();
};

