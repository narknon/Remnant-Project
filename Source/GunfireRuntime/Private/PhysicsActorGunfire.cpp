#include "PhysicsActorGunfire.h"

class UObject;
class UPrimitiveComponent;
class AActor;

void APhysicsActorGunfire::SoundInstanceFinished(UObject* AudioComponent) {
}

void APhysicsActorGunfire::OnHitCallback(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

APhysicsActorGunfire::APhysicsActorGunfire() {
    this->SleepThreshold = 15;
    this->VelocityNoiseFloor = 5.00f;
    this->LowVelocityEncountered = 0;
}

