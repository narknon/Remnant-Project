#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "FactionAffiliationEventDelegate.h"
#include "Components/ActorComponent.h"
#include "DamageInfo.h"
#include "FactionOverride.h"
#include "FactionDamageTracker.h"
#include "EAffiliation.h"
#include "FactionComponent.generated.h"

class UFaction;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UFactionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFactionAffiliationEvent OnFactionAffiliationChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFaction> CachedFaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FFactionOverride> FactionOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFactionDamageTracker> DamageTrackers;
    
public:
    UFactionComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void TakeDamage(const FDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetFactionOverride(TSubclassOf<UFaction> Faction, EAffiliation Affiliation);
    
    UFUNCTION(BlueprintCallable)
    void SetFaction(TSubclassOf<UFaction> NewFaction);
    
    UFUNCTION(BlueprintCallable)
    bool GetFactionOverride(TSubclassOf<UFaction> Faction, EAffiliation& Affiliation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UFaction> GetFaction() const;
    
    UFUNCTION(BlueprintCallable)
    EAffiliation GetAffiliation(AActor* OtherActor);
    
};

