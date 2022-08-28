#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "ItemManager.generated.h"

class AItem;
class UObject;
class UItemManager;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UItemManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AItem*> Items;
    
public:
    UItemManager();
    UFUNCTION(BlueprintCallable)
    void GetItemsInRangeByType(const FVector& Position, float Radius, TSoftClassPtr<AItem> Type, TArray<AItem*>& OutItems);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UItemManager* GetInstance(const UObject* WorldContextObject);
    
};

