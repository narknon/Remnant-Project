#pragma once
#include "CoreMinimal.h"
#include "QuestManager.h"
#include "QuestManagerQuestDelegateDelegate.h"
#include "ELicensedContent.h"
#include "EQuestMode.h"
#include "RemnantQuestEntry.h"
#include "RemnantQuestManager.generated.h"

class ARemnantQuest;
class AActor;
class UQuestObjective;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestManager : public UQuestManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManagerQuestDelegate OnQuestLoaded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestEntry> RegisteredQuests;
    
public:
    URemnantQuestManager();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FRemnantQuestEntry> SortQuestList(const TArray<FRemnantQuestEntry>& QuestList);
    
    UFUNCTION(BlueprintCallable)
    bool IsQuestValid(ARemnantQuest* Quest, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    TArray<ARemnantQuest*> GetRootQuests();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetRootQuestForSlot(int32 SlotID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRemnantQuestEntry> GetRegisteredRootQuestsForMode(EQuestMode Mode);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRemnantQuestEntry> GetRegisteredRootQuests();
    
    UFUNCTION(BlueprintCallable)
    TArray<FRemnantQuestEntry> GetRegisteredQuests();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRemnantQuestEntry GetRegisteredQuestByID(const FString& QuestID);
    
    UFUNCTION(BlueprintCallable)
    void GetQuestsForActor(AActor* Actor, bool IncludeInjectedQuests, TArray<ARemnantQuest*>& Rtn);
    
    UFUNCTION(BlueprintCallable)
    bool GetLicenseForSoftQuest(TSoftClassPtr<ARemnantQuest> Quest, ELicensedContent& OutLicense);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UQuestObjective* GetCurrentQuestObjective(ARemnantQuest* Quest);
    
    UFUNCTION(BlueprintCallable)
    ARemnantQuest* GetActiveRootQuest();
    
    UFUNCTION(BlueprintCallable)
    void DestroyRootQuest(ARemnantQuest* Quest);
    
    UFUNCTION(BlueprintCallable)
    ARemnantQuest* CreateRootQuest(int32 SlotID, const FString& QuestID, int32 Difficulty);
    
    UFUNCTION(BlueprintCallable)
    void ActivateRootQuest(ARemnantQuest* Quest);
    
};

