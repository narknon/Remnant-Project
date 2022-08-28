#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode.h"
#include "EventTreeNode_SetMultipleSpeakers.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_SetMultipleSpeakers : public UEventTreeNode {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowed;
    
public:
    UEventTreeNode_SetMultipleSpeakers();
};

