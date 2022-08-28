#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterElement.h"
#include "SpawnFilterItem.generated.h"

class AItem;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API USpawnFilterItem : public USpawnFilterElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AItem> ItemToFilter;
    
    USpawnFilterItem();
};

