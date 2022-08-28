#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "PhysicsBoundsType.generated.h"

UCLASS(Abstract, Blueprintable, Const, MinimalAPI)
class UPhysicsBoundsType : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideWaterSurfaceType;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EPhysicalSurface> WaterSurfaceType;
    
    UPhysicsBoundsType();
};

