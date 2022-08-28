#include "PhysicsBoundsUtil.h"
#include "Templates/SubclassOf.h"

class AActor;
class UPhysicsBoundsType;

bool UPhysicsBoundsUtil::IsWaterBounds(AActor* Bounds) {
    return false;
}

TEnumAsByte<EPhysicalSurface> UPhysicsBoundsUtil::GetWaterSurfaceType(TSubclassOf<UPhysicsBoundsType> BoundsType) {
    return SurfaceType_Default;
}

bool UPhysicsBoundsUtil::GetWaterLine(AActor* Bounds, float& OutWaterLine) {
    return false;
}

TSubclassOf<UPhysicsBoundsType> UPhysicsBoundsUtil::GetBoundsType(AActor* Bounds) {
    return NULL;
}

UPhysicsBoundsUtil::UPhysicsBoundsUtil() {
}

