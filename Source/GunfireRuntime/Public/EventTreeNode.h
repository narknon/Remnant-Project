#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode_Base.h"
#include "EventTreeNode.generated.h"

class UEventTreeComponent;
class APlayerController;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode : public UEventTreeNode_Base {
    GENERATED_BODY()
public:
    UEventTreeNode();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Validate(UEventTreeComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Loop(UEventTreeComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Join(UEventTreeComponent* Component, APlayerController* JoiningController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsComplete(UEventTreeComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void End(UEventTreeComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Begin(UEventTreeComponent* Component);
    
};

