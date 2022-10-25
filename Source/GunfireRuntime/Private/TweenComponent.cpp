#include "TweenComponent.h"

class AActor;
class USceneComponent;
class ULightComponent;
class UObject;
class UPrimitiveComponent;
class UMaterialInterface;

void UTweenComponent::StopTween(int32 ID) {
}

void UTweenComponent::StopAllTweens() {
}

int32 UTweenComponent::SetLightIntensity(float Intensity, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::SetComponentLightIntensity(ULightComponent* Component, float Intensity, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::ScaleComponent(USceneComponent* Component, const FVector& NewScale, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::Scale(const FVector& NewScale, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::RotateComponent(USceneComponent* Component, const FRotator& TargetRotation, float Time, EEaseType EaseType, float Exponent, bool bRotateRelative) {
    return 0;
}

int32 UTweenComponent::Rotate(const FRotator& TargetRotation, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::MoveToTarget(AActor* Target, float Time, ETweenRoot Root, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::MoveRelative(const FVector& Offset, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::MoveComponent(USceneComponent* Component, const FVector& Destination, float Time, EEaseType EaseType, float Exponent, bool bMoveRelative) {
    return 0;
}

int32 UTweenComponent::MoveBezier(const FVector& ControlPt1, const FVector& Destination, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::Move(const FVector& Destination, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

bool UTweenComponent::IsTweenComplete(int32 ID) {
    return false;
}

float UTweenComponent::GetElapsedTime(int32 ID, bool bIsNormalized) const {
    return 0.0f;
}

int32 UTweenComponent::AnimateVectorProperty(UObject* Object, FName PropertyName, const FVector& from, const FVector& to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimateVector4Property(UObject* Object, FName PropertyName, const FVector4& from, const FVector4& to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimateRotatorProperty(UObject* Object, FName PropertyName, const FRotator& from, const FRotator& to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimatePrimitiveComponentMaterialVectorParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& Param, FVector from, FVector to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimatePrimitiveComponentMaterialScalarParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& Param, float from, float to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimateMaterialVectorParamGlobal(UMaterialInterface* Material, const FName& Param, FVector from, FVector to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimateMaterialVectorParam(const FName& ComponentName, UMaterialInterface* Material, const FName& Param, FVector from, FVector to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimateMaterialScalarParamGlobal(UMaterialInterface* Material, const FName& Param, float from, float to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimateMaterialScalarParam(const FName& ComponentName, UMaterialInterface* Material, const FName& Param, float from, float to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

int32 UTweenComponent::AnimateFloatProperty(UObject* Object, FName PropertyName, float from, float to, float Time, EEaseType EaseType, float Exponent) {
    return 0;
}

UTweenComponent::UTweenComponent() {
}

