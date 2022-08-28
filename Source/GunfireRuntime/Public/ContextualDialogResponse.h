#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ContextualDialogResponse.generated.h"

USTRUCT(BlueprintType)
struct FContextualDialogResponse : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FollowupTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FollowupTrigger;
    
    GUNFIRERUNTIME_API FContextualDialogResponse();
};

