#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RebindedInputAction.h"
#include "RebindedInputAxis.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/PlayerInput.h"
#include "InputRebindings.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UInputRebindings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FRebindedInputAction> ActionRebindings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FRebindedInputAxis> AxisRebindings;
    
    UInputRebindings();
    UFUNCTION(BlueprintCallable)
    static void ResetInputRebindings();
    
    UFUNCTION(BlueprintCallable)
    static void RemoveAxisRebinding(const FInputAxisKeyMapping& Axis);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveActionRebinding(const FInputActionKeyMapping& Action);
    
    UFUNCTION(BlueprintCallable)
    static void AddAxisRebinding(const FInputAxisKeyMapping& Axis);
    
    UFUNCTION(BlueprintCallable)
    static void AddActionRebinding(const FInputActionKeyMapping& Action);
    
};

