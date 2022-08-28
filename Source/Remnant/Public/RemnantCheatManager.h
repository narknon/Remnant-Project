#pragma once
#include "CoreMinimal.h"
#include "CheatManagerGunfire.h"
#include "ELicensedContent.h"
#include "RemnantCheatManager.generated.h"

UCLASS(Blueprintable)
class REMNANT_API URemnantCheatManager : public UCheatManagerGunfire {
    GENERATED_BODY()
public:
    URemnantCheatManager();
private:
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockAllWaypoints();
    
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockAllEmotes();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TravelToQuest(const FString& QuestName, const FString& ComponentName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleShowBlood();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleFogOfWar();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleDLC(ELicensedContent License);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SpawnDebugQuest(const FString& NameOfBP);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ShowMatchmakingPowerLevel();
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetDifficulty(int32 Difficulty);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RaiseDifficulty();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LowerDifficulty();
    
    UFUNCTION(BlueprintCallable, Exec)
    void Joinability(bool isJoinable);
    
private:
    UFUNCTION(BlueprintCallable, Exec)
    void GiveAccountAward(const FString& NameOfBP);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddScrap(int32 Amount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddExperience(int32 Amount);
    
};

