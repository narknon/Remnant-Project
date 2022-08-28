#pragma once
#include "CoreMinimal.h"
#include "AnimNotify_PlayerEffect.h"
#include "AnimNotify_ForceFeedback.generated.h"

class UForceFeedbackEffect;

UCLASS(Blueprintable, CollapseCategories)
class GUNFIRERUNTIME_API UAnimNotify_ForceFeedback : public UAnimNotify_PlayerEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UForceFeedbackEffect* ForceFeedback;
    
    UAnimNotify_ForceFeedback();
};

