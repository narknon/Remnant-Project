#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode.h"
#include "EventTreeNode_RemoveKey.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_RemoveKey : public UEventTreeNode {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ContextActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Key;
    
public:
    UEventTreeNode_RemoveKey();
};

