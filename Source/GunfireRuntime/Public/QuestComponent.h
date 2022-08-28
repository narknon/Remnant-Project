#pragma once
#include "CoreMinimal.h"
#include "QuestDebugProperty.h"
#include "Components/SceneComponent.h"
#include "QuestActivateDelegateDelegate.h"
#include "EQuestResult.h"
#include "UObject/NoExportTypes.h"
#include "QuestComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UQuestComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bQuestAutoActivate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestActivateDelegate OnQuestActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestActivateDelegate OnQuestDeactivated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FString> Errors;
    
public:
    UQuestComponent();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnResetQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnQuestComplete(EQuestResult Result);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostInitializeQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostCreateQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnObjectiveComplete(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnObjectiveActivate(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInitializeQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDeinitializeQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCreateQuest(const FRandomStream& RandomStream);
    
    UFUNCTION(BlueprintCallable)
    bool IsQuestActive();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool HasErrors();
    
    UFUNCTION(BlueprintCallable)
    void GetDebugProperties(TArray<FQuestDebugProperty>& Properties);
    
    UFUNCTION(BlueprintCallable)
    FString GetDebugLabel();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DeactivateQuest();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ActivateQuest();
    
};

