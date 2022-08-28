#pragma once
#include "CoreMinimal.h"
#include "CharacterSpawnedEventDelegate.generated.h"

class ACharacterSpawnPoint;
class ACharacterGunfire;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterSpawnedEvent, ACharacterSpawnPoint*, SpawnPoint, ACharacterGunfire*, Character);

