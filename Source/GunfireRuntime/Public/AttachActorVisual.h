#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SceneVisual.h"
#include "AttachActorVisual.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UAttachActorVisual : public USceneVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorBP;
    
    UAttachActorVisual();
};

