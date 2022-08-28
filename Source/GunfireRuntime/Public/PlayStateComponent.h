#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayStateTransitionedEventDelegate.h"
#include "PlayStateChangedEventDelegate.h"
#include "PlayStateContext.h"
#include "PlayStateComponent.generated.h"

class UPlayState;
class UPlayStateSet;
class APlayerControllerGunfire;
class UPlayStateEffect;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UPlayStateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayStateChangedEvent OnStateChangedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayStateTransitionedEvent OnStateFinishedTransitioning;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayStateSet* StateSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPlayStateContext> ActiveStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UPlayState* CurrentState;
    
public:
    UPlayStateComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerControllerGunfire* GetOwningPlayerController() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetElapsedTransitionTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPlayStateEffect* GetActiveEffect(UClass* Class) const;
    
};

