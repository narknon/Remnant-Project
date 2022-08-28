#pragma once
#include "CoreMinimal.h"
#include "UIActor.h"
#include "EDialogTravelLock.h"
#include "RemnantUIActor.generated.h"

UCLASS(Blueprintable)
class REMNANT_API ARemnantUIActor : public AUIActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDialogTravelLock TravelLock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowedDuringTravel;
    
    ARemnantUIActor();
};

