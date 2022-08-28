#pragma once
#include "CoreMinimal.h"
#include "ShiftButtonType.h"
#include "InputFilterMethod.h"
#include "InputButton.generated.h"

USTRUCT(BlueprintType)
struct FInputButton {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InputName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShiftInputName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ShiftButtonType ShiftType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    InputFilterMethod Filter;
    
    GUNFIRERUNTIME_API FInputButton();
};

