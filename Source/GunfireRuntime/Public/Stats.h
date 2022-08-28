#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StatInfo.h"
#include "Stats.generated.h"

UCLASS(Abstract, Blueprintable, Const, MinimalAPI)
class UStats : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStatInfo> Stats;
    
    UStats();
};

