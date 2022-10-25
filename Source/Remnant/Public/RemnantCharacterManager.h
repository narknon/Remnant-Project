#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "RequestFailedDelegateDelegate.h"
#include "CharacterCreatedDelegateDelegate.h"
#include "CharactersDeletedDelegateDelegate.h"
#include "OnActiveCharacterChangedDelegate.h"
#include "ERemnantCharacterType.h"
#include "RemnantCharacterManager.generated.h"

class UItemType;
class UAccountAward;
class URemnantCharacterManager;
class USavedCharacter;
class APlayerController;
class AItem;
class URemnantArchetype;

UCLASS(Blueprintable)
class REMNANT_API URemnantCharacterManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterCreatedDelegate CharacterCreated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharactersDeletedDelegate CharacterDeleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRequestFailedDelegate CharaterCreationFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRequestFailedDelegate CharacterLoadingFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveCharacterChanged OnActiveCharacterChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<USavedCharacter*> TransientCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<APlayerController*, USavedCharacter*> ClientCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> NewCharacterEquipmentVisuals;
    
public:
    URemnantCharacterManager();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool ShouldAwardHardcoreRewards(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    bool SetActiveCharacter(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    bool RestoreCharacters();
    
    UFUNCTION(BlueprintCallable)
    bool ResolvePendingExit();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsHardcore(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsDeceasedCharacter(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasBackupCharacters() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasActiveCharacter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<USavedCharacter*> GetTransientCharacters();
    
    UFUNCTION(BlueprintCallable)
    int32 GetMaxCharacterCount();
    
    UFUNCTION(BlueprintCallable)
    TArray<USavedCharacter*> GetCharacters();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URemnantCharacterManager* GetCharacterManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    USavedCharacter* GetCharacterInfo(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    int32 GetCharacterCount();
    
    UFUNCTION(BlueprintCallable)
    USavedCharacter* GetCharacterAt(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    USavedCharacter* GetCharacter(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    void GetActiveEquipmentVisuals(USavedCharacter* CharacterInfo, TArray<TSubclassOf<AItem>>& OutVisuals, TArray<uint8>& OutLevels, TArray<TSubclassOf<AItem>>& OutSkins);
    
    UFUNCTION(BlueprintCallable)
    USavedCharacter* GetActiveCharacter();
    
    UFUNCTION(BlueprintCallable)
    bool DeleteTransientCharacters();
    
    UFUNCTION(BlueprintCallable)
    bool DeleteTransientCharacter(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    bool DeleteCharacter(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    USavedCharacter* CreateTransientCharacter(const FString& Name, TSubclassOf<USavedCharacter> SaveGameClass, int32& ErrorCode, bool SetActive, ERemnantCharacterType CharacterType, bool ShouldSkipIntro, TSoftClassPtr<URemnantArchetype> Archetype, int32 StartingDifficulty, USavedCharacter* ReferenceCharacter, const TArray<TSubclassOf<UAccountAward>>& AllowedAccountAwards);
    
    UFUNCTION(BlueprintCallable)
    USavedCharacter* CreateCharacter(const FString& Name, TSubclassOf<USavedCharacter> SaveGameClass, int32& ErrorCode, bool SetActive, ERemnantCharacterType CharacterType, bool ShouldSkipIntro, TSoftClassPtr<URemnantArchetype> Archetype, int32 StartingDifficulty);
    
};

