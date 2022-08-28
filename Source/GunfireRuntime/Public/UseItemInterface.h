#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Interface.h"
#include "UseItemInterface.generated.h"

class APlayerControllerGunfire;
class AItem;

UINTERFACE(Blueprintable, MinimalAPI)
class UUseItemInterface : public UInterface {
    GENERATED_BODY()
};

class IUseItemInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UseItem(APlayerControllerGunfire* PlayerController, TSubclassOf<AItem> ItemClass);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanUseItem(APlayerControllerGunfire* PlayerController, TSubclassOf<AItem> ItemClass);
    
};

