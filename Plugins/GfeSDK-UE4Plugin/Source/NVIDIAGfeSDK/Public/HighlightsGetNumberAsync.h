#pragma once
#include "CoreMinimal.h"
#include "OnGetNumberOfHighlightsCallbackDelegate.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "EGfeSDKHighlightSignificance.h"
#include "EGfeSDKHighlightType.h"
#include "HighlightsGetNumberAsync.generated.h"

class UObject;
class UHighlightsGetNumberAsync;

UCLASS(Blueprintable)
class UHighlightsGetNumberAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGetNumberOfHighlightsCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsGetNumberAsync();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UHighlightsGetNumberAsync* HighlightsGetNumberOfHighlights(UObject* WorldContextObject, const FString& GroupId, const EGfeSDKHighlightType& TagFilter, const EGfeSDKHighlightSignificance& SignificanceFilter);
    
};

