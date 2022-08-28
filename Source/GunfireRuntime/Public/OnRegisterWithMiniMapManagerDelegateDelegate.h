#pragma once
#include "CoreMinimal.h"
#include "OnRegisterWithMiniMapManagerDelegateDelegate.generated.h"

class AActor;
class UMiniMapComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRegisterWithMiniMapManagerDelegate, AActor*, Actor, UMiniMapComponent*, MiniMapComponent);

