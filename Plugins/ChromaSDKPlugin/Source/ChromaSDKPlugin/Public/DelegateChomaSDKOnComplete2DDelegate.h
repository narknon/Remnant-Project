#pragma once
#include "CoreMinimal.h"
#include "DelegateChomaSDKOnComplete2DDelegate.generated.h"

class UChromaSDKPluginAnimation2DObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateChomaSDKOnComplete2D, UChromaSDKPluginAnimation2DObject*, Animation);

