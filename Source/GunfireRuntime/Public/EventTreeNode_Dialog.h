#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EventTreeNode.h"
#include "EventTreeAttrib.h"
#include "Engine/EngineTypes.h"
#include "EventTreeNode_Dialog.generated.h"

class UDialogVocalRange;
class UDialog_Speaker;
class UEventTreeComponent;
class USoundBase;
class UDialog_Emote;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_Dialog : public UEventTreeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialog_Speaker> Speaker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialog_Emote> Emote;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CompleteAfterDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitTimeAfterComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> Dialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeAttrib> Attributes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogVocalRange> VocalRange;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsDefaultSpeaker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsDefaultVocalRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle WaitTimerHandle;
    
public:
    UEventTreeNode_Dialog();
    UFUNCTION(BlueprintCallable)
    void OnFinishedWaiting(UEventTreeComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void OnDialogComplete(UEventTreeComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void Complete(UEventTreeComponent* Component);
    
};

