#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode_List.h"
#include "EventTreeNode_Trigger.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_Trigger : public UEventTreeNode_List {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TriggerName;
    
    UEventTreeNode_Trigger();
};

