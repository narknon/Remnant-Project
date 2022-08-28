#pragma once
#include "CoreMinimal.h"
#include "TraversalState.h"
#include "EWaterSurfaceTraversalType.h"
#include "WaterSurfaceState.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UWaterSurfaceState : public UTraversalState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWaterSurfaceTraversalType TraversalType;
    
    UWaterSurfaceState();
};

