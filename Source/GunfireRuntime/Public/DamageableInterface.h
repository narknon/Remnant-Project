#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageInfo.h"
#include "DamageableInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UDamageableInterface : public UInterface {
    GENERATED_BODY()
};

class IDamageableInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FilterIncomingDamage(const FDamageInfo& DamageInfo, FDamageInfo& DamageInfoOut, bool& ShouldApplyDamage);
    
};

