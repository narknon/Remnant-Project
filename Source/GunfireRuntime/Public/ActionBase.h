#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActorModifier.h"
#include "DamageInfo.h"
#include "Engine/EngineTypes.h"
#include "ActionBase.generated.h"

class UActionComponent;
class AActor;
class UDamageTypeGunfire;
class APlayerControllerGunfire;
class UDamageType;
class UActionBase;

UCLASS(Blueprintable, Config=Game)
class GUNFIRERUNTIME_API UActionBase : public UActorModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 ActionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDamageInfo DamageInfo;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ApplyOnKilled;
    
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopOnCinematic;
    
public:
    UActionBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetCause(AActor* Cause);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCinematic(APlayerControllerGunfire* Player, bool bIsInCinematicMode);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActionStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActionStart();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionFinished() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetHitInfo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UDamageType> GetDamageType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCauseOwner() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCause() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActionComponent* GetActionComponent() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* FireProjectile(AActor* CauseActor, FName SourceSocket, AActor* TargetActor, TSubclassOf<AActor> ProjectileBP, float Speed, bool bOrientTowardsTarget, float AutoArcHeight, float GravityScale);
    
    UFUNCTION(BlueprintCallable)
    void FinishAction();
    
    UFUNCTION(BlueprintCallable)
    static void DoInstantHit(AActor* CauseActor, FName SourceSocket, float Range, int32 SprayCount, float Spread, TSubclassOf<UDamageTypeGunfire> DamageType, float Damage, float DamageMod, float DamageScalar);
    
    UFUNCTION(BlueprintCallable)
    void ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, TSubclassOf<UDamageTypeGunfire> DamageType, FHitResult HitInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool AllowAction(TSubclassOf<UActionBase> ActionBP, const FDamageInfo& InDamageInfo);
    
};

