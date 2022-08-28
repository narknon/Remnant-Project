#include "DamageTypeGunfire.h"

UDamageTypeGunfire::UDamageTypeGunfire() {
    this->Power = 1;
    this->DamageMod = 0.00f;
    this->DamageScalar = 1.00f;
    this->KnockBackImpulse = 1.00f;
    this->KnockUpImpulse = 1.00f;
    this->PhysicsImpulse = 30000.00f;
    this->Unblockable = false;
    this->Blockable = true;
    this->NoBlockCounter = false;
    this->Evadable = true;
    this->HitFriendly = false;
    this->Modifiable = true;
    this->FriendlyDamageScalar = 0.25f;
    this->FriendlyDamageScalarOverridesGameScalar = false;
    this->OnlyHitBreakable = false;
    this->bAllowCriticalHits = true;
    this->TrailFX = NULL;
    this->TracerBP = NULL;
    this->SoundRadius = 500.00f;
    this->bApplyBonusSightRangeForEnemies = true;
    this->HitPause = 0.05f;
    this->HitPauseIntensity = 0.00f;
    this->HitPauseEaseInTime = 0.00f;
    this->HitPauseEaseOutTime = 0.00f;
    this->ForceFeedback = NULL;
    this->HapticEffect = NULL;
    this->CameraShake = NULL;
    this->Action = NULL;
    this->Visibility = EDamageNumbersVisibility::Shown;
    this->bOverrideVisuals = false;
    this->bOverrideCriticalVisuals = false;
    this->bOverrideWeakSpotVisuals = false;
}

