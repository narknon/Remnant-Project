#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RemnantGameType.generated.h"

UCLASS(Blueprintable)
class REMNANT_API URemnantGameType : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    URemnantGameType();
};

