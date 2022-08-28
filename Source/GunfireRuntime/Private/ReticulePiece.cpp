#include "ReticulePiece.h"

UReticulePiece::UReticulePiece() {
    this->Alignment = EReticuleAlignment::Outside;
    this->RadialOffset = 0.00f;
    this->AxisAngle = 0.00f;
    this->PositionScalar = 1.00f;
    this->DrawScale = 1.00f;
    this->DisableMode = EReticulePieceDisableMode::WithConditions;
    this->bLimitToSpreadThreshold = false;
    this->SpreadThreshold = 0.00f;
    this->bLimitToMaxRelativeRange = false;
    this->MaxRelativeRange = 1.00f;
    this->bLimitToCriticalRange = false;
    this->bIsHitIndicator = false;
    this->HitScaleMin = 0.60f;
    this->HitScaleMax = 1.00f;
    this->bForceDrawOnScreen = false;
    this->MinDistanceScale = 0.00f;
    this->MaxDistanceScale = -1.00f;
}

