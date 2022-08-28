#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnPointInfo.h"
#include "UObject/NoExportTypes.h"
#include "SpawnPointData.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ASpawnPointData : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnPointInfo> SpawnPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox BoundingBox;
    
    ASpawnPointData();
};

