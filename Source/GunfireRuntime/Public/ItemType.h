#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EItemQuerySortMethod.h"
#include "UObject/Object.h"
#include "ItemQueryResult.h"
#include "ItemQueryFilter.h"
#include "ItemType.generated.h"

class AActor;
class UItemType;
class UStats;
class UInventoryComponent;
class UTexture2D;

UCLASS(Abstract, Blueprintable, Const)
class GUNFIRERUNTIME_API UItemType : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> BaseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStats> ItemStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStats> CharacterStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> AdditionalTypes;
    
    UItemType();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    static TArray<FItemQueryResult> QueryRelevantItems(const TArray<UInventoryComponent*>& Inventories, const FItemQueryFilter& Filter, EItemQuerySortMethod SortMethod);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<UInventoryComponent*> GetRelevantInventoriesForType(AActor* Actor, TSubclassOf<UItemType> Type);
    
};

