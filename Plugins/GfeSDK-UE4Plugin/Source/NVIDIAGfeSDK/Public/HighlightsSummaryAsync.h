#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "GfeSDKHighlightSummaryParams.h"
#include "HighlightsSummaryAsync.generated.h"

class UObject;
class UHighlightsSummaryAsync;

UCLASS(Blueprintable)
class UHighlightsSummaryAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsSummaryAsync();
    UFUNCTION(BlueprintCallable)
    static UHighlightsSummaryAsync* HighlightsOpenSummary(UObject* WorldContextObject, const FGfeSDKHighlightSummaryParams& Params);
    
};

