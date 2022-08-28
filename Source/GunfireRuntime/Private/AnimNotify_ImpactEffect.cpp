#include "AnimNotify_ImpactEffect.h"

UAnimNotify_ImpactEffect::UAnimNotify_ImpactEffect() {
    this->Type = EAnimImpactType::Foot;
    this->TraceDirection = EAnimImpactTraceDirection::Down;
    this->TraceChannel = ECC_WorldStatic;
    this->TraceDistance = 300.00f;
    this->UpTraceOffset = 0.00f;
    this->PlaySoundAttached = true;
    this->MaxDistance = 3000.00f;
    this->MaxAngleBetweenNormalAndTraceDirection = -1.00f;
    this->bPlayAtAnyWaterSubmergeDepth = false;
    this->bStateTransient = false;
}

