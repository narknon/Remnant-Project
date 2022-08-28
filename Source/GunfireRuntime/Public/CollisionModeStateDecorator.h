#pragma once
#include "CoreMinimal.h"
#include "ActorStateDecorator.h"
#include "Engine/EngineTypes.h"
#include "ECustomCollisionEnabled.h"
#include "CollisionModeStateDecorator.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCollisionModeStateDecorator : public UActorStateDecorator {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetCollisionOnEnter;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ECollisionEnabled::Type> CollisionOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideSoftCollisionOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECustomCollisionEnabled SoftCollisionOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRestoreCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRestoreSoftCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetCollisionOnExit;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ECollisionEnabled::Type> CollisionOnExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideSoftCollisionOnExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECustomCollisionEnabled SoftCollisionOnExit;
    
public:
    UCollisionModeStateDecorator();
};

