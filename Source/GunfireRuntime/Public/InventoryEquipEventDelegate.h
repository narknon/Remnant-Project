#pragma once
#include "CoreMinimal.h"
#include "InventoryEquipEventDelegate.generated.h"

class AEquipment;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FInventoryEquipEvent, AEquipment*, Equipment, int32, ItemID, int32, SlotIndex);

