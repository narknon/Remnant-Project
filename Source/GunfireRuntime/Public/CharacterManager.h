#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterManager.generated.h"

class ACharacterGunfire;
class AActor;
class UObject;
class UCharacterManager;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UCharacterManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacterGunfire*> Characters;
    
public:
    UCharacterManager();
    UFUNCTION(BlueprintCallable)
    void KillAllCharactersForOwner(AActor* Owner);
    
    UFUNCTION(BlueprintCallable)
    static UCharacterManager* GetInstance(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    TArray<ACharacterGunfire*> GetCharactersInAggroGroup(FName AggroGroup);
    
    UFUNCTION(BlueprintCallable)
    TArray<ACharacterGunfire*> GetCharactersForOwner(AActor* Owner);
    
    UFUNCTION(BlueprintCallable)
    void DestroyAllCharactersForOwner(AActor* Owner);
    
};

