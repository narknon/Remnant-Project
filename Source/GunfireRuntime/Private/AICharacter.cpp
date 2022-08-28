#include "AICharacter.h"
#include "Net/UnrealNetwork.h"

void AAICharacter::OnRep_POIAnimationTag(FName PreviousTag) {
}

void AAICharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAICharacter, POIAnimationTag);
}

AAICharacter::AAICharacter() {
    this->Blackboard = NULL;
    this->SpawnPath = NULL;
    this->PatrolPath = NULL;
    this->PerceptionScalar = 1.00f;
    this->CombatClass = NULL;
}

