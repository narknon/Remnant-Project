#include "TraversalSettings.h"

UTraversalSettings::UTraversalSettings() {
    this->VaultOverDistance = 200.00f;
    this->VaultUpDistance = 150.00f;
    this->VaultPivotHeight = 100.00f;
    this->VaultPivotOffset = 25.00f;
    this->VaultMinHeight = 35.00f;
    this->VaultMaxHeight = 150.00f;
    this->VaultOpeningSize = 90.00f;
    this->VaultCheckDistance = 150.00f;
    this->VaultMaxSideStep = 45.00f;
    this->VaultCollisionChannel = ECC_GameTraceChannel5;
    this->FacingThreshold = 120.00f;
    this->FeetPlantOffset = 60.00f;
    this->HandPlantOffset = 60.00f;
    this->HandAnimationOffset = -19.50f;
    this->TestWallTraceDistanceDelta = 6.00f;
    this->bUseComplexCollisionWhenTestingForWalls = true;
    this->ValidWallAngleThreshold = 12.50f;
    this->LedgeGrabChannels.AddDefaulted(1);
    this->LedgeGrabStartOffset = 135.00f;
    this->LedgeGrabStopOffset = 185.00f;
    this->LedgeGrabCheckIncrement = 10.00f;
    this->LedgeGrabDistance = 60.00f;
    this->SolidTestWallPointDistance = 20.00f;
    this->InsetTestWallPointDistance = 60.00f;
    this->ClingDistance = 10.00f;
    this->ClingTestWallPointDistance = 9.00f;
    this->ClingHandOffset = 100.00f;
    this->WaterSurfaceAboveOffset = 87.50f;
    this->WaterSurfaceBelowOffset = 47.50f;
    this->WaterSurfaceEntryScaleZ = 0.33f;
    this->WaterSurfaceEntryMinVelocity = 50.00f;
    this->bWaterSurfaceEntryOnEmerge = true;
    this->EmergeAcceleration = 2000.00f;
    this->EmergeFullStrengthDepth = 100.00f;
    this->SubmergeDepth = 87.50f;
    this->SubmergeAcceleration = 2000.00f;
    this->DiveMinDistance = 2000.00f;
    this->DiveCastDistance = 3000.00f;
    this->DiveMinWaterDepth = 500.00f;
}

