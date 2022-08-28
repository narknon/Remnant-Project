#include "RemnantProgressionComponent.h"

void URemnantProgressionComponent::ServerAddExperience_Implementation(int32 Exp) {
}
bool URemnantProgressionComponent::ServerAddExperience_Validate(int32 Exp) {
    return true;
}

void URemnantProgressionComponent::ClientAddProgressionTimeOut() {
}

void URemnantProgressionComponent::AddProtectionTimeOut() {
}

URemnantProgressionComponent::URemnantProgressionComponent() {
    this->MaxValidExperienceOverTime = 20000;
    this->ExpTimeOutSeconds = 60.00f;
}

