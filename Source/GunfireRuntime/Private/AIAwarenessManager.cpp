#include "AIAwarenessManager.h"

class AActor;
class UObject;
class UAIAwarenessManager;

void UAIAwarenessManager::SendAwarenessSignalSegment(EAwarenessSignal Type, AActor* Source, const FVector& from, const FVector& to, float Radius) {
}

void UAIAwarenessManager::SendAwarenessSignal(EAwarenessSignal Type, AActor* Source, const FVector& Position, float Radius, bool UseSourceForLastKnownPosition, bool bApplySightRangeBonus) {
}

UAIAwarenessManager* UAIAwarenessManager::GetInstance(UObject* WorldContextObject) {
    return NULL;
}

UAIAwarenessManager::UAIAwarenessManager() {
    this->MaxUpdatesPerFrame = 2;
    this->bShouldUpdateAwareness = true;
}

