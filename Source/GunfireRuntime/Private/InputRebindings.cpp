#include "InputRebindings.h"

void UInputRebindings::ResetInputRebindings() {
}

void UInputRebindings::RemoveAxisRebinding(const FInputAxisKeyMapping& Axis) {
}

void UInputRebindings::RemoveActionRebinding(const FInputActionKeyMapping& Action) {
}

void UInputRebindings::AddAxisRebinding(const FInputAxisKeyMapping& Axis) {
}

void UInputRebindings::AddActionRebinding(const FInputActionKeyMapping& Action) {
}

UInputRebindings::UInputRebindings() {
    this->ActionRebindings.AddDefaulted(34);
    this->AxisRebindings.AddDefaulted(3);
}

