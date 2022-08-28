#include "ThirdPersonCameraState.h"

UThirdPersonCameraState::UThirdPersonCameraState() {
    this->AimType = ETPSAimType::None;
    this->PitchMin = -70.00f;
    this->PitchMax = 70.00f;
    this->PitchSpeed = 90.00f;
    this->MousePitchSpeedScalar = 1.00f;
    this->PitchMinZoomScale = 0.50f;
    this->PitchMaxZoomScale = 0.50f;
    this->YawSpeed = 360.00f;
    this->MouseYawSpeedScalar = 1.00f;
    this->YawMin = -180.00f;
    this->YawMax = 180.00f;
    this->Distance = 200.00f;
    this->HeightOffset = 500.00f;
    this->LeftRightOffset = 40.00f;
    this->FadeCharacterDistance = 20.00f;
    this->CameraBoneYawInverted = true;
    this->AllowShoulderSwitch = false;
    this->ShoulderSwitchOrientationMemory = 0.65f;
    this->ShoulderSwitchDelay = 0.20f;
    this->AimRealignmentScalar = 1.00f;
    this->OrientTowardsHeading = false;
    this->SwayAdjustSpeed = 1.00f;
    this->SwayPeriodScale = 1.00f;
    this->GamepadCameraInputPower = 3.00f;
    this->GamepadDeadZone = 0.01f;
    this->InputSmooth = 0.10f;
    this->InputSmoothNeutral = 0.02f;
    this->InputDampingX = 1.00f;
    this->InputDampingY = 1.00f;
    this->InputSmoothWhileDamping = 0.01f;
    this->AdhesionStrength = 0.70f;
    this->AdhesionMode = EAdhesionActivateMode::CameraOrMoveInput;
    this->AdhesionBlendTime = 0.10f;
    this->DepthOfFieldStrength = 0.00f;
    this->DepthOfFieldRange = 4000.00f;
    this->DepthOfFieldWeaponType = NULL;
    this->RangedWeaponType = NULL;
    this->bShouldSnapTarget = false;
    this->SnapTargetTime = 0.20f;
    this->FollowTimeAfterSnap = 0.50f;
    this->bIsCrouchCoverCameraState = false;
    this->CoverPitchMinHeightOffset = 300.00f;
    this->CoverPitchMinDistance = 30.00f;
    this->CoverPitchMinLeftRightOffset = 8.00f;
    this->TargetingComponent = NULL;
    this->TargetActor = NULL;
    this->ScopeWidgetInstance = NULL;
    this->ScopedWeapon = NULL;
    this->ScopePostProcess = NULL;
}

