#pragma once
#include "CoreMinimal.h"
#include "ENavAreaFlag.generated.h"

UENUM(BlueprintType)
namespace ENavAreaFlag {
    enum Type {
        Default,
        Jump,
        Vault,
        Fall,
        VaultOn,
        Custom1,
        Custom2,
        Custom3,
        Custom4,
    };
}

