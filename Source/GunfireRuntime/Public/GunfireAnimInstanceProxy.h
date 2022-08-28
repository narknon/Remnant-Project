#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstanceProxy.h"
#include "GunfireAnimInstanceProxy.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FGunfireAnimInstanceProxy : public FAnimInstanceProxy {
    GENERATED_BODY()
public:
    FGunfireAnimInstanceProxy();
};

