#pragma once
#include "CoreMinimal.h"
#include "DelegateChomaSDKOnComplete1DDelegate.generated.h"

class UChromaSDKPluginAnimation1DObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateChomaSDKOnComplete1D, UChromaSDKPluginAnimation1DObject*, Animation);

