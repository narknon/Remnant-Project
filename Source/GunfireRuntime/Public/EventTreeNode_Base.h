#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "EventTreeNodeCondition.h"
#include "EventTreeNode_Base.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_Base : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeNodeCondition> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WriteKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ValidKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NotValidKey;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
public:
    UEventTreeNode_Base();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString GetEditorLabel() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

