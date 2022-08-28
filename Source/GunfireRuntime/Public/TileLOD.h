#pragma once
#include "CoreMinimal.h"
#include "ETileLODType.h"
#include "Engine/LODActor.h"
#include "TileLOD.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ATileLOD : public ALODActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LODDrawDistanceOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* DistantLOD;
    
    ATileLOD();
    UFUNCTION(BlueprintCallable)
    void SetLODOverride(ETileLODType LODType);
    
};

