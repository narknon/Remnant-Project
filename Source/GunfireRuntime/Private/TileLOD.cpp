#include "TileLOD.h"
#include "Components/StaticMeshComponent.h"

void ATileLOD::SetLODOverride(ETileLODType LODType) {
}

ATileLOD::ATileLOD() {
    this->LODDrawDistanceOverride = 0.00f;
    this->DistantLOD = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DistanceLODComponent"));
}

