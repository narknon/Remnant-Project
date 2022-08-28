#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TraitInfo.generated.h"

class UTrait;

USTRUCT(BlueprintType)
struct FTraitInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTrait> TraitBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTrait* TraitInstance;
    
    GUNFIRERUNTIME_API FTraitInfo();
};

