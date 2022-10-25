#pragma once
#include "CoreMinimal.h"
#include "SpawnFilterManager.h"
#include "RemnantSpawnFilterManager.generated.h"

class URemnantSpawnFilterManager;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantSpawnFilterManager : public USpawnFilterManager {
    GENERATED_BODY()
public:
    URemnantSpawnFilterManager();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URemnantSpawnFilterManager* GetManagerInstance(const UObject* WorldContextObject);
    
};

