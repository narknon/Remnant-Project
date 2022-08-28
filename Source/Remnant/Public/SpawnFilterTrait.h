#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterElement.h"
#include "SpawnFilterTrait.generated.h"

class UTrait;

UCLASS(Blueprintable)
class REMNANT_API USpawnFilterTrait : public USpawnFilterElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UTrait> TraitToFilter;
    
    USpawnFilterTrait();
};

