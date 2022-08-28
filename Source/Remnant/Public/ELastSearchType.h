#pragma once
#include "CoreMinimal.h"
#include "ELastSearchType.generated.h"

UENUM(BlueprintType)
enum class ELastSearchType : uint8 {
    QuickMatch,
    QuickMatchSurvival,
    Browse,
    BrowseSurvival,
};

