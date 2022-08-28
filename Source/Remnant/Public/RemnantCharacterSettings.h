#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RemnantCharacterSettings.generated.h"

UCLASS(Blueprintable, Config=EditorPerProjectUserSettings)
class REMNANT_API URemnantCharacterSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CreateMalePIE;
    
    URemnantCharacterSettings();
};

