#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemDelegateDelegate.h"
#include "ItemInstanceData.generated.h"

UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class GUNFIRERUNTIME_API UItemInstanceData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_InstanceData)
    uint8 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_InstanceData, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemDelegate OnChanged;
    
    UItemInstanceData();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_InstanceData();
    
};

