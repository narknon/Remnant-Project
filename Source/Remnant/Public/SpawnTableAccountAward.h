#pragma once
#include "CoreMinimal.h"
#include "SpawnTableEntry.h"
#include "EQuestMode.h"
#include "SpawnTableAccountAward.generated.h"

class UAccountAward;

UCLASS(Blueprintable)
class REMNANT_API USpawnTableAccountAward : public USpawnTableEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UAccountAward> Award;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHardcoreOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFilterByRootQuestMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertValidQuestMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestMode ValidQuestMode;
    
    USpawnTableAccountAward();
};

