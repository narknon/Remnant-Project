#include "VariableComponent.h"

class UObject;

void UVariableComponent::SetVariableObject(const FName& NameID, UObject* Value, float Expiration) {
}

void UVariableComponent::SetVariableNumber(const FName& NameID, float Value, float Expiration) {
}

void UVariableComponent::SetVariableName(const FName& NameID, FName Value, float Expiration) {
}

void UVariableComponent::SetVariableBool(const FName& NameID, bool Value, float Expiration) {
}

UObject* UVariableComponent::GetVariableObject(const FName& NameID) {
    return NULL;
}

float UVariableComponent::GetVariableNumber(const FName& NameID) {
    return 0.0f;
}

bool UVariableComponent::GetVariableBool(const FName& NameID) {
    return false;
}

UVariableComponent::UVariableComponent() {
    this->Variables = NULL;
}

