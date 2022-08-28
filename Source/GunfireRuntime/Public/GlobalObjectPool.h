#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SimplePoolPrecache.h"
#include "UObject/NoExportTypes.h"
#include "GlobalObjectPool.generated.h"

class USingleObjectPool;
class UGlobalObjectPool;
class UWorld;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UGlobalObjectPool : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimplePoolPrecache> StartingPools;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FSoftObjectPath, USingleObjectPool*> Pools;
    
public:
    UGlobalObjectPool();
    UFUNCTION(BlueprintCallable)
    static UGlobalObjectPool* GetInstance(UWorld* World);
    
    UFUNCTION(BlueprintCallable)
    void Empty();
    
};

