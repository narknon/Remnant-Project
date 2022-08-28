#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "ActorVisual.generated.h"

UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class GUNFIRERUNTIME_API UActorVisual : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RequiredID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HardReferenceAssets;
    
    UActorVisual();
    
    // Fix for true pure virtual functions not being implemented
};

