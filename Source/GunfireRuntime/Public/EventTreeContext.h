#pragma once
#include "CoreMinimal.h"
#include "EventTreeContext.generated.h"

class UEventTreeNode;
class UBranch;

USTRUCT(BlueprintType)
struct FEventTreeContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEventTreeNode*> Events;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UBranch*> Subroutines;
    
    GUNFIRERUNTIME_API FEventTreeContext();
};

