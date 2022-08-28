#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHighlightsOperationResultCallbackDelegate.h"
#include "HighlightsCloseGroupAsync.generated.h"

class UHighlightsCloseGroupAsync;
class UObject;

UCLASS(Blueprintable)
class UHighlightsCloseGroupAsync : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHighlightsOperationResultCallback OnFailure;
    
    UHighlightsCloseGroupAsync();
    UFUNCTION(BlueprintCallable)
    static UHighlightsCloseGroupAsync* HighlightsCloseGroup(UObject* WorldContextObject, const FString& GroupId, const bool& DestroyHighlights);
    
};

