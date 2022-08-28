#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniMapLookupActor.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMiniMapLookupActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MiniMapMeshOutputDirectory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* MeshLookupTable;
    
    AMiniMapLookupActor();
};

