#include "AIDataGenerationSettings.h"

UAIDataGenerationSettings::UAIDataGenerationSettings() {
    this->TraceChannel = ECC_WorldStatic;
    this->QueryComplexCollision = false;
    this->CoverCheckIncrement = 5.00f;
    this->MinimumCoverWidth = -1.00f;
    this->CoverTestDistance = 100.00f;
    this->LongEdgeLength = 100.00f;
    this->LowCoverHeight = 75.00f;
    this->LowCoverOpenTestDistance = 150.00f;
    this->LowCoverOpenTestHeight = 125.00f;
    this->LowCoverOpenTestSize = -1.00f;
    this->HighCoverHeight = -1.00f;
    this->HighCornerCoverGap = 20.00f;
    this->HighCornerCoverBottom = 10.00f;
    this->MaximumFallDistance = 425.00f;
    this->SpawnGenerators.AddDefaulted(6);
}

