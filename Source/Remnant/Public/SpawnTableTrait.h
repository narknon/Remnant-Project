#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SpawnTableEntry.h"
#include "SpawnTableTrait.generated.h"

class UTrait;

UCLASS(Blueprintable)
class REMNANT_API USpawnTableTrait : public USpawnTableEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTrait> TraitBP;
    
    USpawnTableTrait();
};

