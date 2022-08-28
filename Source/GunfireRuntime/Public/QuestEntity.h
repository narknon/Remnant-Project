#pragma once
#include "CoreMinimal.h"
#include "QuestComponent.h"
#include "DialogProviderInterface.h"
#include "QuestActorDelegateDelegate.h"
#include "EQuestEntityOwnerContext.h"
#include "QuestEntityEventTree.h"
#include "QuestNoActorDelegateDelegate.h"
#include "QuestEntity.generated.h"

class UEventTree;
class AQuest;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UQuestEntity : public UQuestComponent, public IDialogProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEventTree* EventTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestEntityOwnerContext OwnerContext;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FQuestEntityEventTree> EventTrees;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestActorDelegate OnSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestNoActorDelegate OnDeSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestActorDelegate OnDestroyed;
    
    UQuestEntity();
    UFUNCTION(BlueprintCallable)
    void StartEventTree(UEventTree* NewEventTree);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpawned() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEventTree(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AQuest* GetQuest() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEventTree* GetEventTreeByID(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetActor() const;
    
    UFUNCTION(BlueprintCallable)
    void EndDialog();
    
    UFUNCTION(BlueprintCallable)
    void DialogTrigger(FName TriggerName, AActor* Initiator, bool Push, bool AllowOverrideExistingStack);
    
    UFUNCTION(BlueprintCallable)
    void BeginDialog(AActor* Initiator);
    
    
    // Fix for true pure virtual functions not being implemented
};

