#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChallengeInstance.h"
#include "ChallengeComponent.generated.h"

class UChallengeList;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UChallengeComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UChallengeList* ListOfAllChallenges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FChallengeInstance> ChallengeInstances;
    
    UChallengeComponent();
    UFUNCTION(BlueprintCallable)
    bool UnlockChallenge(const FName& ChallengeID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsChallengeComplete(const FName& ChallengeID) const;
    
    UFUNCTION(BlueprintCallable)
    void IncrementObjectivesFromActor(const FName& EventType, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void IncrementObjectives(const FName& EventType, const FName& Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetChallengeRank(const FName& ChallengeID) const;
    
};

