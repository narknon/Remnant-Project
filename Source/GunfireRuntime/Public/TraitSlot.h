#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TraitSlot.generated.h"

class UTraitType;

USTRUCT(BlueprintType)
struct FTraitSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTraitType> Type;
    
    GUNFIRERUNTIME_API FTraitSlot();
};

