#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SequencerPlayerSettings.h"
#include "OnSequenceSkipVoteChangedEventDelegate.h"
#include "OnSequencePlayingEventDelegate.h"
#include "SequencerManager.generated.h"

class UActionBase;
class USequenceInstance;
class UEventTreeComponent;
class ULevelSequence;
class UObject;
class AActor;
class APlayerGunfire;
class USequencerManager;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USequencerManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSequenceSkipVoteChangedEvent OnSkipVoteChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSequencePlayingEvent OnCinematicPlaying;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSequencePlayingEvent OnCinematicStopping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActionBase> PossessedObjectAction;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USequenceInstance*> SequenceInstances;
    
public:
    USequencerManager();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void UpdateSkipStatus(ULevelSequence* InSequence, bool ShouldSkip);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void SkipSequence(ULevelSequence* InSequence);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable, meta=(WorldContext="WorldContextObject"))
    void SetupSequence_Client(UObject* WorldContextObject, ULevelSequence* LevelSequence, FSequencerPlayerSettings LevelSequenceSettings, AActor* Instigator, UEventTreeComponent* SourceComponent);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ProposeToSkip(ULevelSequence* InSequence, APlayerGunfire* Player);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static USequencerManager* GetInstance(UObject* WorldContextObject);
    
};

