#include "SoundSetComponent.h"

class USoundBase;
class USoundCue;

void USoundSetComponent::RemoveSoundTag(FName SoundTag) {
}

void USoundSetComponent::PlaySound2D(FName SoundIDName, float VolumeMultiplier, float PitchMultiplier) {
}

void USoundSetComponent::PlaySound(FName SoundIDName, float VolumeMultiplier, float PitchMultiplier, bool bAttach, FName SocketName) {
}

bool USoundSetComponent::HasSoundTag(FName SoundTag) const {
    return false;
}

TArray<FName> USoundSetComponent::GetSoundTags() {
    return TArray<FName>();
}

TSoftObjectPtr<USoundBase> USoundSetComponent::GetSoundSoft(FName SoundIDName) {
    return NULL;
}

USoundCue* USoundSetComponent::GetSoundCue(FName SoundIDName) {
    return NULL;
}

USoundBase* USoundSetComponent::GetSound(FName SoundIDName) {
    return NULL;
}

void USoundSetComponent::AddUniqueSoundTag(FName SoundTag) {
}

USoundSetComponent::USoundSetComponent() {
    this->SoundSet = NULL;
    this->MeshComp = NULL;
}

