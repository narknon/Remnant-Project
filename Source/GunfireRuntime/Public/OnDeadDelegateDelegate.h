#pragma once
#include "CoreMinimal.h"
#include "OnDeadDelegateDelegate.generated.h"

class ACharacterGunfire;
class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDeadDelegate, uint8, Reason, ACharacterGunfire*, Character, AActor*, Cause);

