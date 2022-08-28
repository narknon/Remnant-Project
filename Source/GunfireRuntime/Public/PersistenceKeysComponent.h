#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PersistenceKeysComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UPersistenceKeysComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> KeyValues;
    
public:
    UPersistenceKeysComponent();
    UFUNCTION(BlueprintCallable)
    void SetKey(FName Key, FName Value);
    
    UFUNCTION(BlueprintCallable)
    void RemoveKey(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasKey(FName Key) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetKeyValue(FName Key) const;
    
    UFUNCTION(BlueprintCallable)
    void AddKey(FName Key);
    
};

