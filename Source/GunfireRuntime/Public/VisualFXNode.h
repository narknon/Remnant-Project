#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "VisualFXNode.generated.h"

UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class GUNFIRERUNTIME_API UVisualFXNode : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UVisualFXNode();
    
    // Fix for true pure virtual functions not being implemented
};

