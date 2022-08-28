#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "PlayState.generated.h"

class UPlayStateEffect;

UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class GUNFIRERUNTIME_API UPlayState : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StateName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UPlayStateEffect*> Effects;
    
    UPlayState();
    
    // Fix for true pure virtual functions not being implemented
};

