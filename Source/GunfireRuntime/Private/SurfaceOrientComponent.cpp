#include "SurfaceOrientComponent.h"

void USurfaceOrientComponent::SetEnableIK(bool bEnable, bool bReset) {
}

USurfaceOrientComponent::USurfaceOrientComponent() {
    this->ComponentToOrient = TEXT("CharacterMesh0");
    this->LeanLimit = 90.00f;
    this->bIkEnabled = false;
    this->IkGroundOffset = 0.00f;
    this->IkEnableOffset = 0.00f;
    this->TraceStartOffsetOverride = 0.00f;
    this->TraceEndOffsetOverride = 0.00f;
    this->FrameFrequencyOffset = 1;
    this->OrientRoot = NULL;
}

