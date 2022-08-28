#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GunfireCrossplayManager.generated.h"

class UGunfireCrossplayManager;
class UObject;

UCLASS(Blueprintable)
class ONLINESUBSYSTEMSTEAMEOS_API UGunfireCrossplayManager : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UGunfireCrossplayManager();
    UFUNCTION(BlueprintCallable)
    void LoginPersistenceAuth();
    
    UFUNCTION(BlueprintCallable)
    void LoginEpicFromSteam(bool bCreateHeadlessAccount);
    
    UFUNCTION(BlueprintCallable)
    void LinkEpicFromSteam();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UGunfireCrossplayManager* GetGunfireCrossplayManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    void DeletePersistenceAuth();
    
    UFUNCTION(BlueprintCallable)
    void BeginCrossplayLogin();
    
};

