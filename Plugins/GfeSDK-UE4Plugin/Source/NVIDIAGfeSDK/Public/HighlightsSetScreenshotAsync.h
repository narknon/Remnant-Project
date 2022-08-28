#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "HighlightsSetScreenshotAsync.generated.h"

class UHighlightsSetScreenshotAsync;
class UObject;

UCLASS(Blueprintable)
class UHighlightsSetScreenshotAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsSetScreenshotAsync();
    UFUNCTION(BlueprintCallable)
    static UHighlightsSetScreenshotAsync* HighlightsSetScreenshot(UObject* WorldContextObject, const FString& GroupId, const FString& HighlightId);
    
};

