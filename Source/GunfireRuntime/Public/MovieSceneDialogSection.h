#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "MovieSceneSection.h"
#include "UObject/NoExportTypes.h"
#include "Components/AudioComponent.h"
#include "Components/AudioComponent.h"
#include "MovieSceneDialogSection.generated.h"

class UDialog_Emote;
class USoundWave;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UMovieSceneDialogSection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DialogText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundWave* Dialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialog_Emote> Emote;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreVocalRange;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid ObjectBindingId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAudioFinished OnDialogFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAudioPlaybackPercent OnDialogPlaybackPercent;
    
public:
    UMovieSceneDialogSection();
};

