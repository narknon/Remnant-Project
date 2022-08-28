#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VariableInfo.h"
#include "Variables.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UVariables : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVariableInfo> Variables;
    
    UVariables();
};

