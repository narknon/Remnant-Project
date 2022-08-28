#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "Components/AudioComponent.h"
#include "Components/AudioComponent.h"
#include "MovieSceneSoundSetSectionTemplateData.generated.h"

class UDialog_Emote;

USTRUCT(BlueprintType)
struct FMovieSceneSoundSetSectionTemplateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SoundIDName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialog_Emote> Emote;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreVocalRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatRange SoundSetTimeRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAudioFinished OnSoundSetFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAudioPlaybackPercent OnSoundSetPlaybackPercent;
    
    GUNFIRERUNTIME_API FMovieSceneSoundSetSectionTemplateData();
};

