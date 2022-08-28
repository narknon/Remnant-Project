#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterEntry.h"
#include "SpawnFilterList.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API USpawnFilterList : public USpawnFilterEntry {
    GENERATED_BODY()
public:
    USpawnFilterList();
};

