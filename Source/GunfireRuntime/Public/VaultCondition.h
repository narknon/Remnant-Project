#pragma once
#include "CoreMinimal.h"
#include "TraversalCondition.h"
#include "EVaultType.h"
#include "VaultCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UVaultCondition : public UTraversalCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVaultType VaultType;
    
public:
    UVaultCondition();
};

