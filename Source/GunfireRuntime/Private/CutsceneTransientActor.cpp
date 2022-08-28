#include "CutsceneTransientActor.h"

void ACutsceneTransientActor::OnLevelSequence(bool Start, const TArray<FName>& SequenceTags) {
}

void ACutsceneTransientActor::OnCinematic_Implementation(bool IsPlaying, const TArray<FName>& SequenceTags) {
}

void ACutsceneTransientActor::ForceCutscene(const TArray<FName>& SequenceTags, bool bIsPlaying) {
}

ACutsceneTransientActor::ACutsceneTransientActor() {
    this->bIsInCutscene = false;
}

