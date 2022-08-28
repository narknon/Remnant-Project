#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapTileEdge.generated.h"

class AMapTileInfo;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMapTileEdge : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapTileInfo* Tile;
    
    AMapTileEdge();
};

