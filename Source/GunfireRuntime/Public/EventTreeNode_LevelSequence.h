#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode_Branch.h"
#include "MovieSceneSequencePlayer.h"
#include "EventTreeNode_LevelSequence.generated.h"

class UEventTreeComponent;
class ULevelSequence;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_LevelSequence : public UEventTreeNode_Branch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<ULevelSequence> LevelSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SequenceTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HideOtherPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ResetNonMVPs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ResetCameraOnComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowSkipCinematic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DefaultToPlayerCameraOnFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneSequencePlaybackSettings PlaybackSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UEventTreeComponent* StoredComponent;
    
    UEventTreeNode_LevelSequence();
    UFUNCTION(BlueprintCallable)
    void OnSequenceTriggerForEventTree(FName TriggerName);
    
    UFUNCTION(BlueprintCallable)
    void OnSequenceFinishedCallback();
    
};

