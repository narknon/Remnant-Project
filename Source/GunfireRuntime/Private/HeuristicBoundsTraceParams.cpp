#include "HeuristicBoundsTraceParams.h"

FHeuristicBoundsTraceParams::FHeuristicBoundsTraceParams() {
    this->MinDistance = 0.00f;
    this->MaxDistance = 0.00f;
    this->FieldOfView = 0.00f;
    this->bCheckForLoS = false;
    this->bCheckForHitComponent = false;
    this->TraceChannel = ECC_WorldStatic;
}

