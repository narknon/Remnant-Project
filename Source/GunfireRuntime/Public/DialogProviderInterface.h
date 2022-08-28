#pragma once
#include "CoreMinimal.h"
#include "EDialogType.h"
#include "UObject/Interface.h"
#include "DialogProviderInterface.generated.h"

class UDialogComponent;
class UEventTree;
class AActor;

UINTERFACE(Blueprintable)
class UDialogProviderInterface : public UInterface {
    GENERATED_BODY()
};

class IDialogProviderInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetupContextVariables(UDialogComponent* DialogComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UEventTree* QueryEventTree(UDialogComponent* DialogComponent, EDialogType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UEventTree* GetEventTree(AActor* Actor);
    
};

