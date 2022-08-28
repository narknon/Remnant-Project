#include "PhysicsUtil.h"

class UPrimitiveComponent;
class UPhysicalMaterial;
class AActor;

void UPhysicsUtil::RestoreRigidBodies(TArray<FCachedPhysicsComponent>& CachedComponents) {
}

void UPhysicsUtil::ResetOverlaps(UPrimitiveComponent* Component) {
}

UPhysicalMaterial* UPhysicsUtil::GetPhysicsMaterial(UPrimitiveComponent* Component) {
    return NULL;
}

int32 UPhysicsUtil::DisableRigidBodies(AActor* Actor, TArray<FCachedPhysicsComponent>& CachedComponents) {
    return 0;
}

UPhysicsUtil::UPhysicsUtil() {
}

