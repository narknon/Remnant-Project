#include "CameraState.h"

class UStateCameraComponent;
class AActor;

AActor* UCameraState::ValidateCameraActor_Implementation(UStateCameraComponent* CameraManager, AActor* CameraActor) {
    return NULL;
}




UCameraState::UCameraState() {
    this->FOV = 90.00f;
    this->DefaultBlendTime = 0.10f;
}

