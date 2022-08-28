#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/NoExportTypes.h"
#include "ProjectileMovementComponentGunfire.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UProjectileMovementComponentGunfire : public UProjectileMovementComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Penetrate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProjectileMovementComponent::FOnProjectileStopDelegate OnProjectileHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyPostBounceGravityScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostBounceGravityScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BounceNormalAlignmentAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PenetrateVelocityModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyPostBounceVelocityClamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PostBounceMinMaxVelocity;
    
    UProjectileMovementComponentGunfire();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector SimulateBounce(FVector CurrentVelocity, const FHitResult& Hit, float& OutGravityScale);
    
    UFUNCTION(BlueprintCallable)
    void SetPenetrate(bool bShouldPenetrate);
    
};

