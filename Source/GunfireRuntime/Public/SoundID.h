#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "SoundID.generated.h"

class USoundEntry;
class USoundBase;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API USoundID : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USoundEntry*> Entries;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USoundBase*> PreloadSounds;
    
public:
    USoundID();
    
    // Fix for true pure virtual functions not being implemented
};

