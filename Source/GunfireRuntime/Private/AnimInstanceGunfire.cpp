#include "AnimInstanceGunfire.h"

class UAnimInstanceGunfire;
class UStateMachineComponent;
class AActor;

void UAnimInstanceGunfire::UpdateLegIkEffector(const FLegIkEffector& Effector) {
}

void UAnimInstanceGunfire::StopAnimation(FAnimationHandle Handle) {
}

void UAnimInstanceGunfire::SetParentAnimInstance(UAnimInstanceGunfire* AnimInstance) {
}

void UAnimInstanceGunfire::RemoveLegIkEffector(FName IkBone) {
}

void UAnimInstanceGunfire::RemoveChildAnimInstance(UAnimInstanceGunfire* AnimInstance) {
}

void UAnimInstanceGunfire::RemoveAnimationTag(FName AnimTag) {
}

FAnimationHandle UAnimInstanceGunfire::PlayAnimationByID(FName AnimationLayer, FName AnimationID) {
    return FAnimationHandle{};
}

bool UAnimInstanceGunfire::HasAnimationTag(FName AnimTag) const {
    return false;
}

UStateMachineComponent* UAnimInstanceGunfire::GetStateMachine() const {
    return NULL;
}

float UAnimInstanceGunfire::GetMoveInputDir() const {
    return 0.0f;
}

float UAnimInstanceGunfire::GetMoveDir() const {
    return 0.0f;
}

UAnimInstanceGunfire* UAnimInstanceGunfire::GetMasterAnimInstance(AActor* Actor) {
    return NULL;
}

FLegIkEffector UAnimInstanceGunfire::GetLegIkEffector(FName IkBone) const {
    return FLegIkEffector{};
}

float UAnimInstanceGunfire::GetHeading() const {
    return 0.0f;
}

void UAnimInstanceGunfire::GetAimAngles(FName RefBone, float& Yaw, float& Pitch) {
}

void UAnimInstanceGunfire::EnableLookPoses(bool bEnabled) {
}

bool UAnimInstanceGunfire::CompareAngles(float Angle1, float Angle2, float Arc) const {
    return false;
}

bool UAnimInstanceGunfire::AreLookPosesDisabled() const {
    return false;
}

void UAnimInstanceGunfire::AddChildAnimInstance(UAnimInstanceGunfire* AnimInstance) {
}

void UAnimInstanceGunfire::AddAnimationTag(FName AnimTag) {
}

UAnimInstanceGunfire::UAnimInstanceGunfire() {
    this->Speed = 0.00f;
    this->VerticalSpeed = 0.00f;
    this->TurnSpeed = 0.00f;
    this->GroundSlope = 0.00f;
    this->Direction = 0.00f;
    this->InputDirection = 0.00f;
    this->VerticalDirection = 0.00f;
    this->AimYaw = 0.00f;
    this->AimPitch = 0.00f;
    this->AnimationLayers.AddDefaulted(1);
    this->UseVelocityOverride = false;
    this->UseTargetForAim = true;
    this->bAdjustTargetDirectionByMeshOrientation = false;
    this->bCalculateGroundSlope = false;
    this->bClearTimeDilationOnStateChange = false;
    this->OwningPawn = NULL;
    this->OwningCharacter = NULL;
    this->Input = NULL;
    this->ParentAnimInstance = NULL;
    this->CachedStateMachine = NULL;
    this->bDoNotifyTriggerRateOptimizations = true;
    this->bDisableRateOptimizationsDuringCinematics = true;
    this->MinNotifiesPerFrame = 1;
    this->MaxNotifiesPerFrame = 3;
    this->QueuedNotifyFlushThreshold = 100;
    this->DefaultBone = TEXT("null_Spine");
}

