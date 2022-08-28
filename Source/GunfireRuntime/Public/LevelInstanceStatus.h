#pragma once
#include "CoreMinimal.h"
#include "LevelInstanceStatus.generated.h"

class ULevelInstance;

USTRUCT(BlueprintType)
struct FLevelInstanceStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelInstance* LevelInstance;
    
    GUNFIRERUNTIME_API FLevelInstanceStatus();
};

