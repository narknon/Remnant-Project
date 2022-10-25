#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActiveMusicSet.h"
#include "MusicManager.generated.h"

class UMusicSet;
class UMusicManager;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UMusicManager : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMusicSet* DefaultMusicSet;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CurrentState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FActiveMusicSet> ActiveMusicSets;
    
public:
    UMusicManager();
    UFUNCTION(BlueprintCallable)
    void SetMusicState(UMusicSet* Set, FName State);
    
    UFUNCTION(BlueprintCallable)
    bool IsMusicSetActive(UMusicSet* Set);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UMusicManager* GetMusicManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    void DeactivateMusicSet(UMusicSet* Set, FName Outro);
    
    UFUNCTION(BlueprintCallable)
    void ActivateMusicSet(UMusicSet* Set, FName InitialState);
    
};

