#pragma once
#include "CoreMinimal.h"
#include "MapGenGizmo.h"
#include "MapTileTemplateEdge.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UMapTileTemplateEdge : public UMapGenGizmo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UMapTileTemplateEdge();
};

