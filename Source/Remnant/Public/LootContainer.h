#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnLootGeneratedDelegate.h"
#include "SpawnList.h"
#include "LootContainerItem.h"
#include "LootContainer.generated.h"

class USpawnTable;

UCLASS(Blueprintable)
class REMNANT_API ALootContainer : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLootGenerated OnGenerated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnList SpawnList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootContainerItem> Items;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsGenerating;
    
public:
    ALootContainer();
protected:
    UFUNCTION(BlueprintCallable)
    void OnSpawnListLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void Generate(USpawnTable* SpawnTable, const TArray<FName>& SpawnTags);
    
    UFUNCTION(BlueprintCallable)
    void ClearItems();
    
};

