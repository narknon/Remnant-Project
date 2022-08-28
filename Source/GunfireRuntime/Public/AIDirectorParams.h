#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AIDirectorParams.generated.h"

USTRUCT(BlueprintType)
struct FAIDirectorParams : public FTableRowBase {
    GENERATED_BODY()
public:
    GUNFIRERUNTIME_API FAIDirectorParams();
};

