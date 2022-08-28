#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "OnTraitLevelChangedDelegateDelegate.h"
#include "TraitSlot.h"
#include "TraitInfo.h"
#include "OnTraitDelegateDelegate.h"
#include "OnTraitPointAddedDelegate.h"
#include "TraitsComponent.generated.h"

class UDataTable;
class UProgressionComponent;
class UTrait;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UTraitsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TraitPointsPerLevelTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UTrait>> AvailableTraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTraitSlot> TraitSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultTraitLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_TraitPoints, meta=(AllowPrivateAccess=true))
    int32 TraitPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_TraitPointsSpent, meta=(AllowPrivateAccess=true))
    int32 TraitPointsSpent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitDelegate OnTraitUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitDelegate OnTraitAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitDelegate OnTraitRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitDelegate OnTraitAddFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitLevelChangedDelegate OnTraitLevelChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitPointAdded OnTraitPointAdded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Traits, meta=(AllowPrivateAccess=true))
    TArray<FTraitInfo> Traits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTraitInfo> OldTraits;
    
public:
    UTraitsComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    bool UnlockTrait(TSubclassOf<UTrait> TraitBP, int32 StartingLevel);
    
    UFUNCTION(BlueprintCallable)
    void SetTraitLevel(TSubclassOf<UTrait> TraitBP, int32 NewLevel, bool bAwardTraitPoints);
    
    UFUNCTION(BlueprintCallable)
    void SetAllTraitLevels(int32 NewLevel, bool bAwardTraitPoints);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnlockTrait(TSubclassOf<UTrait> TraitBP, int32 StartingLevel);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Purchase(TSubclassOf<UTrait> TraitBP);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Traits();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TraitPointsSpent();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TraitPoints();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelUp();
    
    UFUNCTION(BlueprintCallable)
    void OnComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTraitByName(const FName& NameID, int32 RequiredLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTrait(TSubclassOf<UTrait> TraitBP, int32 RequiredLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTraitLevel(TSubclassOf<UTrait> TraitBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalTraitLevels() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UProgressionComponent* GetProgression() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTraitInfo> GetAvailableTraits() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAvailableTraitPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTraitInfo> GetAllTraits() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Equip(TSubclassOf<UTrait> TraitBP, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    bool CanPurchase(TSubclassOf<UTrait> TraitBP);
    
    UFUNCTION(BlueprintCallable)
    bool CanEquip(TSubclassOf<UTrait> TraitBP, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void AddTraitPoints(int32 Points);
    
    UFUNCTION(BlueprintCallable)
    bool AddTrait(TSubclassOf<UTrait> TraitBP, int32 Level);
    
};

