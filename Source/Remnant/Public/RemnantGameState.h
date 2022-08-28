#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameStateGunfire.h"
#include "FinishTravelEventDelegate.h"
#include "OnZoneTravelStateChangedDelegate.h"
#include "ZoneTravelState.h"
#include "EZoneTravelLock.h"
#include "RemnantGameState.generated.h"

class AActor;
class ACheckpoint;
class URemnantPingManager;
class URemnantSpawnFilterManager;
class UObject;

UCLASS(Blueprintable)
class REMNANT_API ARemnantGameState : public AGameStateGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bTestMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelCountdownAdditionalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Replicated, Transient, meta=(AllowPrivateAccess=true))
    URemnantPingManager* PingManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URemnantPingManager> PingManagerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URemnantSpawnFilterManager* SpawnFilterManager;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnZoneTravelStateChanged OnZoneTravelStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFinishTravelEvent OnAllPlayersFinishedTravel;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ZoneTravelState, meta=(AllowPrivateAccess=true))
    FZoneTravelState ZoneTravelState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActivatedCheckpoint, meta=(AllowPrivateAccess=true))
    ACheckpoint* ActivatedCheckpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACheckpoint* DeactivatingCheckpoint;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACheckpoint* PreviouslyActivatingCheckpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TravelCountdownSource;
    
public:
    ARemnantGameState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ZoneTravelState();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ActivatedCheckpoint();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsZoneTravelPending(const UObject* WorldContextObject, float& OutTimeRemaining);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsZoneTravelAvailable(const UObject* WorldContextObject, EZoneTravelLock& OutReason, AActor* Source, bool bIsTravelMenu, float AdditionalDistance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ACheckpoint* GetActivatedCheckpoint(const UObject* WorldContextObject, bool bIncludeDeactivatingCheckpoint);
    
};

