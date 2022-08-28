#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterElement.h"
#include "SpawnFilterAccountAward.generated.h"

class UAccountAward;

UCLASS(Blueprintable)
class REMNANT_API USpawnFilterAccountAward : public USpawnFilterElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UAccountAward> AwardToFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldFilterByHardcore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FilterHardcoreAwards;
    
    USpawnFilterAccountAward();
};

