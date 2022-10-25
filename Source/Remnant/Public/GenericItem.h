#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "SpawnList.h"
#include "GenericItem.generated.h"

class AActor;
class USpawnTable;
class UInventoryComponent;

UCLASS(Blueprintable)
class REMNANT_API AGenericItem : public AItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpawnTable* RandomizedDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpawnTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShareNonItemPickups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CachedSpawnList, meta=(AllowPrivateAccess=true))
    FSpawnList CachedSpawnList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseGeneratedObjectLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseGeneratedObjectIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseGeneratedObjectPickupSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddToInventory;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSaveOnAward;
    
    AGenericItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidatePickupHandled(const FSpawnList& SpawnList, UInventoryComponent* Inventory);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateAddToInventory(const FSpawnList& SpawnList, UInventoryComponent* Inventory);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CachedSpawnList();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishedItemInit(const FSpawnList& DisplayEntry);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HasMaxSpawnsForCharacter(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleAward(const FSpawnList& SpawnList, UInventoryComponent* Inventory, bool bForceNoSharing);
    
};

