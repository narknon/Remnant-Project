#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RegionNotifyInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class URegionNotifyInterface : public UInterface {
    GENERATED_BODY()
};

class IRegionNotifyInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNotifyRegionEntered(const FName& Region);
    
};

