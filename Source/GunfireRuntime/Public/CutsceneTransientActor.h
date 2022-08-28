#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CutsceneTransientActor.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ACutsceneTransientActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInCutscene;
    
public:
    ACutsceneTransientActor();
protected:
    UFUNCTION(BlueprintCallable)
    void OnLevelSequence(bool Start, const TArray<FName>& SequenceTags);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCinematic(bool IsPlaying, const TArray<FName>& SequenceTags);
    
public:
    UFUNCTION(BlueprintCallable)
    void ForceCutscene(const TArray<FName>& SequenceTags, bool bIsPlaying);
    
};

