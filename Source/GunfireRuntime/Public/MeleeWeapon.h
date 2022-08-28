#pragma once
#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "MeleeWeapon.generated.h"

class UReticule;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMeleeWeapon : public AWeaponBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverridesReticule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UReticule* Reticule;
    
    AMeleeWeapon();
};

