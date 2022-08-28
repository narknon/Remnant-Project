#pragma once
#include "CoreMinimal.h"
#include "UserSetting.h"
#include "GenericInput.h"
#include "EInputConflictGroup.h"
#include "RebindableInputSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API URebindableInputSetting : public UUserSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InputName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AxisScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGenericInput DefaultInput;
    
    UPROPERTY(EditAnywhere)
    uint8 ConflictGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> IgnoreInputs;
    
    URebindableInputSetting();
    UFUNCTION(BlueprintCallable)
    void SetValue(FGenericInput NewKey);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasConflictGroup(EInputConflictGroup InputGroup) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGenericInput GetValue();
    
};

