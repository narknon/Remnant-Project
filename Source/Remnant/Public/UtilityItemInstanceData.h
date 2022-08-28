#pragma once
#include "CoreMinimal.h"
#include "ItemInstanceData.h"
#include "UtilityItemInstanceData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class REMNANT_API UUtilityItemInstanceData : public UItemInstanceData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_InstanceData)
    uint8 Charges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float Cooldown;
    
    UUtilityItemInstanceData();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
};

