#include "FocusButtonWidget.h"

class UTexture2D;
class UMaterialInstance;

void UFocusButtonWidget::SetTexture(UTexture2D* Texture) {
}

void UFocusButtonWidget::SetMaterial(UMaterialInstance* Material) {
}

void UFocusButtonWidget::SetIsFocusable(bool Focusable) {
}

void UFocusButtonWidget::SetForceFocusVisualState(bool Force) {
}

void UFocusButtonWidget::SetColorAndOpacity(FLinearColor InColorAndOpacity) {
}

void UFocusButtonWidget::SetBackgroundColor(FLinearColor InBackgroundColor) {
}

void UFocusButtonWidget::SetAllowMouseClick(bool IsMouseClickable) {
}

bool UFocusButtonWidget::IsPressed() const {
    return false;
}

bool UFocusButtonWidget::HasInactiveFocus() {
    return false;
}

bool UFocusButtonWidget::HasFocus() {
    return false;
}

FVector2D UFocusButtonWidget::GetAbsoluteCoords() const {
    return FVector2D{};
}

UFocusButtonWidget::UFocusButtonWidget() {
    this->ClickMethod = EButtonClickMethod::DownAndUp;
    this->TouchMethod = EButtonTouchMethod::DownAndUp;
    this->PressMethod = EButtonPressMethod::DownAndUp;
    this->FocusOnMouseEnter = false;
    this->IsFocusable = true;
    this->AutoNavigateFocus = true;
    this->AllowMouseClick = true;
    this->bScrollWithInputAxis = false;
    this->bScrollOnlyWhenFocused = false;
    this->ScrollVelocityPerSecond = 600.00f;
    this->CachedFocusManager = NULL;
}

