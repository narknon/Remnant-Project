#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "QuestManagerVoidDelegateDelegate.h"
#include "QuestManagerQuestDelegateDelegate.h"
#include "QuestManager.generated.h"

class UEventTreeComponent;
class UQuestManager;
class AQuest;
class ULevel;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UQuestManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManagerVoidDelegate OnQuestsUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManagerQuestDelegate OnQuestObjectivesUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManagerQuestDelegate OnQuestComplete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AQuest*> Quests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 QuestIDGen;
    
public:
    UQuestManager();
    UFUNCTION(BlueprintCallable)
    void SetupQuestVariables(UEventTreeComponent* EventTreeComponent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void NotifyQuestsUpdated();
    
public:
    UFUNCTION(BlueprintCallable)
    static bool NotifyQuestByName(UObject* WorldContextObject, FName QuestNameID, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    AQuest* GetQuestByType(TSubclassOf<AQuest> QuestBP);
    
    UFUNCTION(BlueprintCallable)
    static UQuestManager* GetInstance(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    TArray<AQuest*> FindQuestsInLevel(ULevel* Level);
    
    UFUNCTION(BlueprintCallable)
    AQuest* FindQuestByNameID(FName QuestNameID);
    
    UFUNCTION(BlueprintCallable)
    AQuest* FindQuestByID(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    void DestroyQuest(AQuest* Quest);
    
    UFUNCTION(BlueprintCallable)
    AQuest* AddQuest(TSubclassOf<AQuest> QuestBP, int32 SeedOverride);
    
};

