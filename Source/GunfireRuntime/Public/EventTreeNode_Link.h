#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode.h"
#include "EventTreeNode_Link.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_Link : public UEventTreeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEventTreeNode* LinkedNode;
    
    UEventTreeNode_Link();
};

