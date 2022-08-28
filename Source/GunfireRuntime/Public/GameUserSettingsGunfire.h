#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "GenericInput.h"
#include "GameUserSettingsGunfire.generated.h"

class UUserSetting;
class URebindableInputSetting;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UGameUserSettingsGunfire : public UGameUserSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UUserSetting*> Settings;
    
    UGameUserSettingsGunfire();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetUserSettingInt(const FName& NameID, int32 Value);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetUserSettingFloat(const FName& NameID, int32 Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UUserSetting*> GetSettingsForCategory(const FName& Category) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetInputConflicts(URebindableInputSetting* Setting, FGenericInput Key, const TArray<FName>& Categories, TArray<URebindableInputSetting*>& Conflicts);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UUserSetting* FindUserSetting(const FName& NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllowsInputRebindings() const;
    
};

