#include "DeployableAttributes.h"

FDeployableAttributes::FDeployableAttributes() {
    this->RotateIncrementDegrees = 0.00f;
    this->MinPlaceDistance = 0.00f;
    this->MaxPlaceDistance = 0.00f;
    this->HeightTolerance = 0.00f;
    this->AngleTolerance = 0.00f;
    this->BuilderToUse = NULL;
}

