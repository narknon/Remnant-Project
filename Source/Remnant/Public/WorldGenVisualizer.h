#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZoneTileDef.h"
#include "WorldGenVisualizer.generated.h"

class URandomWorld;

UCLASS(Blueprintable)
class REMNANT_API AWorldGenVisualizer : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumFeatures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoneCoverage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FZoneTileDef> ZoneTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URandomWorld* World;
    
    AWorldGenVisualizer();
};

