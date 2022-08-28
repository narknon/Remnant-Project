#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldResetUtil.generated.h"

UCLASS(Blueprintable)
class REMNANT_API UWorldResetUtil : public UObject {
    GENERATED_BODY()
public:
    UWorldResetUtil();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsWorldResetInProgress(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static uint8 GetWorldResetColorIndex();
    
};

