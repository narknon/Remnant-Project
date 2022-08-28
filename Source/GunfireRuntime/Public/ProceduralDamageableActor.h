#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DamageableActor.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "DamageInfo.h"
#include "ProceduralDamageableActor.generated.h"

class UDamageClass;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AProceduralDamageableActor : public ADamageableActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UDamageClass>> TriggerDamageTypes;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> Vertices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> Triangles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearColor> VertexColors;
    
public:
    AProceduralDamageableActor();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTriggerDamageType(const FDamageInfo& DamageInfo, const TArray<TSubclassOf<UDamageClass>> TriggerDamageClasses) const;
    
    UFUNCTION(BlueprintCallable)
    void GetVertices(const UStaticMeshComponent* StaticMeshComponent);
    
    UFUNCTION(BlueprintCallable)
    void GetTriangleIndices(const UStaticMeshComponent* StaticMeshComponent);
    
    UFUNCTION(BlueprintCallable)
    void ApplyRadialVertexColor(const FVector& CenterPoint, const float Radius, const float Falloff);
    
};

