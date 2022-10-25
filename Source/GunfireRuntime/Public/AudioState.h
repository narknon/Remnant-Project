#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Sound/AudioVolume.h"
#include "Sound/AudioVolume.h"
#include "WorldSound.h"
#include "AudioState.generated.h"

class UAudioStateID;
class USoundCue;
class USoundClass;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FAudioState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAudioStateID> StateID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnEnterSoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* PrimarySoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnExitSoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundClass* SoundClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReverbSettings Reverb;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteriorSettings AmbientZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldSound> WorldSounds;
    
    FAudioState();
};

