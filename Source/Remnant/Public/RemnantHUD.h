#pragma once
#include "CoreMinimal.h"
#include "UIHud.h"
#include "RemnantHUD.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class REMNANT_API ARemnantHUD : public AUIHud {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ContextActor;
    
    ARemnantHUD();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldShowSubtitles() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldShowHealthBars() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopPendingTravel();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartPendingTravel();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInvalidDialog() const;
    
};

