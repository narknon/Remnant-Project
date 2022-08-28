#pragma once
#include "CoreMinimal.h"
#include "OnAffectCharacterDelegateDelegate.generated.h"

class ACharacter;
class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAffectCharacterDelegate, ACharacter*, Character, AActor*, BoundsActor);

