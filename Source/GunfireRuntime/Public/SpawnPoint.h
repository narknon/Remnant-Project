#pragma once
#include "CoreMinimal.h"
#include "SpawnPointBase.h"
#include "ESpawnPointType.h"
#include "SpawnPoint.generated.h"

class AActor;
class USceneComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ASpawnPoint : public ASpawnPointBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoRegisterSpawnPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnPointType SpawnPointType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SpawnPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SpawnEndPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpawnTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnMinCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnMaxCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnPointGroundCastDistance;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Busy;
    
public:
    ASpawnPoint();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartPreSpawn(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void StartCoolDown();
    
    UFUNCTION(BlueprintCallable)
    void SetBusy(bool IsBusy);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostEditMove();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCooledDown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetBusy() const;
    
};

