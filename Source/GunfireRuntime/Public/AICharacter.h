#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CharacterGunfire.h"
#include "UObject/NoExportTypes.h"
#include "AICharacter.generated.h"

class UBlackboardData;
class AAIPathPoint;
class UCombatClass;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AAICharacter : public ACharacterGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBlackboardData* Blackboard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAIPathPoint* SpawnPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAIPathPoint* PatrolPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCombatClass> CombatClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector SpawnLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName POITag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_POIAnimationTag, meta=(AllowPrivateAccess=true))
    FName POIAnimationTag;
    
    AAICharacter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_POIAnimationTag(FName PreviousTag);
    
};

