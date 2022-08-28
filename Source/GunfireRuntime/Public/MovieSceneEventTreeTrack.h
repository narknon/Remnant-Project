#pragma once
#include "CoreMinimal.h"
#include "MovieSceneObjectBindingID.h"
#include "Tracks/MovieSceneEventTrack.h"
#include "MovieSceneNameableTrack.h"
#include "EventTreeTrackEventDelegate.h"
#include "MovieSceneEventTreeTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable, MinimalAPI)
class UMovieSceneEventTreeTrack : public UMovieSceneNameableTrack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFireEventsWhenForwards: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFireEventsWhenBackwards: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFireEventsAtPosition EventPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMovieSceneObjectBindingID> EventReceivers;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventTreeTrackEvent OnTrackTriggerNotified;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> Sections;
    
public:
    UMovieSceneEventTreeTrack();
};

