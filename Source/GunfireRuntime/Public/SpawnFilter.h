#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterEntry.h"
#include "SpawnFilter.generated.h"

class USpawnFilterElement;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API USpawnFilter : public USpawnFilterEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<USpawnFilterElement*> FilterEntries;
    
    USpawnFilter();
};

