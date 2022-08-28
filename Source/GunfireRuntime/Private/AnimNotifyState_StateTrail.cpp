#include "AnimNotifyState_StateTrail.h"

UAnimNotifyState_StateTrail::UAnimNotifyState_StateTrail() {
    this->bIsStateTransient = true;
    this->bSoftDestroy = true;
    this->OptimizationType = ENotifyOptimizationType::Queued;
    this->bShowInPreview = true;
}

