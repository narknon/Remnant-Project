#pragma once
#include "CoreMinimal.h"
#include "TraversalCondition.h"
#include "EWaterSurfaceDirection.h"
#include "WaterSurfaceCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UWaterSurfaceCondition : public UTraversalCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWaterSurfaceDirection WaterSurfaceDirection;
    
public:
    UWaterSurfaceCondition();
};

