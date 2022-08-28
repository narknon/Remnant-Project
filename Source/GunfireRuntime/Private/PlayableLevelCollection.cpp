#include "PlayableLevelCollection.h"

class APlayableLevel;

bool APlayableLevelCollection::IsPreloaded() {
    return false;
}

APlayableLevel* APlayableLevelCollection::GetPlayableLevelByPath(const FString& Path) const {
    return NULL;
}

APlayableLevel* APlayableLevelCollection::GetPlayableLevelByName(const FString& Name) const {
    return NULL;
}

void APlayableLevelCollection::ChangeCollectionState(EPlayableLoadState LoadState, EPlayableVisibleState VisibleState) {
}

void APlayableLevelCollection::AddPlayableLevel(APlayableLevel* Level) {
}

APlayableLevelCollection::APlayableLevelCollection() {
}

