#pragma once
#include "CoreMinimal.h"
#include "TutorialPromptDelegateDelegate.h"
#include "Components/ActorComponent.h"
#include "TutorialComponent.generated.h"

class UTutorialPrompts;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UTutorialComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTutorialPrompts* TutorialPrompts;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTutorialPromptDelegate OnShowTutorialPrompt;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTutorialPromptDelegate OnHideTutorialPrompt;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTutorialPromptDelegate OnClearTutorialPrompt;
    
    UTutorialComponent();
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void SetTutorialPrompt(const FName& ID, AActor* Actor, float DurationOverride);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void RemoveTutorialPrompt(const FName& ID, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void QueueTutorialPrompt(const FName& ID, AActor* Actor, float DurationOverride);
    
    UFUNCTION(BlueprintCallable)
    bool HasActiveTutorialPrompt(AActor* Actor, FName RequiredID);
    
    UFUNCTION(BlueprintCallable)
    void ClearTutorialPrompts(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreTutorialsEnabled();
    
};

