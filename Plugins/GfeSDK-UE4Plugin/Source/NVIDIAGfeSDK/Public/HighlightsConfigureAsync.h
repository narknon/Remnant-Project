#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "GfeSDKHighlightConfigParams.h"
#include "HighlightsConfigureAsync.generated.h"

class UHighlightsConfigureAsync;
class UObject;

UCLASS(Blueprintable)
class UHighlightsConfigureAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsConfigureAsync();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UHighlightsConfigureAsync* HighlightsConfigure(UObject* WorldContextObject, const FGfeSDKHighlightConfigParams& ConfigParams);
    
};

