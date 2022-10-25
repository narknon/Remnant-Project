#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActorStateDecorator.h"
#include "UseItemStateDecorator.generated.h"

class AItem;
class UStaticMesh;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UUseItemStateDecorator : public UActorStateDecorator {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* AttachMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FireEventOnExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Remove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> Item;
    
    UPROPERTY(EditAnywhere)
    uint8 Quantity;
    
public:
    UUseItemStateDecorator();
};

