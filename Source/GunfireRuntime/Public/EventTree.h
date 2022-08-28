#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "EventTree.generated.h"

class UEventTreeNode;
class UDialogVocalRange;
class UDialog_Speaker;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTree : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEventTreeNode*> Nodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialog_Speaker> DefaultSpeaker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogVocalRange> DefaultVocalRange;
    
    UEventTree();
    
    // Fix for true pure virtual functions not being implemented
};

