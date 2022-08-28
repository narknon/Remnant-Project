#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "SpawnFilterEntry.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API USpawnFilterEntry : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    USpawnFilterEntry();
    
    // Fix for true pure virtual functions not being implemented
};

