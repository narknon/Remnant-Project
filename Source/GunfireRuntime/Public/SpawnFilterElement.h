#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterEntry.h"
#include "SpawnFilterElement.generated.h"

class USpawnFilterList;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API USpawnFilterElement : public USpawnFilterEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpawnFilterList*> ModifierLists;
    
    USpawnFilterElement();
};

