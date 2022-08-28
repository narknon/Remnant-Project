#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "InventoryScalingInfo.generated.h"

class AItem;

USTRUCT(BlueprintType)
struct FInventoryScalingInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> ScaledItemBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ItemAmount;
    
    GUNFIRERUNTIME_API FInventoryScalingInfo();
};

