#include "WeaponBase.h"
#include "Templates/SubclassOf.h"

class AImpactEffect;
class AActor;

float AWeaponBase::GetProcChance() const {
    return 0.0f;
}

TSubclassOf<AImpactEffect> AWeaponBase::GetImpactEffect_Implementation() {
    return NULL;
}

float AWeaponBase::GetAttackSpeed() {
    return 0.0f;
}

void AWeaponBase::ComputeDamage(AActor* Actor, float& Damage, float& AttackRating) {
}

bool AWeaponBase::AttemptProc(float BonusChance) const {
    return false;
}

AWeaponBase::AWeaponBase() {
    this->DamageType = NULL;
    this->ImpactEffect = NULL;
}

