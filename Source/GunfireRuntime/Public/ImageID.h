#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "ImageID.generated.h"

class UImageEntry;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UImageID : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UImageEntry*> ImageEntries;
    
    UImageID();
    
    // Fix for true pure virtual functions not being implemented
};

