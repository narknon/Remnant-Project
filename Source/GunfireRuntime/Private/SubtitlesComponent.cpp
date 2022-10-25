#include "SubtitlesComponent.h"

class USubtitleInstance;
class USoundBase;
class AActor;

void USubtitlesComponent::ServerRemoveSubtitle_Implementation(int32 ID) {
}
bool USubtitlesComponent::ServerRemoveSubtitle_Validate(int32 ID) {
    return true;
}

void USubtitlesComponent::RemoveSubtitle(int32 ID) {
}

void USubtitlesComponent::ClientRemoveSubtitle_Implementation(int32 ID) {
}

void USubtitlesComponent::ClientAddSubtitle_Implementation(const FSubtitleInfo& Info) {
}

USubtitleInstance* USubtitlesComponent::AddSubtitle(AActor* Source, FText Text, TSoftObjectPtr<USoundBase> Audio, FName Emote, bool AutoRemove) {
    return NULL;
}

USubtitlesComponent::USubtitlesComponent() {
}

