#include "InteractiveState.h"

UInteractiveState::UInteractiveState() {
    this->InterruptState = TEXT("Default");
    this->InterruptStateOther = TEXT("Default");
    this->Initiator = EInteractiveInitiator::Us;
    this->Anchor = EInteractiveInitiator::Us;
    this->bInitiatorIsSubject = true;
    this->InteractType = EInteractiveType::Action;
    this->AllowHitReactions = true;
    this->AllowDamage = true;
    this->AllowDeath = false;
    this->AllowOtherInteractives = false;
    this->GravityScale = -1.00f;
    this->bConvergeToAnchor = true;
    this->ConvergeTime = 0.25f;
    this->AnchorFaceOtherOnStart = false;
    this->FaceOtherMethod = EAnchorFaceOtherMethod::UseConvergeTime;
    this->AnchorFaceOffset = 0.00f;
    this->DisableNonAnchorCollision = false;
    this->SnapNonAnchorToGround = false;
    this->IgnoreAnchorWhenSnappingToGround = true;
    this->DisableNonAnchorOverlaps = false;
    this->RestoreOtherDefaultMovement = true;
    this->bDisableNonAnchorSpecialCharacterCollision = false;
    this->InteractRange = 100.00f;
    this->InteractRangeZ = 0.00f;
    this->ArcValidationType = EInteractArcValidationType::AngleOnly;
    this->InteractRefAngle = 0.00f;
    this->InteractArc = 180.00f;
    this->PositionArcAngleOffset = 0.00f;
    this->ValidateLOS = false;
    this->ValidateCapsule = false;
    this->CapsuleInflation = 0.00f;
    this->InputWindowStart = 0.00f;
    this->InputWindowEnd = 1000.00f;
    this->InputMashEnable = false;
    this->InputMashStart = 0.50f;
    this->InputMashIncrement = 0.05f;
    this->InputMashDecay = 0.05f;
    this->InputMashSuccessThreshold = 0.80f;
    this->InputMashFailureThreshold = 0.10f;
    this->UIIcon = NULL;
    this->bDrawWhenNotFocus = false;
    this->bShouldDrawWhenOffScreen = true;
}

