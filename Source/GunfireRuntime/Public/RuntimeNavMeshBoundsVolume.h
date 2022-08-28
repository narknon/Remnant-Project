#pragma once
#include "CoreMinimal.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "UObject/NoExportTypes.h"
#include "RuntimeNavMeshBoundsVolume.generated.h"

UCLASS(Blueprintable, NotPlaceable)
class GUNFIRERUNTIME_API ARuntimeNavMeshBoundsVolume : public ANavMeshBoundsVolume {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBox Bounds;
    
public:
    ARuntimeNavMeshBoundsVolume();
};

