#pragma once
#include "CoreMinimal.h"
#include "SpawnGenerator.generated.h"

class UEnvQuery;
class ASpawnPoint;

USTRUCT(BlueprintType)
struct FSpawnGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UEnvQuery> EnvironmentQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASpawnPoint> SpawnPointBP;
    
    GUNFIRERUNTIME_API FSpawnGenerator();
};

