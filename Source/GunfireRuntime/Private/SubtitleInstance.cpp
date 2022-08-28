#include "SubtitleInstance.h"

class AActor;

void USubtitleInstance::Remove() {
}

void USubtitleInstance::OnSourceActorDestroyed(AActor* DestroyedActor) {
}

void USubtitleInstance::OnLoaded() {
}

void USubtitleInstance::CompleteAndRemove() {
}

void USubtitleInstance::Complete() {
}

USubtitleInstance::USubtitleInstance() {
    this->Component = NULL;
    this->ID = 0;
    this->Source = NULL;
    this->AutoRemove = false;
    this->AudioComponent = NULL;
    this->Added = false;
    this->Completed = false;
}

