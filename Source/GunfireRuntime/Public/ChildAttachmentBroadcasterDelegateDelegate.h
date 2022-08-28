#pragma once
#include "CoreMinimal.h"
#include "ChildAttachmentBroadcasterDelegateDelegate.generated.h"

class USceneComponent;
class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChildAttachmentBroadcasterDelegate, AActor*, Actor, USceneComponent*, ChildComponent);

