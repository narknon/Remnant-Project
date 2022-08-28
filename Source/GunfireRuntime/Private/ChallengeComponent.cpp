#include "ChallengeComponent.h"

class AActor;

bool UChallengeComponent::UnlockChallenge(const FName& ChallengeID) {
    return false;
}

bool UChallengeComponent::IsChallengeComplete(const FName& ChallengeID) const {
    return false;
}

void UChallengeComponent::IncrementObjectivesFromActor(const FName& EventType, AActor* Actor) {
}

void UChallengeComponent::IncrementObjectives(const FName& EventType, const FName& Tag) {
}

int32 UChallengeComponent::GetChallengeRank(const FName& ChallengeID) const {
    return 0;
}

UChallengeComponent::UChallengeComponent() {
    this->ListOfAllChallenges = NULL;
}

