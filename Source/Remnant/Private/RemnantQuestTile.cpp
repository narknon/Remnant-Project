#include "RemnantQuestTile.h"

class AActor;

void URemnantQuestTile::SetTileActive(int32 ID, bool Active) {
}

AActor* URemnantQuestTile::GetZoneLink(FName ZoneLinkNameID) {
    return NULL;
}

FTileCoord URemnantQuestTile::GetTileCoord() {
    return FTileCoord{};
}

bool URemnantQuestTile::GetTileAttribute(FName Key, FMapGenAttribute& Out) {
    return false;
}

URemnantQuestTile::URemnantQuestTile() {
    this->OverrideTileSet = NULL;
    this->Exclusive = true;
    this->Flags = 255;
    this->TileID = 0;
}

