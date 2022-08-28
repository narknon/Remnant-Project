#include "TutorialComponent.h"

class AActor;

void UTutorialComponent::SetTutorialPrompt_Implementation(const FName& ID, AActor* Actor, float DurationOverride) {
}

void UTutorialComponent::RemoveTutorialPrompt_Implementation(const FName& ID, AActor* Actor) {
}

void UTutorialComponent::QueueTutorialPrompt_Implementation(const FName& ID, AActor* Actor, float DurationOverride) {
}

bool UTutorialComponent::HasActiveTutorialPrompt(AActor* Actor, FName RequiredID) {
    return false;
}

void UTutorialComponent::ClearTutorialPrompts(AActor* Actor) {
}

bool UTutorialComponent::AreTutorialsEnabled() {
    return false;
}

UTutorialComponent::UTutorialComponent() {
    this->TutorialPrompts = NULL;
}

