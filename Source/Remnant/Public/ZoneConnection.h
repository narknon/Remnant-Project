#pragma once
#include "CoreMinimal.h"
#include "TileCoord.h"
#include "ZoneConnection.generated.h"

USTRUCT(BlueprintType)
struct REMNANT_API FZoneConnection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FromZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTileCoord FromCoord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ToZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTileCoord ToCoord;
    
    FZoneConnection();
};

