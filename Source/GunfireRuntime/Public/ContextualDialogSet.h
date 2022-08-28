#pragma once
#include "CoreMinimal.h"
#include "RuleSet.h"
#include "ContextualDialogSet.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UContextualDialogSet : public URuleSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* Responses;
    
    UContextualDialogSet();
};

