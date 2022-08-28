#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnFilterManager.generated.h"

class USpawnFilter;
class UObject;
class USpawnFilterManager;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USpawnFilterManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<USpawnFilter*> ActiveSpawnFilters;
    
public:
    USpawnFilterManager();
    UFUNCTION(BlueprintCallable)
    static void SetSpawnFilter(const UObject* WorldContextObject, USpawnFilter* SpawnFilter);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveSpawnFilter(const UObject* WorldContextObject, USpawnFilter* SpawnFilter);
    
    UFUNCTION(BlueprintCallable)
    static USpawnFilterManager* GetInstance(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void ClearAllSpawnFilters(const UObject* WorldContextObject);
    
};

