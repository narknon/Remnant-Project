#pragma once
#include "CoreMinimal.h"
#include "UserSetting.h"
#include "UObject/NoExportTypes.h"
#include "ResolutionUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UResolutionUserSetting : public UUserSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> AdditionalResolutions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWraps;
    
    UResolutionUserSetting();
    UFUNCTION(BlueprintCallable)
    void SetValue(FIntPoint NewResolution);
    
    UFUNCTION(BlueprintCallable)
    void ResetList(bool bMatchNativeAspectRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetValue();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetNextResolution(FIntPoint Current, bool bForwards);
    
};

