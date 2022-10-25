#include "WeaponPhantomComponent.h"
#include "Templates/SubclassOf.h"

class UShapeComponent;
class UImpactDirection;
class AActor;
class UDamageTypeGunfire;
class AImpactEffect;
class UObject;

void UWeaponPhantomComponent::StopWeaponPhantom(UShapeComponent* Shape) {
}

void UWeaponPhantomComponent::StopAllWeaponPhantoms() {
}

void UWeaponPhantomComponent::StartWeaponPhantom(UShapeComponent* Shape, AActor* Cause, TSubclassOf<UDamageTypeGunfire> DamageType, TSubclassOf<UImpactDirection> ImpactDirection, TSubclassOf<AImpactEffect> ImpactEffect, const FName& EffectBone, EEffectSpawnDirection EffectSpawnDirection, FRotator EffectOrientation, float DamageMod, float DamageScalar, bool Blockable, bool Evadable, int32 PowerOverride, float HitCooldown) {
}

void UWeaponPhantomComponent::SetSuspended(bool bIsSuspended) {
}

void UWeaponPhantomComponent::MarkActorHit(UObject* WorldContextObject, UShapeComponent* Shape, AActor* Actor) {
}

bool UWeaponPhantomComponent::IsSuspended() const {
    return false;
}

bool UWeaponPhantomComponent::HasRecentlyHitActor(UObject* WorldContextObject, UShapeComponent* Shape, AActor* Actor) const {
    return false;
}

bool UWeaponPhantomComponent::HasAnyOverlappingDamageable(TArray<AActor*> IgnoredActors, bool bIgnoreDeadActors) const {
    return false;
}

UWeaponPhantomComponent::UWeaponPhantomComponent() {
    this->DefaultDamageType = NULL;
    this->DefaultImpactEffect = NULL;
    this->DefaultBlockEffect = NULL;
    this->DefaultHitCooldown = -1.00f;
    this->DefaultWeaponDamage = 0.00f;
    this->bSkipLagSupersampling = true;
    this->bSkipEnvironmentHits = true;
    this->bSkipWallChecks = true;
    this->bDoHitPause = false;
    this->bPausePhantomsDuringHitPause = false;
    this->MaxHitPauses = 3;
    this->HitPausePenalty = 0.50f;
}

