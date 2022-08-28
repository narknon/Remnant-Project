#pragma once
#include "CoreMinimal.h"
#include "SoundInstanceDelegateDelegate.generated.h"

class UObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSoundInstanceDelegate, UObject*, UPhysicsSoundInstance);

