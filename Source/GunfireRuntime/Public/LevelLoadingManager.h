#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelInstanceStatus.h"
#include "LevelInstanceInfo.h"
#include "LevelLoadingManager.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API ULevelLoadingManager : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LevelInstanceInfo, meta=(AllowPrivateAccess=true))
    TArray<FLevelInstanceInfo> LevelInstanceInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<int32, FLevelInstanceStatus> LevelInstanceStatus;
    
public:
    ULevelLoadingManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_LevelInstanceInfo();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelUnloaded(int32 LevelID);
    
    UFUNCTION(BlueprintCallable)
    void OnLevelShown(int32 LevelID);
    
    UFUNCTION(BlueprintCallable)
    void OnLevelLoaded(int32 LevelID);
    
    UFUNCTION(BlueprintCallable)
    void OnLevelHidden(int32 LevelID);
    
};

