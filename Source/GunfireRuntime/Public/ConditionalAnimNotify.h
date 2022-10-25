#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Conditions.h"
#include "OptimizableNotifyInterface.h"
#include "ENotifyOptimizationType.h"
#include "ConditionalAnimNotify.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories)
class GUNFIRERUNTIME_API UConditionalAnimNotify : public UAnimNotify, public IOptimizableNotifyInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENotifyOptimizationType OptimizationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowInPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions Conditions;
    
public:
    UConditionalAnimNotify();
    
    // Fix for true pure virtual functions not being implemented
};

