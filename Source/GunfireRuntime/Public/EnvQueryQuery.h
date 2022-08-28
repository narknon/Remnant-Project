#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvQueryQuery.generated.h"

class UEnvQuery;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FEnvQueryQuery : public FEQSParametrizedQueryExecutionRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEnvQuery* RetestQuery;
    
    FEnvQueryQuery();
};

