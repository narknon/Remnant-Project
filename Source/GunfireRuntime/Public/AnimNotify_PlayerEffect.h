#pragma once
#include "CoreMinimal.h"
#include "StateTransientAnimNotify.h"
#include "AnimNotify_PlayerEffect.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories)
class GUNFIRERUNTIME_API UAnimNotify_PlayerEffect : public UStateTransientAnimNotify {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAOE;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreSelf;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStateTransient;
    
public:
    UAnimNotify_PlayerEffect();
};

