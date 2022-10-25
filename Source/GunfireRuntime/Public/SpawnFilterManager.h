#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnFilterManager.generated.h"

class USpawnFilterManager;
class USpawnFilter;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USpawnFilterManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<USpawnFilter*> ActiveSpawnFilters;
    
public:
    USpawnFilterManager();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetSpawnFilter(const UObject* WorldContextObject, USpawnFilter* SpawnFilter);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RemoveSpawnFilter(const UObject* WorldContextObject, USpawnFilter* SpawnFilter);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static USpawnFilterManager* GetInstance(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ClearAllSpawnFilters(const UObject* WorldContextObject);
    
};

