#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterList.h"
#include "SpawnFilterReplacementList.generated.h"

class USpawnTable;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API USpawnFilterReplacementList : public USpawnFilterList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnItemOnReplacementFail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ReplacementChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpawnTable*> ReplacementTables;
    
    USpawnFilterReplacementList();
};

