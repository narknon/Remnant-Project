#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode.h"
#include "EventTreeNode_SetKey.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_SetKey : public UEventTreeNode {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ContextActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Value;
    
public:
    UEventTreeNode_SetKey();
};

