#include "MapTileInfo.h"
#include "Components/BoxComponent.h"

AMapTileInfo::AMapTileInfo() {
    this->Region = CreateDefaultSubobject<UBoxComponent>(TEXT("Region"));
    this->OriginPointActor = NULL;
}

