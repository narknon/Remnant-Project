#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemCategory.generated.h"

class UTexture2D;

UCLASS(Abstract, Blueprintable, Const)
class GUNFIRERUNTIME_API UItemCategory : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UItemCategory();
};

