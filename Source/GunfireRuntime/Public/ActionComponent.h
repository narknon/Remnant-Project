#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "OnActionDelegateDelegate.h"
#include "DamageInfo.h"
#include "Engine/EngineTypes.h"
#include "ActionComponent.generated.h"

class UDamageType;
class UActionBase;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UActionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Actions, meta=(AllowPrivateAccess=true))
    TArray<UActionBase*> Actions;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActionDelegate OnActionAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActionDelegate OnActionRemoved;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActionBase*> OldActions;
    
public:
    UActionComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void StopActionByType(TSubclassOf<UActionBase> ActionBP);
    
    UFUNCTION(BlueprintCallable)
    void StopAction(int32 ActionID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Actions();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionTypeRunning(TSubclassOf<UActionBase> ActionBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionRunning(int32 ActionID) const;
    
    UFUNCTION(BlueprintCallable)
    void InvokeEventOnAll(FName EventName);
    
    UFUNCTION(BlueprintCallable)
    void InvokeEvent(TSubclassOf<UActionBase> ActionType, FName EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumActionsOfType(TSubclassOf<UActionBase> ActionBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UActionBase*> GetAllActionsOfType(TSubclassOf<UActionBase> ActionBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActionBase* GetActionOfType(TSubclassOf<UActionBase> ActionBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActionBase* GetActionByID(int32 ID) const;
    
protected:
    UFUNCTION(BlueprintCallable)
    int32 DoActionInternal(UActionBase* Action, const FDamageInfo& DamageInfo, const TArray<FName>& AdditionalTags);
    
public:
    UFUNCTION(BlueprintCallable)
    int32 DoAction(TSubclassOf<UActionBase> Action, AActor* Cause, AActor* Target, FHitResult HitInfo, TSubclassOf<UDamageType> DamageType);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool CanDoActionInternal(TSubclassOf<UActionBase> ActionBP, const FDamageInfo& DamageInfo);
    
};

