#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameModeGunfire.h"
#include "Engine/EngineTypes.h"
#include "OnAllPlayersDeadDelegateDelegate.h"
#include "WorldResetDelegateDelegate.h"
#include "ZoneLinkInfo.h"
#include "ELicensedContent.h"
#include "RemnantGameMode.generated.h"

class ARemnantPlayerController;
class UTileSet;
class ARemnantQuest;
class AActor;
class ACheckpoint;

UCLASS(Blueprintable, NonTransient)
class REMNANT_API ARemnantGameMode : public AGameModeGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantQuest> BaseQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantQuest> AutoLoadQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantQuest> DemoQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantQuest> DebugQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DebugTileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> DebugWaypointBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTileSet* DebugTileset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARemnantQuest* DebugQuestInstance;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAllPlayersDeadDelegate OnAllPlayersDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAllPlayersDeadDelegate OnFinishRespawnAllPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FailResetDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFailResetDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoneTravelDelay;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldResetDelegate OnWorldReset;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle RespawnHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle FailsafeRespawnHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle PostAllDeathRespawnHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ARemnantPlayerController*> WorldResetPlayers;
    
public:
    ARemnantGameMode();
    UFUNCTION(BlueprintCallable)
    void TravelToZone(int32 DestZoneID, const FName& DestLink, AActor* Source, bool bForce, bool bInstant);
    
    UFUNCTION(BlueprintCallable)
    void TravelToLastCheckpoint(AActor* Source);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetPostDeathScreenTime(float Time);
    
public:
    UFUNCTION(BlueprintCallable)
    bool SetAsRootCheckpoint(const FZoneLinkInfo& NewZoneLink, bool IgnoreActive);
    
    UFUNCTION(BlueprintCallable)
    bool SetAsRespawnZoneLink(const FZoneLinkInfo& NewZoneLink, bool bIgnoreWorldState);
    
    UFUNCTION(BlueprintCallable)
    void OnFullGameAvailable();
    
    UFUNCTION(BlueprintCallable)
    bool IsEveryoneEntitled(ELicensedContent License, bool ShowFailDialog, bool KickUnentitled);
    
    UFUNCTION(BlueprintCallable)
    void IncrementAllPlayersBossCounters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FZoneLinkInfo GetRespawnZoneLink() const;
    
    UFUNCTION(BlueprintCallable)
    void ActivateCheckpoint(ACheckpoint* Checkpoint);
    
};

