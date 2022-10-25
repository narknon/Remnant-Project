#pragma once
#include "CoreMinimal.h"
#include "WorldResetInterface.h"
#include "Quest.h"
#include "ERemnantQuestType.h"
#include "EQuestMode.h"
#include "ERemnantQuestDebugState.h"
#include "ERemnantQuestRarity.h"
#include "ELicensedContent.h"
#include "UObject/NoExportTypes.h"
#include "ERemnantQuestStatus.h"
#include "QuestVoidDelegateDelegate.h"
#include "ERemnantQuestRewardType.h"
#include "ZoneLinkInfo.h"
#include "RemnantQuest.generated.h"

class UDataTable;
class USpawnTable;
class UPersistenceComponent;
class UPersistenceKeysComponent;
class UWorld;
class URemnantQuestComponent;
class ULevelStreaming;
class ARemnantPlayerController;
class ARemnantCharacter;
class ARemnantQuest;
class UInventoryComponent;

UCLASS(Blueprintable)
class REMNANT_API ARemnantQuest : public AQuest, public IWorldResetInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPersistenceComponent* PersistenceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPersistenceKeysComponent* PersistenceKeysComponent;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERemnantQuestType Type;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERemnantQuestRarity Rarity;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> QuestTags;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ParentQuestTags;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> QuestRewardTags;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxUsageCount;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERemnantQuestDebugState DebugState;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestMode QuestGameMode;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UnlockKey;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELicensedContent RequiredEntitlement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpawnTable*> ResourceCachedSpawns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> Container;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelMin;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Difficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FTimespan PlayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SlotID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ParentQuestID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Status, meta=(AllowPrivateAccess=true))
    ERemnantQuestStatus Status;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BiomeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ItemValueTable;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnQuestLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URemnantQuestComponent* ParentQuestComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LastCheckpointZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    FName LastCheckpointNameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelStreaming* ContainerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Created;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FString, int32> UsageCount;
    
public:
    ARemnantQuest();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Status();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoaded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLastCheckpoint() const;
    
    UFUNCTION(BlueprintCallable)
    void GiveRewardToPlayerController(ARemnantPlayerController* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType, int32 RandomSeed, bool bSkipDuplicates);
    
    UFUNCTION(BlueprintCallable)
    void GiveRewardToPlayer(ARemnantCharacter* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType);
    
    UFUNCTION(BlueprintCallable)
    void GiveReward(USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType, bool bSkipDuplicates);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetRootQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetQuestInventory();
    
    UFUNCTION(BlueprintCallable)
    bool GetObjectQuestValue(UClass* ObjectBP, UPARAM(Ref) int32& ObjectValue, UPARAM(Ref) float& OutSellScalar, int32& OutPickupValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FZoneLinkInfo GetLastCheckpoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetBiomeName();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<FZoneLinkInfo> GetAutoJoinZoneLinks();
    
    UFUNCTION(BlueprintCallable)
    void DeactivateQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddQuestLootTags(UPARAM(Ref) TArray<FName>& LootTags, bool& Rtn);
    
    UFUNCTION(BlueprintCallable)
    void ActivateQuest();
    
    
    // Fix for true pure virtual functions not being implemented
};

