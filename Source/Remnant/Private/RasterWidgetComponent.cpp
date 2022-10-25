#include "RasterWidgetComponent.h"

class UMaterialInterface;
class UTexture;
class UPrimitiveComponent;
class UMaterialInstanceDynamic;

UTexture* URasterWidgetComponent::GetWidgetTexture() {
    return NULL;
}

void URasterWidgetComponent::ForceRedraw() {
}

UMaterialInstanceDynamic* URasterWidgetComponent::CreateWidgetMaterial(UPrimitiveComponent* Primitive, UMaterialInterface* SourceMaterial, FName MaterialTextureName, int32 ElementIndex) {
    return NULL;
}

URasterWidgetComponent::URasterWidgetComponent() {
    this->MaterialOverride = NULL;
}

