#pragma once
#include "CoreMinimal.h"
#include "NamedActorDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNamedActorDelegate, AActor*, Actor);

