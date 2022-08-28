#pragma once
#include "CoreMinimal.h"
#include "NavAreas/NavArea.h"
#include "ENavAreaFlag.h"
#include "AINavArea.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAINavArea : public UNavArea {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ENavAreaFlag::Type> AreaFlag;
    
public:
    UAINavArea();
};

