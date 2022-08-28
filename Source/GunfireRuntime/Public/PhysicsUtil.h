#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CachedPhysicsComponent.h"
#include "PhysicsUtil.generated.h"

class UPrimitiveComponent;
class UPhysicalMaterial;
class AActor;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UPhysicsUtil : public UObject {
    GENERATED_BODY()
public:
    UPhysicsUtil();
    UFUNCTION(BlueprintCallable)
    static void RestoreRigidBodies(UPARAM(Ref) TArray<FCachedPhysicsComponent>& CachedComponents);
    
    UFUNCTION(BlueprintCallable)
    static void ResetOverlaps(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static UPhysicalMaterial* GetPhysicsMaterial(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static int32 DisableRigidBodies(AActor* Actor, UPARAM(Ref) TArray<FCachedPhysicsComponent>& CachedComponents);
    
};

