#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActiveWeaponPhantom.h"
#include "WeaponPhantomProvider.generated.h"

class UDamageTypeGunfire;
class AImpactEffect;

USTRUCT(BlueprintType)
struct FWeaponPhantomProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> DefaultDamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> DefaultImpactEffect;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FActiveWeaponPhantom> ActiveWeaponPhantoms;
    
public:
    GUNFIRERUNTIME_API FWeaponPhantomProvider();
};

