#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "MovieSceneSection.h"
#include "UObject/NoExportTypes.h"
#include "Components/AudioComponent.h"
#include "Components/AudioComponent.h"
#include "MovieSceneSoundSetSection.generated.h"

class UDialog_Emote;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UMovieSceneSoundSetSection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SoundIDName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialog_Emote> Emote;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreVocalRange;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid ObjectBindingId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAudioFinished OnSoundSetFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAudioPlaybackPercent OnSoundSetPlaybackPercent;
    
public:
    UMovieSceneSoundSetSection();
};

