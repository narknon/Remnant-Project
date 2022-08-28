#include "AICoordinator.h"

class AActor;
class UObject;
class UAICoordinator;

int32 UAICoordinator::GetWeightForTarget(AActor* Target) {
    return 0;
}

int32 UAICoordinator::GetMaxWeightForTarget(AActor* Target) {
    return 0;
}

UAICoordinator* UAICoordinator::GetAICoordinator(UObject* WorldContextObject) {
    return NULL;
}

UAICoordinator::UAICoordinator() {
    this->FlockingStyle = EFlockingStyle::ClassicMelee;
    this->DefaultCombatClass = NULL;
    this->PlayerCombatClass = NULL;
}

