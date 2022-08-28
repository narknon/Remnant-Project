#pragma once
#include "CoreMinimal.h"
#include "ContextualDialogResponse.h"
#include "ContextualDialogDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FContextualDialogDelegate, const FContextualDialogResponse&, Response);

