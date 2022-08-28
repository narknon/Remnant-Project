#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "EnvQueryTest_GroundMaterial.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_GroundMaterial : public UEnvQueryTest {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ECollisionChannel> TraceChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    UPROPERTY(EditAnywhere)
    TArray<TEnumAsByte<EPhysicalSurface>> ValidSurfaceTypes;
    
public:
    UEnvQueryTest_GroundMaterial();
};

