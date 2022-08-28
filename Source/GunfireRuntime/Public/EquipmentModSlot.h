#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EquipmentModSlot.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FEquipmentModSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> Type;
    
    GUNFIRERUNTIME_API FEquipmentModSlot();
};

