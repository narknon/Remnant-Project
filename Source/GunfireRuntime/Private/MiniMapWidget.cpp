#include "MiniMapWidget.h"

class AMiniMapDisplayActor;
class AActor;

FWidgetTransform UMiniMapWidget::UpdateMiniMapWidget_Implementation(const FWidgetTransform& InTransform) {
    return FWidgetTransform{};
}

void UMiniMapWidget::UpdateLevelVisibility_Implementation(int32 DisplayLevel, int32 MyLevel) {
}

void UMiniMapWidget::SetDynamicSize(const FVector2D& DynamicSize) {
}

void UMiniMapWidget::SetCullBounds(const FVector2D& CullBounds) {
}


int32 UMiniMapWidget::GetZOrder() const {
    return 0;
}

AActor* UMiniMapWidget::GetMiniMapRefActor() {
    return NULL;
}

AMiniMapDisplayActor* UMiniMapWidget::GetMiniMap() const {
    return NULL;
}

FVector2D UMiniMapWidget::GetDefaultWidgetCullBounds() const {
    return FVector2D{};
}

int32 UMiniMapWidget::GetContext() const {
    return 0;
}

UMiniMapWidget::UMiniMapWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ZOrder = 0;
    this->MiniMap = NULL;
    this->CachedRefActor = NULL;
    this->Context = 0;
}

