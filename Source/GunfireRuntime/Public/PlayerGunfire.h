#pragma once
#include "CoreMinimal.h"
#include "CharacterGunfire.h"
#include "PlayerGunfire.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APlayerGunfire : public ACharacterGunfire {
    GENERATED_BODY()
public:
    APlayerGunfire();
};

