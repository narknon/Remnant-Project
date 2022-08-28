#include "InputStateComponent.h"

class APlayerController;

void UInputStateComponent::SetWalking(bool InIsWalking) {
}

void UInputStateComponent::SetInputEnabled(bool enable) {
}

void UInputStateComponent::SetButtonStateByName(const FName& Name, ButtonEvent Event) {
}

void UInputStateComponent::ResetButton(FName ButtonName) {
}

void UInputStateComponent::RemoveButtonListener(const FName& Name, const FInputButtonDelegate& Event) {
}

void UInputStateComponent::OnSwitchCamera() {
}

bool UInputStateComponent::IsInputEnabled() const {
    return false;
}

bool UInputStateComponent::IsActionPressed(APlayerController* PlayerController, FName ActionName) {
    return false;
}

bool UInputStateComponent::HasVerticalMoveInput() const {
    return false;
}

bool UInputStateComponent::HasMoveInput() const {
    return false;
}

bool UInputStateComponent::HasHorizontalMoveInput() const {
    return false;
}

FVector UInputStateComponent::GetScreenRelativeMoveInput(FVector Up, bool bAllowSticky, bool bAllowVerticalInput) {
    return FVector{};
}

FVector UInputStateComponent::GetRelativeMoveInput(FRotator Rotation, bool bAllowVerticalInput) {
    return FVector{};
}

void UInputStateComponent::GetMoveInput(FVector& OutMoveInput) {
}

bool UInputStateComponent::GetIsWalking() const {
    return false;
}

bool UInputStateComponent::GetCameraRotation(FRotator& OutCameraRotation, bool bAllowSticky) {
    return false;
}

FVector UInputStateComponent::GetCameraRelativeMoveInput(FVector Up, bool bAllowSticky, bool bAllowVerticalInput) {
    return FVector{};
}

ButtonEvent UInputStateComponent::GetButtonStateByName(const FName& Name) const {
    return ButtonEvent::None;
}

void UInputStateComponent::AddButtonListener(const FName& Name, const FInputButtonDelegate& Event) {
}

UInputStateComponent::UInputStateComponent() {
    this->StickyMovement = false;
    this->StickyMovementThreshold = 1.00f;
    this->MaxWalkingInput = 0.30f;
}

