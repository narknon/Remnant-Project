#pragma once
#include "CoreMinimal.h"
#include "TileCoord.h"
#include "TileVisibleDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTileVisibleDelegate, FTileCoord, Coord, bool, Visible);

