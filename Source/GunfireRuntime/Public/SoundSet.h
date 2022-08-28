#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HierarchicalEditInterface.h"
#include "SoundSet.generated.h"

class USoundID;
class USoundSet;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API USoundSet : public UDataAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USoundID*> SoundIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundSet* ParentSoundSet;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, USoundID*> SoundMap;
    
public:
    USoundSet();
    
    // Fix for true pure virtual functions not being implemented
};

