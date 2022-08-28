#include "ProjectileBase.h"
#include "ProjectileMovementComponentGunfire.h"
#include "ReplicatedMovementComponent.h"
#include "Components/AudioComponent.h"
#include "ActionComponent.h"

bool AProjectileBase::ValidateHit_Implementation(const FHitResult& Hit, bool bSimulating) {
    return false;
}

void AProjectileBase::SetMaxLifeTime(float NewMaxLifeTime) {
}

void AProjectileBase::OnStop(const FHitResult& Hit) {
}





void AProjectileBase::OnHit(const FHitResult& Hit) {
}

void AProjectileBase::MulticastStop_Implementation() {
}

void AProjectileBase::MulticastImpactEffect_Implementation(const FReplicatedHit& ReplicatedHit, bool bFinalHit) {
}

bool AProjectileBase::IsSprayHit_Implementation(const FHitResult& Hit) {
    return false;
}

void AProjectileBase::IncrementNumPenetrations() {
}

int32 AProjectileBase::GetNumPenetrations() {
    return 0;
}

AProjectileBase::AProjectileBase() {
    this->Cause = NULL;
    this->MaxLifetime = 10.00f;
    this->Collision = NULL;
    this->ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponentGunfire>(TEXT("ProjectileMovement"));
    this->ProjectileReplication = CreateDefaultSubobject<UReplicatedMovementComponent>(TEXT("ProjectileReplication"));
    this->ActionComp = CreateDefaultSubobject<UActionComponent>(TEXT("Action"));
    this->Loop = CreateDefaultSubobject<UAudioComponent>(TEXT("Loop"));
    this->DestroyAfterImpactEffects = true;
    this->AttachOnHit = false;
    this->AttachIgnoreBones = TEXT("_Head");
    this->TargetCooldownTime = 0.00f;
    this->DestroyBreakables = false;
    this->bActivateNearbyCharacters = true;
    this->AdditionalActivateRadius = 200.00f;
    this->ApplyDamage = false;
    this->DamageScalar = 1.00f;
    this->DamageMod = 0.00f;
    this->DamageType = NULL;
    this->PowerOverride = -1;
    this->Evadable = true;
    this->bPenetrate = false;
    this->MaxPenetrations = 1;
    this->PenetrateDelay = 0.50f;
    this->PenetrationDamageScalarInitial = 0.50f;
    this->PenetrationDamageScalarIncrement = 1.00f;
    this->CameraShake = NULL;
    this->InnerRadius = 0.00f;
    this->OuterRadius = 0.00f;
    this->Falloff = 1.00f;
    this->LoopFadeInDuration = 0.00f;
    this->ImpactSound = NULL;
    this->ImpactEffect = NULL;
    this->ImpactVFX = NULL;
    this->SimulationWorld = NULL;
    this->bIsDamageable = false;
    this->bHasGroupDoneHit = false;
}

