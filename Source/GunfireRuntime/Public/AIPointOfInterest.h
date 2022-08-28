#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "AIPointOfInterest.generated.h"

class UAIPOIType;
class AAIPathPoint;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AAIPointOfInterest : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAIPOIType> Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinUseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxUseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAIPathPoint* PatrolPath;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Occupant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
public:
    AAIPointOfInterest();
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool IsEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnValidate(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOccupied(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndUse();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginUse();
    
    UFUNCTION(BlueprintCallable)
    void EndUse();
    
    UFUNCTION(BlueprintCallable)
    void BeginUse();
    
};

