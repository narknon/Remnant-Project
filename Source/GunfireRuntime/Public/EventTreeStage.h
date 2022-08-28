#pragma once
#include "CoreMinimal.h"
#include "EventTreeAttrib.h"
#include "EventTreeStage.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FEventTreeStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyTargetInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeAttrib> Attributes;
    
    FEventTreeStage();
};

