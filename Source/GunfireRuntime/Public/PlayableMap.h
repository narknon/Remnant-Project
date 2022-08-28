#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayableMap.generated.h"

class UWorld;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UPlayableMap : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> PersistentLevel;
    
public:
    UPlayableMap();
};

