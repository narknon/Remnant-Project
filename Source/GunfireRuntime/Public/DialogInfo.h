#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DialogInfo.generated.h"

class USoundBase;
class UDialogVocalRange;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FDialogInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Speaker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Emote;
    
    UPROPERTY(EditAnywhere)
    uint8 TextCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> Dialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreVocalRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogVocalRange> VocalRange;
    
    FDialogInfo();
};

