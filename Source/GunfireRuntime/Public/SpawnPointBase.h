#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "SpawnPointBase.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API ASpawnPointBase : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpawnState;
    
    ASpawnPointBase();
    UFUNCTION(BlueprintCallable)
    void Warp(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    AActor* SpawnActor(TSubclassOf<AActor> ActorClass, bool SpawnInRoot);
    
    UFUNCTION(BlueprintCallable)
    void QueueSpawnActor(TSubclassOf<AActor> ActorClass, AActor* OwningActor, bool SpawnInRoot);
    
    UFUNCTION(BlueprintCallable)
    void PreSpawn(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void PostSpawn(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPreSpawn(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostSpawn(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NotifySpawnComplete(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void FinishSpawn(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    AActor* BeginSpawn(AActor* OwningActor, TSubclassOf<AActor> ActorClass, bool SpawnInRoot);
    
};

