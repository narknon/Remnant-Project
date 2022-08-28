#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "HighlightsSetVideoAsync.generated.h"

class UHighlightsSetVideoAsync;
class UObject;

UCLASS(Blueprintable)
class UHighlightsSetVideoAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsSetVideoAsync();
    UFUNCTION(BlueprintCallable)
    static UHighlightsSetVideoAsync* HighlightsSetVideo(UObject* WorldContextObject, const FString& GroupId, const FString& HighlightId, const int32& StartDelta, const int32& EndDelta);
    
};

