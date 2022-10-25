#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "PrimaryPingInfo.h"
#include "EPingType.h"
#include "OnCharacterPingDelegate.h"
#include "OnRequestPingDelegate.h"
#include "Engine/EngineTypes.h"
#include "OnCharacterPingCooldownDelegate.h"
#include "ActionPing.h"
#include "RemnantPingManager.generated.h"

class AActor;
class UPingSubContext;
class UItemType;
class AItem;
class ARemnantPingActor;
class URemnantPingManager;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantPingManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCharacterPing OnCharacterPing;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCharacterPing OnPingRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRequestPing OnRequestPing;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCharacterPingCooldown OnCharacterPingCooldown;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> VOCoolDownActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> PingCoolDownActors;
    
    UPROPERTY(EditAnywhere)
    TMap<AActor*, uint8> CharacterPingAttempts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AActor*, FTimerHandle> CharacterPingCooldownHandles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPingType, FPrimaryPingInfo> PingTypeMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPingSubContext*> PingSubContexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPingSubContext* PrimaryAmmoRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPingSubContext* SecondaryAmmoRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPingSubContext* HealingRequest;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> RangedWeaponType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> PrimaryAmmoClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> SecondaryAmmoClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantPingActor> PingActorBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultPingDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VoCooldownDuration;
    
    UPROPERTY(EditAnywhere)
    uint8 AllowedPingsPerInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PingCooldownDuration;
    
public:
    URemnantPingManager();
    UFUNCTION(BlueprintCallable)
    bool IsCharacterOnVOCooldown(AActor* Character);
    
    UFUNCTION(BlueprintCallable)
    bool IsCharacterOnPingCooldown(AActor* Character);
    
    UFUNCTION(BlueprintCallable)
    float GetRemainingCharacterPingCooldown(AActor* Character);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URemnantPingManager* GetPingManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    bool GetPingFromCharacter(AActor* Character, FActionPing& OutPing, int32& PingIndex);
    
    UFUNCTION(BlueprintCallable)
    TArray<FActionPing> GetCurrentPings();
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Client_UpdateCharacterPing(AActor* Character, const FActionPing& NewPing);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Client_MarkPlayerSoloPing(AActor* Character, const bool IsSolo);
    
};

