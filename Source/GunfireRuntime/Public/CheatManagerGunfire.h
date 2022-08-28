#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "CheatCommands.h"
#include "CheatInputAction.h"
#include "CheatManagerGunfire.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCheatManagerGunfire : public UCheatManager {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FString, FCheatCommands> CheatCommandsByCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FString> CheatCommandCategories;
    
public:
    UCheatManagerGunfire();
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockAllTraits(int32 StartingLevel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleSecondaryFlyCamera();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TogglePrimaryFlyCamera();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleFollowPlayer();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TakeScreenShotWithDimensions(int32 ResX, int32 ResY);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TakeScreenShotCurrentResolutionScaled(int32 ScaleResolution);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SpawnCharacter(const FString& NameOfCharBP);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetPlayerState(FName NewState);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetPlayerNormalizedHealth(float NewHealth);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetKillRadius(float NewKillRadius);
    
    UFUNCTION(BlueprintCallable)
    void SendCommandToConsole(const FString& Command);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RemoveItem(const FString& NameOfBP, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void OnUseDebugCommandKey();
    
    UFUNCTION(BlueprintCallable)
    void OnReleaseDebugCommandKey();
    
    UFUNCTION(BlueprintCallable, Exec)
    void KillNearbyEnemies();
    
    UFUNCTION(BlueprintCallable, Exec)
    void IncreasePlayerLevel(int32 NumLevel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GiveItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GiveAllItems(const FString& NameOfClassBP, int32 Quantity, int32 LevelOverride, bool bOnlyUnique);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FString> GetInputDescriptorForCheat(FName ActionName);
    
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetConsoleCommands(const FString& Category);
    
    UFUNCTION(BlueprintCallable)
    FText GetConsoleCommandDescription(const FString& Command);
    
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetConsoleCommandCategories();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FCheatInputAction> GetAllCheats();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ForceCrash();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ExecuteCheat(FName ActionName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void EnablePrimaryFlyCamera();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DropItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DoAction(const FString& NameOfBP, bool bApplyToTarget);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ClearAllDialogs();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreCheatsEnabled();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddTrait(const FString& NameOfBP, int32 Level);
    
};

