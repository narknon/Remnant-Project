#pragma once
#include "CoreMinimal.h"
#include "StateTransientAnimNotify.h"
#include "AnimNotify_TargetConverge.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class GUNFIRERUNTIME_API UAnimNotify_TargetConverge : public UStateTransientAnimNotify {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetConvergeDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetConvergeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetConvergeMaxScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetConvergeDirectionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TargetConvergeOnlyAffectForward;
    
public:
    UAnimNotify_TargetConverge();
};

