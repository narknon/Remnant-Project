#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "VisualSetNode.generated.h"

UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class GUNFIRERUNTIME_API UVisualSetNode : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UVisualSetNode();
    
    // Fix for true pure virtual functions not being implemented
};

