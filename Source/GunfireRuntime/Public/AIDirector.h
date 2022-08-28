#pragma once
#include "CoreMinimal.h"
#include "EncounterGroupNamedEventDelegate.h"
#include "Components/ActorComponent.h"
#include "AIDirectorParams.h"
#include "EncounterGroupSpawnEventDelegate.h"
#include "EncounterGroupEventDelegate.h"
#include "AIDirectorPlayer.h"
#include "EIntensityState.h"
#include "EncounterGroup.h"
#include "DamageInfo.h"
#include "AIDirector.generated.h"

class UEncounterGroupInstance;
class UEncounterInstance;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAIDirector : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDirectorParams Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterGroupEvent OnGroupAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterGroupEvent OnGroupRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterGroupEvent OnGroupEncounterComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterGroupSpawnEvent OnGroupActorSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterGroupSpawnEvent OnGroupActorDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterGroupNamedEvent OnGroupEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Suspended;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAIDirectorPlayer> Players;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UEncounterGroupInstance*> EncounterGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EIntensityState IntensityState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IntensityTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IntensityMax;
    
public:
    UAIDirector();
    UFUNCTION(BlueprintCallable)
    void Suspend();
    
    UFUNCTION(BlueprintCallable)
    void StopEncounterGroup(UEncounterGroupInstance* EncounterGroup, bool DestroyActiveSpawns);
    
    UFUNCTION(BlueprintCallable)
    UEncounterGroupInstance* StartEncounterGroup(const FEncounterGroup& Group);
    
    UFUNCTION(BlueprintCallable)
    void Resume();
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyHit(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnEncounterEvent(UEncounterInstance* Encounter, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    void OnActorSpawned(UEncounterInstance* Encounter, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorDead(UEncounterInstance* Encounter, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    bool HasActiveSpawns();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAIDirectorDebugState();
    
    UFUNCTION(BlueprintCallable)
    void ClearAllGroups(bool DestroyActiveSpawns);
    
};

