#include "DialogStage.h"

class AActor;
class APlayerController;
class UCameraComponent;

void ADialogStage::SetupStage_Implementation(const FEventTreeStage& Stage) {
}

void ADialogStage::SetCameraByName(FName Name, APlayerController* TargetController) {
}

void ADialogStage::SetCamera(AActor* CameraActor, APlayerController* TargetController) {
}

void ADialogStage::SetActiveCameraComponent(AActor* Actor, UCameraComponent* Camera, APlayerController* TargetController) {
}

void ADialogStage::RestoreCamera(bool ResetToCurrentView, APlayerController* TargetController) {
}

void ADialogStage::PositionActorAtMark(AActor* Actor, FName Mark) {
}

void ADialogStage::PositionActor(AActor* Actor, const FTransform& Transform) {
}

AActor* ADialogStage::GetActor(FName Name) {
    return NULL;
}

void ADialogStage::End_Implementation() {
}

void ADialogStage::Begin_Implementation() {
}

ADialogStage::ADialogStage() {
    this->DialogComponent = NULL;
    this->StageActive = false;
}

