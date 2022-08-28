#pragma once
#include "CoreMinimal.h"
#include "EAlternateLoginType.generated.h"

UENUM(BlueprintType)
enum class EAlternateLoginType : uint8 {
    DEFAULT,
    EPIC_LOGIN_EXTERNAL,
    EPIC_LINK_HEADLESS,
    EPIC_LINK_EXTERNAL,
};

