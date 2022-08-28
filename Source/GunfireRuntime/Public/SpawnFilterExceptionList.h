#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterList.h"
#include "SpawnFilterExceptionList.generated.h"

class USpawnFilterElement;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API USpawnFilterExceptionList : public USpawnFilterList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpawnFilterElement*> FilterExceptions;
    
    USpawnFilterExceptionList();
};

