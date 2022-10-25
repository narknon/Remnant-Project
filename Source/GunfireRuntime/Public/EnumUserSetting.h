#pragma once
#include "CoreMinimal.h"
#include "EnumUserSettingEntry.h"
#include "IntUserSetting.h"
#include "EnumUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UEnumUserSetting : public UIntUserSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnumUserSettingEntry> Entries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWraps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> DisabledValues;
    
    UEnumUserSetting();
    UFUNCTION(BlueprintCallable)
    void SetValueEnum(const FEnumUserSettingEntry& Entry);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetValueEnum(FEnumUserSettingEntry& OutEntry);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumEntries() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNextEntry(int32 CurrentValue, FEnumUserSettingEntry& OutNext, bool bForwards);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEnumEntryByValue(int32 Value, FEnumUserSettingEntry& OutEntry);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEnumEntryByIndex(int32 Index, FEnumUserSettingEntry& OutEntry);
    
    UFUNCTION(BlueprintCallable)
    void EnableValue(int32 InValue);
    
    UFUNCTION(BlueprintCallable)
    void DisableValue(int32 InValue);
    
};

