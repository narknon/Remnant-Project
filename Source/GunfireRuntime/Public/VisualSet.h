#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HierarchicalEditInterface.h"
#include "VisualSet.generated.h"

class UObject;
class UVisualSet;
class UVisualSetNode;
class UVisualFX;
class UVisualID;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UVisualSet : public UDataAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HardReferenceAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UVisualSet*> Include;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UVisualSetNode*> Nodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UVisualID*> VisualIDs;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UVisualFX*> VisualFXMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> HardReferencedAssets;
    
public:
    UVisualSet();
    
    // Fix for true pure virtual functions not being implemented
};

