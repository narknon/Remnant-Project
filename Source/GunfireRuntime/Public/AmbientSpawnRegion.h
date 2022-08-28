#pragma once
#include "CoreMinimal.h"
#include "VisualizableActor.h"
#include "AmbientSpawnRegion.generated.h"

class UAmbientSpawnManager;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AAmbientSpawnRegion : public AVisualizableActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpawnLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpawnTags;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UAmbientSpawnManager* AmbientSpawnManager;
    
public:
    AAmbientSpawnRegion();
};

