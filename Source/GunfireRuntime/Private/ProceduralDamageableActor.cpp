#include "ProceduralDamageableActor.h"
#include "Templates/SubclassOf.h"

class UDamageClass;
class UStaticMeshComponent;

bool AProceduralDamageableActor::IsTriggerDamageType(const FDamageInfo& DamageInfo, const TArray<TSubclassOf<UDamageClass>> TriggerDamageClasses) const {
    return false;
}

void AProceduralDamageableActor::GetVertices(const UStaticMeshComponent* StaticMeshComponent) {
}

void AProceduralDamageableActor::GetTriangleIndices(const UStaticMeshComponent* StaticMeshComponent) {
}

void AProceduralDamageableActor::ApplyRadialVertexColor(const FVector& CenterPoint, const float Radius, const float Falloff) {
}

AProceduralDamageableActor::AProceduralDamageableActor() {
}

