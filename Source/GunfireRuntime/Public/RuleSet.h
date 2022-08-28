#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RuleSet.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API URuleSet : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* RulesTable;
    
    URuleSet();
};

