#include "MiniMapLevelRegion.h"

class AActor;

bool AMiniMapLevelRegion::IsInRegion(AActor* RefActor, int32 CurrentLevel, float AdditionalZ) const {
    return false;
}

int32 AMiniMapLevelRegion::GetRegionLevel() const {
    return 0;
}

bool AMiniMapLevelRegion::AreConcurrentMiniMapLevels(int32 LevelA, int32 LevelB, bool bCheckBelow, bool bCheckAbove) {
    return false;
}

AMiniMapLevelRegion::AMiniMapLevelRegion() {
    this->RegionType = EMiniMapLevelRegionType::Volume;
    this->MiniMapLevel = 0;
    this->PlaneBuffer = 30.00f;
}

