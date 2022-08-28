#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Interface.h"
#include "DamageInfo.h"
#include "DamageSourceInterface.generated.h"

class UDamageTypeGunfire;

UINTERFACE(Blueprintable, MinimalAPI)
class UDamageSourceInterface : public UInterface {
    GENERATED_BODY()
};

class IDamageSourceInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResolveOwner(const FDamageInfo& In, FDamageInfo& Out);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NotifyHitTarget(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyDamage(UPARAM(Ref) FDamageInfo& Info, bool& Rtn);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<UDamageTypeGunfire> GetDamageType();
    
};

