#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpawnedGrenadeRepData.generated.h"

USTRUCT(BlueprintType)
struct FSpawnedGrenadeRepData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* GrenadeItemClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrenadeLifeSpan;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector InitialVelocity;
    
    REMNANT_API FSpawnedGrenadeRepData();
};

