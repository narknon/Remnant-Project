#pragma once
#include "CoreMinimal.h"
#include "EPingType.h"
#include "UObject/Object.h"
#include "ETownLock.h"
#include "UObject/NoExportTypes.h"
#include "PingSubContext.generated.h"

class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class REMNANT_API UPingSubContext : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 PingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETownLock TownLock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* WorldIconOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldOverrideWorldColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor WorldObjectColorOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SubContextText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SoundSetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SubtitleText;
    
    UPingSubContext();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidForPingType(EPingType Type) const;
    
};

