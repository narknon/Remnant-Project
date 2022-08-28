#pragma once
#include "CoreMinimal.h"
#include "MiniMapDisplayActor.h"
#include "RemnantMiniMapDisplayActor.generated.h"

class URemnantFogOfWarComponent;

UCLASS(Blueprintable)
class REMNANT_API ARemnantMiniMapDisplayActor : public AMiniMapDisplayActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    URemnantFogOfWarComponent* FogOfWar;
    
    ARemnantMiniMapDisplayActor();
protected:
    UFUNCTION(BlueprintCallable)
    void OnFogOfWarChanged(int32 X, int32 Y);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAnyMiniMapDisplayed();
    
};

