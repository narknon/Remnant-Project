#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AccountAward.generated.h"

UCLASS(Abstract, Blueprintable)
class REMNANT_API UAccountAward : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowDuplicates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNotifyOnlyOnInitialAward;
    
    UAccountAward();
};

