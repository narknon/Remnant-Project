#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode.h"
#include "EventTreeNode_SetVariable.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_SetVariable : public UEventTreeNode {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ContextActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VariableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Value;
    
public:
    UEventTreeNode_SetVariable();
};

