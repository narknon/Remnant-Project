#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SequencerPlayerSettings.h"
#include "LevelSequencePossession.h"
#include "UObject/NoExportTypes.h"
#include "OnSequenceInstanceCompleteEventDelegate.h"
#include "OnSequenceInstanceEventTreeTriggerDelegate.h"
#include "SequenceInstance.generated.h"

class ULevelSequence;
class AActor;
class ULevelSequencePlayer;
class ALevelSequenceActor;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API USequenceInstance : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSequencerPlayerSettings SequenceSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelSequence* CurrentSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelSequencePlayer* CurrentSequencePlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ALevelSequenceActor* CurrentSequenceActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CurrentSequenceInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLevelSequencePossession> CurrentPossessions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform SequenceOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSequenceInstanceCompleteEvent OnInstanceComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSequenceInstanceEventTreeTrigger OnEventTreeSequenceTrigger;
    
    USequenceInstance();
    UFUNCTION(BlueprintCallable)
    void OnFinished();
    
    UFUNCTION(BlueprintCallable)
    void OnEventTreeTrackTriggerNotified(FName TriggerName);
    
};

