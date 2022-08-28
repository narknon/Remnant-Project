#pragma once
#include "CoreMinimal.h"
#include "BreakableEventDelegate.h"
#include "Components/SceneComponent.h"
#include "Engine/EngineTypes.h"
#include "BreakableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UBreakableComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBreakableEvent OnPreBreak;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBreakableEvent OnBeginBreak;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBreakableEvent OnEndBreak;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBreakableEvent OnReset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreakDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomTorque;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UnbrokenMeshComponent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnbrokenMeshSupportsCollisionQueries;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPiecesSupportsCollisionQueries;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PiecesCollisionProfileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle HideHandle;
    
public:
    UBreakableComponent();
    UFUNCTION(BlueprintCallable)
    void Reset();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnHidePieces();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUnbroken() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBroken() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBreaking() const;
    
    UFUNCTION(BlueprintCallable)
    void Break();
    
};

