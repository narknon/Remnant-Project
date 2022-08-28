#pragma once
#include "CoreMinimal.h"
#include "EDlcRequirementTypes.h"
#include "EPresenceContent.h"
#include "SessionDetails.generated.h"

USTRUCT(BlueprintType)
struct FSessionDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PowerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Difficulty;
    
    UPROPERTY(EditAnywhere)
    uint8 CharacterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPresenceContent Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDlcRequirementTypes DlcRequired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsHighPriority;
    
    REMNANT_API FSessionDetails();
};

