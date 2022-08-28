#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/GameMode.h"
#include "DamageEventDelegateDelegate.h"
#include "ShutdownEventDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "GameModeGunfire.generated.h"

class UImpactDirection;
class APlayerController;
class ULevelStreaming;
class APlayableLevelCollection;
class AGameRules;
class UObject;
class APlayableLevel;
class AActor;
class UDamageTypeGunfire;

UCLASS(Blueprintable, NonTransient)
class GUNFIRERUNTIME_API AGameModeGunfire : public AGameMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnNotifyHit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnNotifyDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShutdownEventDelegate OnGameShutdown;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGameRules> GameRulesClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> AssetReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AGameRules* GameRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<APlayableLevelCollection>> LevelCollectionsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<APlayableLevelCollection*> LevelCollections;
    
public:
    AGameModeGunfire();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void RemoveLevelInstanceByName(const FString& UniqueInstanceName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void RemoveLevelInstance(ULevelStreaming* LevelInstance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPlayerDied(APlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    APlayableLevelCollection* GetPlayableLevelCollection(const FName& CollectionName);
    
    UFUNCTION(BlueprintCallable)
    APlayableLevel* GetPlayableLevelByPath(const FString& Path, const FName& CollectionName);
    
    UFUNCTION(BlueprintCallable)
    APlayableLevel* GetPlayableLevelByName(const FString& Name, const FName& CollectionName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLevelInstance(const FString& UniqueInstanceName, ULevelStreaming*& LevelInstance) const;
    
    UFUNCTION(BlueprintCallable)
    void ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, TSubclassOf<UDamageTypeGunfire> DamageType, TSubclassOf<UImpactDirection> ImpactDirection);
    
    UFUNCTION(BlueprintCallable)
    void AddPlayableLevel(APlayableLevel* Level, const FName& CollectionName);
    
    UFUNCTION(BlueprintCallable)
    void AddLevelInstance(const FString& UniqueInstanceName, const FString& PackageNameToLoad, const FTransform& LevelTransform, ULevelStreaming*& LevelInstance);
    
};

