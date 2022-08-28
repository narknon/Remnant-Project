#pragma once
#include "CoreMinimal.h"
#include "CameraState.h"
#include "FixedCameraState.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UFixedCameraState : public UCameraState {
    GENERATED_BODY()
public:
    UFixedCameraState();
};

