#pragma once
#include "CoreMinimal.h"
#include "CharacterDiedEventDelegate.generated.h"

class ACharacterSpawnPoint;
class ACharacterGunfire;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterDiedEvent, ACharacterSpawnPoint*, SpawnPoint, ACharacterGunfire*, Character);

