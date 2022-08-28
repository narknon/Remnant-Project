#pragma once
#include "CoreMinimal.h"
#include "MapGenComponent.h"
#include "ZoneTileDef.h"
#include "RemnantMapGenComponent.generated.h"

class URandomWorld;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantMapGenComponent : public UMapGenComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumZones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoneCoverage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FZoneTileDef> ZoneTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URandomWorld* RandomWorld;
    
public:
    URemnantMapGenComponent();
};

