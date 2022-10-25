#pragma once
#include "CoreMinimal.h"
#include "UserSettingAppliedEventDelegate.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "UserSetting.generated.h"

class UGameUserSettingsGunfire;

UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class GUNFIRERUNTIME_API UUserSetting : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConsoleVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowOnConsoles;
    
    UPROPERTY(EditAnywhere)
    uint8 Platforms;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUserSettingAppliedEvent OnApplied;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameUserSettingsGunfire* Settings;
    
public:
    UUserSetting();
    UFUNCTION(BlueprintCallable)
    void ResetToDefault();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetDisplayValue() const;
    
    UFUNCTION(BlueprintCallable)
    void Apply();
    
    
    // Fix for true pure virtual functions not being implemented
};

