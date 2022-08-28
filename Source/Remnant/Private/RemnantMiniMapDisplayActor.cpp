#include "RemnantMiniMapDisplayActor.h"
#include "RemnantFogOfWarComponent.h"

void ARemnantMiniMapDisplayActor::OnFogOfWarChanged(int32 X, int32 Y) {
}

bool ARemnantMiniMapDisplayActor::IsAnyMiniMapDisplayed() {
    return false;
}

ARemnantMiniMapDisplayActor::ARemnantMiniMapDisplayActor() {
    this->FogOfWar = CreateDefaultSubobject<URemnantFogOfWarComponent>(TEXT("FogOfWar"));
}

