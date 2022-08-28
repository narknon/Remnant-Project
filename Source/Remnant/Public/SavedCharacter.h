#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ERemnantCharacterType.h"
#include "ELastHostType.h"
#include "SavedEquipmentVisual.h"
#include "VisualSlot.h"
#include "EGender.h"
#include "PersistenceBlob.h"
#include "AccountAwardInstance.h"
#include "SavedCharacter.generated.h"

class URemnantArchetype;

UCLASS(Blueprintable)
class REMNANT_API USavedCharacter : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TraitRank;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<URemnantArchetype> Archetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool HasInitializedArchetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bFinishedIntro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bSkipIntro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FVisualSlot> Visuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSavedEquipmentVisual> EquipmentVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EGender Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ELastHostType HostType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TArray<uint8> CharacterBlob;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FPersistenceBlob CharacterData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 QuestDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 InitialDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 PowerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> Keys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> Counters;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString Name;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ERemnantCharacterType CharacterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDeceased;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 BossCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bValidExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 InvalidExitCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAccountAwardInstance> ReceivedAwards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasHandledCurrencyAward;
    
    USavedCharacter();
    UFUNCTION(BlueprintCallable)
    void SetSkipIntro(bool ShouldSkipIntro);
    
    UFUNCTION(BlueprintCallable)
    void SetKey(FName Key);
    
    UFUNCTION(BlueprintCallable)
    void SetCharacterType(ERemnantCharacterType NewCharacterType);
    
    UFUNCTION(BlueprintCallable)
    void MarkValidExit();
    
    UFUNCTION(BlueprintCallable)
    void IncrementCounter(FName Counter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasKey(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCounter(FName Counter);
    
    UFUNCTION(BlueprintCallable)
    bool CheckForInvalidExit();
    
};

