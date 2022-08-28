#include "RemnantMiniMapWidget.h"

void URemnantMiniMapWidget::UpdateWidgetVisibility() {
}

bool URemnantMiniMapWidget::ShouldIgnoreFogOfWar() const {
    return false;
}

void URemnantMiniMapWidget::SetVisibleFromLevel(bool bVisible) {
}

bool URemnantMiniMapWidget::IsWidgetVisible() const {
    return false;
}

URemnantMiniMapWidget::URemnantMiniMapWidget() {
    this->bIgnoreFogOfWar = false;
    this->FogOfWarOffset = 0.45f;
    this->FogOfWarTolerance = 0.15f;
}

