#pragma once
#include "CoreMinimal.h"
#include "WaterFXEntry.generated.h"

class USoundBase;
class UParticleSystem;

USTRUCT(BlueprintType)
struct FWaterFXEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VelocityRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SubmergeDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* SFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* VFX;
    
    GUNFIRERUNTIME_API FWaterFXEntry();
};

