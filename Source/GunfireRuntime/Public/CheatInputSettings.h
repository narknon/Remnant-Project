#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameFramework/PlayerInput.h"
#include "CheatInputAction.h"
#include "CheatInputSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Input)
class GUNFIRERUNTIME_API UCheatInputSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheatsEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCheatInputAction> ActionMappings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyMapping> DebugToggleKeys;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCheatInputAction> DebugActionMappings;
    
    UCheatInputSettings();
};

