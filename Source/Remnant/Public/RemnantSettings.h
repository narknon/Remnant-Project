#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RemnantSettings.generated.h"

class UDamageClass;

UCLASS(Blueprintable, DefaultConfig)
class REMNANT_API URemnantSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float ModPowerSplashScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float ModPowerSplashFromOtherModScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float BonusModPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UDamageClass> ModDamageClass;
    
    URemnantSettings();
};

