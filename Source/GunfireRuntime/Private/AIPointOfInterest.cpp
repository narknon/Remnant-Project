#include "AIPointOfInterest.h"

class AActor;

void AAIPointOfInterest::SetEnabled(bool IsEnabled) {
}

bool AAIPointOfInterest::OnValidate_Implementation(AActor* Actor) {
    return false;
}




void AAIPointOfInterest::EndUse() {
}

void AAIPointOfInterest::BeginUse() {
}

AAIPointOfInterest::AAIPointOfInterest() {
    this->Type = NULL;
    this->MinUseTime = -1.00f;
    this->MaxUseTime = -1.00f;
    this->CooldownMin = 5.00f;
    this->CooldownMax = 20.00f;
    this->PatrolPath = NULL;
    this->Occupant = NULL;
    this->Enabled = true;
}

