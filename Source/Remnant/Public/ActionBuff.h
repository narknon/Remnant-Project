#pragma once
#include "CoreMinimal.h"
#include "ActionBase.h"
#include "ActionBuff.generated.h"

class UActionComponent;
class UVisualComponent;

UCLASS(Blueprintable)
class REMNANT_API UActionBuff : public UActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Persistent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ContextualDialogTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContextualDialogTriggerRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VisualPriority;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UVisualComponent* CachedVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActionComponent* CachedActions;
    
public:
    UActionBuff();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void ResetTimer();
    
    UFUNCTION(BlueprintCallable)
    void PauseDuration(bool Paused);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDurationPaused() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRemainingTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetElapsedTimePct() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetDesiredVisual(FName& Slot, FName& ID);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void ApplyTimerDelta(float DeltaTime);
    
};

