#pragma once
#include "CoreMinimal.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "PathSharingFilter.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UPathSharingFilter : public UNavigationQueryFilter {
    GENERATED_BODY()
public:
    UPathSharingFilter();
};

