#pragma once
#include "CoreMinimal.h"
#include "TileBase.h"
#include "Tile.generated.h"

class AMapTileTemplate;
class ULevel;
class ULevelStreaming;
class UTileSet;
class UTileInfo;
class ATileLOD;
class AMapTileInfo;
class AMapTileEdge;

USTRUCT(BlueprintType)
struct FTile : public FTileBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelStreaming* Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevel* LoadedLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMapTileTemplate* Template;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTileSet* TileSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTileInfo* TileInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATileLOD* TileLOD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMapTileInfo* MapTileInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AMapTileEdge*> TileEdges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> AdjacentTiles;
    
    GUNFIRERUNTIME_API FTile();
};

