#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GfeSDKCreateResponse.h"
#include "EGfeSDKPermission.h"
#include "HighlightsFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class UHighlightsFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UHighlightsFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void Poll();
    
    UFUNCTION(BlueprintCallable)
    static void ChekIfHighlightsAvailable(const FGfeSDKCreateResponse& InitProperties, bool& VideoGranted, bool& ScreenshotsGranted, EGfeSDKPermission& Video, EGfeSDKPermission& Screenshots);
    
};

