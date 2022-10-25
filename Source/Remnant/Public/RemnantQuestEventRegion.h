#pragma once
#include "CoreMinimal.h"
#include "EventRegionCharacter.h"
#include "EventRegionDelegateDelegate.h"
#include "RemnantQuestComponent.h"
#include "EventRegionPlayerDelegateDelegate.h"
#include "RemnantQuestEventRegion.generated.h"

class UMusicSet;
class AEventRegion;
class AActor;
class ARemnantCharacter;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestEventRegion : public URemnantQuestComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventRegionNameID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventRegionDelegate OnBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventRegionDelegate OnEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventRegionPlayerDelegate OnPlayerEnter;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventRegionPlayerDelegate OnPlayerExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMusicSet* MusicSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideExistingSet;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyAggroGroupToStack;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AEventRegion* EventRegion;
    
public:
    URemnantQuestEventRegion();
    UFUNCTION(BlueprintCallable)
    void SetMusicState(FName MusicState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnActorRegistered(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable)
    void LockEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEventRegionActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsComplete() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ARemnantCharacter*> GetPlayersInRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumPlayersInRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantCharacter* GetFirstPlayerInRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEventRegion* GetEventRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetAggroGroup();
    
protected:
    UFUNCTION(BlueprintCallable)
    void EventPlayerExit(FEventRegionCharacter Player);
    
    UFUNCTION(BlueprintCallable)
    void EventPlayerEnter(FEventRegionCharacter Player);
    
    UFUNCTION(BlueprintCallable)
    void EventOnEnd();
    
    UFUNCTION(BlueprintCallable)
    void EventOnBegin();
    
public:
    UFUNCTION(BlueprintCallable)
    void End();
    
    UFUNCTION(BlueprintCallable)
    void CompleteEvent();
    
    UFUNCTION(BlueprintCallable)
    void Begin();
    
};

