#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "EInputDevice.h"
#include "ImageSet.generated.h"

class UImageID;
class UImageSet;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UImageSet : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UImageSet* ParentProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputDevice PrimaryDevice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UImageID*> ImageIDs;
    
    UImageSet();
    
    // Fix for true pure virtual functions not being implemented
};

