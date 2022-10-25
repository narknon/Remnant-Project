#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "OnMiniMapSelectDelegateDelegate.h"
#include "SetMiniMapDelegateDelegate.h"
#include "OnMiniMapVisibilityDelegateDelegate.h"
#include "MiniMapActor.generated.h"

class AMiniMapDisplayActor;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMiniMapActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor Color;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMiniMapSelectDelegate OnSelectedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMiniMapSelectDelegate OnDeSelectedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMiniMapVisibilityDelegate OnShownEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMiniMapVisibilityDelegate OnHiddenEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSetMiniMapDelegate OnMiniMapSetEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Context;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* RefActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMiniMapDisplayActor* MiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool SnappedToEdge;
    
public:
    AMiniMapActor();
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateLevelVisibility(int32 DisplayLevel, int32 MyLevel);
    
    UFUNCTION(BlueprintCallable)
    void SetShown(bool bShown);
    
    UFUNCTION(BlueprintCallable)
    void Select(bool MultiSelect, bool bStaySelected);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnShown();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSelected();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnMiniMapSet(AMiniMapDisplayActor* MiniMapActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnHidden();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDeSelected();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSelected() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetRefActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetMiniMapRefActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMiniMapDisplayActor* GetMiniMap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsActorVisibleOnMiniMap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetContext() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void DeSelect();
    
    UFUNCTION(BlueprintCallable)
    void DebugSetContext(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void Center(bool bLock);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanSelect() const;
    
};

