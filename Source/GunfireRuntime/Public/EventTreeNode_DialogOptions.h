#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode_Branch.h"
#include "EventTreeNode_DialogOptions.generated.h"

class UEventTreeComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_DialogOptions : public UEventTreeNode_Branch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DialogTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoCompleteDialog;
    
    UEventTreeNode_DialogOptions();
    UFUNCTION(BlueprintCallable)
    void SelectOption(UEventTreeComponent* Component, uint8 Option);
    
};

