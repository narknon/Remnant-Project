#pragma once
#include "CoreMinimal.h"
#include "ItemGenResult.generated.h"

class AItem;
class UItemInstanceData;

USTRUCT(BlueprintType)
struct FItemGenResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AItem> Item;
    
    UPROPERTY(EditAnywhere)
    uint8 Quantity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UItemInstanceData* InstanceData;
    
    GUNFIRERUNTIME_API FItemGenResult();
};

