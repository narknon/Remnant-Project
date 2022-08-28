#include "MiniMapPanel.h"

UMiniMapPanel::UMiniMapPanel() {
    this->TargetPixelSize = 10.00f;
    this->WidgetScale = 1.00f;
    this->ScalingMethod = EMiniMapPanelScalingMethod::Maxima;
    this->ZAdjustPerLevel = 10;
}

