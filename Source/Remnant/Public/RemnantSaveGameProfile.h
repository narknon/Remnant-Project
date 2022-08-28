#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SaveGameProfile.h"
#include "AccountCurrencyInstance.h"
#include "RemnantSaveGameProfile.generated.h"

class USavedCharacter;
class AQuest;
class UAccountAward;
class AItem;

UCLASS(Blueprintable)
class REMNANT_API URemnantSaveGameProfile : public USaveGameProfile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<USavedCharacter*> Characters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ActiveCharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bNeedsCheatedSaveConfirmation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAccountAward>> AccountAwards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAccountCurrencyInstance> AccountCurrencies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SurvivalBossesKilled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SurvivalCoopBossesKilled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SurvivalItemsAcquired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AQuest>, int32> SurvivalMiniBossQuestsCompleteMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AQuest>, int32> SurvivalWorldBossQuestsCompleteMap;
    
    URemnantSaveGameProfile();
    UFUNCTION(BlueprintCallable)
    bool UpdateAccountCurrency(TSubclassOf<AItem> CurrencyType, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    int32 GetAccountCurrencyForItemType(TSubclassOf<AItem> CurrencyType);
    
};

