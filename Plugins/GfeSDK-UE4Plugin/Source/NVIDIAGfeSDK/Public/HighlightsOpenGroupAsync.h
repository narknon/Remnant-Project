#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "GfeSDKHighlightOpenGroupParams.h"
#include "HighlightsOpenGroupAsync.generated.h"

class UObject;
class UHighlightsOpenGroupAsync;

UCLASS(Blueprintable)
class UHighlightsOpenGroupAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsOpenGroupAsync();
    UFUNCTION(BlueprintCallable)
    static UHighlightsOpenGroupAsync* HighlightsOpenGroup(UObject* WorldContextObject, const FGfeSDKHighlightOpenGroupParams& Params);
    
};

