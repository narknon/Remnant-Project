#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DialogOption.h"
#include "EventTreeComponent.h"
#include "DialogVoidDelegateDelegate.h"
#include "DialogEventDelegate.h"
#include "EventTreeStage.h"
#include "EventTreeAttrib.h"
#include "DialogInfo.h"
#include "DialogTokenValuePair.h"
#include "DamageInfo.h"
#include "DialogComponent.generated.h"

class UEventTree;
class ADialogStage;
class AActor;
class UDialogInstance;
class UAudioComponent;
class UObject;
class APlayerController;
class UEventTreeAsset;
class AItem;
class UEventTreeNode;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UDialogComponent : public UEventTreeComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEventTree* EventTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoPlayDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableProximityTriggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADialogStage> StageBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADialogStage* Stage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogSetStage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogEvent OnDialogEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnOptionsUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool AllowMultipleSpeakers;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* DialogInitiator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Active, meta=(AllowPrivateAccess=true))
    bool DialogActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Stage, meta=(AllowPrivateAccess=true))
    FEventTreeStage DialogStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Dialog, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeAttrib> DialogAttributes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Dialog, meta=(AllowPrivateAccess=true))
    FDialogInfo Dialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Options, meta=(AllowPrivateAccess=true))
    TArray<FDialogOption> DialogOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FDialogTokenValuePair> TokenValuePairs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* DialogAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> DialogProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDialogInstance* CurrentDialog;
    
public:
    UDialogComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void TokenValueSet(const FName& NameID, const FText& Value);
    
public:
    UFUNCTION(BlueprintCallable)
    void SelectOptionByName(FName OptionName);
    
    UFUNCTION(BlueprintCallable)
    void SelectOption(uint8 OptionID);
    
    UFUNCTION(BlueprintCallable)
    void ResetStageFromCinematic();
    
    UFUNCTION(BlueprintCallable)
    void RemoveDialogProvider(UObject* Provider);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Stage();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Options();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Dialog();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Active();
    
    UFUNCTION(BlueprintCallable)
    void OnInitiatorTakeAnyDamage(const FDamageInfo& Damage);
    
    UFUNCTION(BlueprintCallable)
    void OnDialogFinished(UDialogInstance* Instance);
    
public:
    UFUNCTION(BlueprintCallable)
    void JoinInProgressServer(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void JoinInProgressClient();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasOption(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAttributeValueForStage(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAttributeValueForOption(const FDialogOption& Option, FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAttributeValue(FName Key);
    
    UFUNCTION(BlueprintCallable)
    void HandleEvent(FName EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetTokenReplacedText() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAttributeValueForStage(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAttributeValueForOption(const FDialogOption& Option, FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAttributeValue(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEventTreeAsset* GetAttributeAssetForStage(FName Key);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteTrigger(const FName& TriggerName, AActor* Initiator, bool Push, bool AllowOverrideExistingStack);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteItemTrigger(TSoftClassPtr<AItem> ItemBP, AActor* Initiator);
    
protected:
    UFUNCTION(BlueprintCallable)
    void EventTreeStageEvent(const FEventTreeStage& EventTreeStage);
    
    UFUNCTION(BlueprintCallable)
    void EventTreeNodeEvent(UEventTreeNode* Node, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    void EventEnd();
    
    UFUNCTION(BlueprintCallable)
    void EventBegin();
    
public:
    UFUNCTION(BlueprintCallable)
    void DialogAdvance();
    
    UFUNCTION(BlueprintCallable)
    void BeginDialog(AActor* Initiator);
    
    UFUNCTION(BlueprintCallable)
    void AddDialogProvider(UObject* Provider);
    
};

