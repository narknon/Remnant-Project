#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EventTreeNodeEventDelegate.h"
#include "DialogVoidDelegateDelegate.h"
#include "EventTreeStageEventDelegate.h"
#include "EventTreeContext.h"
#include "EventTreeStage.h"
#include "EventTreeComponent.generated.h"

class UEventTreeNode;
class UObject;
class UEventTree;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UEventTreeComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventTreeNodeEvent OnNodeEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventTreeStageEvent OnSetStage;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeContext> ExecutionStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeStage> StageStack;
    
public:
    UEventTreeComponent();
    UFUNCTION(BlueprintCallable)
    void Stop();
    
    UFUNCTION(BlueprintCallable)
    void StartTree();
    
    UFUNCTION(BlueprintCallable)
    void SetVariableAsObject(FName Name, UObject* Value);
    
    UFUNCTION(BlueprintCallable)
    void SetVariableAsBool(FName Name, bool Value);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupContextVariables();
    
    UFUNCTION(BlueprintCallable)
    void SetStage(const FEventTreeStage& Stage);
    
    UFUNCTION(BlueprintCallable)
    void PushStage(const FEventTreeStage& Stage);
    
    UFUNCTION(BlueprintCallable)
    void PopStage();
    
    UFUNCTION(BlueprintCallable)
    UEventTreeNode* PeekNextNode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRunning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPendingEvents() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetVariableObject(FName Name);
    
    UFUNCTION(BlueprintCallable)
    UEventTreeNode* GetCurrentNode();
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteTriggerFromEventTree(UEventTree* EventTree, const FName& TriggerName);
    
    UFUNCTION(BlueprintCallable)
    void ExecuteSubroutine(FName Name);
    
    UFUNCTION(BlueprintCallable)
    void Clear(bool ForceComplete);
    
    UFUNCTION(BlueprintCallable)
    void BeginEventTree(UEventTree* EventTree, bool DeferredStart);
    
};

