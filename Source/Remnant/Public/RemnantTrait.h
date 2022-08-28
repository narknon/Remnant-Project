#pragma once
#include "CoreMinimal.h"
#include "Trait.h"
#include "RemnantTrait.generated.h"

UCLASS(Blueprintable)
class REMNANT_API URemnantTrait : public UTrait {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredLegacyLevel;
    
    URemnantTrait();
};

