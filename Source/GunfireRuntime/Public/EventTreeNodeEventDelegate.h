#pragma once
#include "CoreMinimal.h"
#include "EventTreeNodeEventDelegate.generated.h"

class UEventTreeNode;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEventTreeNodeEvent, UEventTreeNode*, Node, FName, EventName);

