#pragma once
#include "CoreMinimal.h"
#include "RemnantQuestComponent.h"
#include "QuestTriggerPlayerDelegateDelegate.h"
#include "RemnantQuestTrigger.generated.h"

class ARemnantCharacter;
class AActor;
class AQuestTrigger;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestTrigger : public URemnantQuestComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TriggerNameID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestTriggerPlayerDelegate OnPlayerEnter;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestTriggerPlayerDelegate OnPlayerExit;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AQuestTrigger* Trigger;
    
public:
    URemnantQuestTrigger();
protected:
    UFUNCTION(BlueprintCallable)
    void OnActorRegistered(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AQuestTrigger* GetTrigger();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ARemnantCharacter*> GetPlayersInTrigger();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumPlayersInTrigger();
    
protected:
    UFUNCTION(BlueprintCallable)
    void EventPlayerExit(ARemnantCharacter* Player);
    
    UFUNCTION(BlueprintCallable)
    void EventPlayerEnter(ARemnantCharacter* Player);
    
};

