#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "RemnantQuestEntityInfo.h"
#include "QuestEntity.h"
#include "DamageInfo.h"
#include "EAffiliation.h"
#include "RemnantQuestEntity.generated.h"

class ACharacterGunfire;
class AActor;
class USpawnTable;
class ARemnantQuest;
class UFaction;
class AZoneActor;
class URemnantQuestZone;
class URemnantQuestTile;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestEntity : public UQuestEntity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpawnTable* SpawnTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpawnTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Transient;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceSpawnIfNotFound;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HackGenerateSpawnsIfMissing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PersistDestroyed;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorNameID;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ActorTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpawnTable* LootSpawnTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> LootSpawnTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFaction> Faction;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Actors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestEntityInfo> Spawns;
    
public:
    URemnantQuestEntity();
protected:
    UFUNCTION(BlueprintCallable)
    void ZoneUnloaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetFactionAffiliation(TSubclassOf<UFaction> TargetFaction, EAffiliation Affiliation, bool Propogate);
    
    UFUNCTION(BlueprintCallable)
    void SetFaction(TSubclassOf<UFaction> NewFaction);
    
    UFUNCTION(BlueprintCallable)
    void ResetSpawns();
    
    UFUNCTION(BlueprintCallable)
    void ReactivateSpawns();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSpawnListLoaded();
    
    UFUNCTION()
    void OnDead(uint8 Reason, ACharacterGunfire* Character, AActor* Cause);
    
    UFUNCTION(BlueprintCallable)
    void OnActorRegistered(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorDead(const FDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AZoneActor* GetZone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetRootQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetRemnantQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URemnantQuestZone* GetQuestZone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URemnantQuestTile* GetQuestTile();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumSpawns();
    
    UFUNCTION(BlueprintCallable)
    TArray<AActor*> GetActors();
    
};

