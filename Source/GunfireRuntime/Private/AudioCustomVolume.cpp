#include "AudioCustomVolume.h"
#include "Templates/SubclassOf.h"
#include "AmbientAudioComponent.h"
#include "WorldSoundComponent.h"
#include "Components/AudioComponent.h"

class UAudioStateID;

void AAudioCustomVolume::SetState(TSubclassOf<UAudioStateID> StateID, bool bPlayTransitions) {
}

void AAudioCustomVolume::OnEndActiveVolume() {
}

void AAudioCustomVolume::OnBeginActiveVolume() {
}

bool AAudioCustomVolume::IsActiveVolume() const {
    return false;
}

AAudioCustomVolume::AAudioCustomVolume() {
    this->bInfiniteExtent = false;
    this->LevelDepth = 0;
    this->WorldSoundSet = NULL;
    this->AttenShape = EAttenuationShape::Sphere;
    this->MusicSet = NULL;
    this->bOverrideFalloff = false;
    this->FalloffOverride = 200.00f;
    this->CurrentStateID = NULL;
    this->PrimaryAudioComponent = CreateDefaultSubobject<UAmbientAudioComponent>(TEXT("AudioComponent"));
    this->OnEnterAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent_OnEnter"));
    this->OnExitAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent_OnExit"));
    this->WorldSoundComponent = CreateDefaultSubobject<UWorldSoundComponent>(TEXT("WorldSoundComponent"));
}

