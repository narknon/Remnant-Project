#pragma once
#include "CoreMinimal.h"
#include "QuestCompleteDelegateDelegate.h"
#include "RemnantQuestComponent.h"
#include "ERemnantQuestType.h"
#include "EQuestResult.h"
#include "RemnantQuestSubQuest.generated.h"

class UQuestComponent;
class ARemnantQuest;
class AQuest;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestSubQuest : public URemnantQuestComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ARemnantQuest> QuestBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERemnantQuestType QuestType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> QuestTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChanceToSpawn;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 QuestID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestCompleteDelegate OnSubQuestComplete;
    
    URemnantQuestSubQuest();
protected:
    UFUNCTION(BlueprintCallable)
    void SubQuestComplete(AQuest* Quest, EQuestResult Result);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnLinkDeactivated(UQuestComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void OnLinkActivated(UQuestComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetSubQuest();
    
};

