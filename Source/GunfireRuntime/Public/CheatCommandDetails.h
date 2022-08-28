#pragma once
#include "CoreMinimal.h"
#include "CheatCommandDetails.generated.h"

USTRUCT(BlueprintType)
struct FCheatCommandDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString Command;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(EditAnywhere, Transient)
    uint32 ArgumentCount;
    
    GUNFIRERUNTIME_API FCheatCommandDetails();
};

