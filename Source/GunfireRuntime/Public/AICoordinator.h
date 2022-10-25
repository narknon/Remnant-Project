#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "EFlockingStyle.h"
#include "OnRegisterAttackDelegateDelegate.h"
#include "AICoordinator.generated.h"

class AActor;
class UCombatClass;
class UAICoordinator;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAICoordinator : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFlockingStyle FlockingStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCombatClass> DefaultCombatClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCombatClass> PlayerCombatClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRegisterAttackDelegate OnRegisterAttack;
    
    UAICoordinator();
    UFUNCTION(BlueprintCallable)
    int32 GetWeightForTarget(AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    int32 GetMaxWeightForTarget(AActor* Target);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAICoordinator* GetAICoordinator(UObject* WorldContextObject);
    
};

