#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EDialogLocation.h"
#include "Engine/LatentActionManager.h"
#include "GameFramework/HUD.h"
#include "OnIconsLoadedDelegate.h"
#include "OnHudEventDelegateDelegate.h"
#include "EDialogBeginMethod.h"
#include "UIHud.generated.h"

class APawn;
class AUIActor;
class UObject;

UCLASS(Blueprintable, NonTransient)
class GUNFIRERUNTIME_API AUIHud : public AHUD {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisablePlayerInput;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHudEventDelegate OnHudEventDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoHideUMGWidgetsOnHidden;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawn* PlayerPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AUIActor*> UIActorStack;
    
    AUIHud();
    UFUNCTION(BlueprintCallable)
    void UnloadLargeIcons();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetVisibility(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    AUIActor* SetDialog(TSubclassOf<AUIActor> DialogBP, EDialogLocation Location, FText Text, FText Caption);
    
    UFUNCTION(BlueprintCallable)
    void PushUIActor(const AUIActor* UIActor);
    
    UFUNCTION(BlueprintCallable)
    AUIActor* PopUIActor(AUIActor* DialogToPop);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PawnChanged(APawn* Pawn);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnSetVisbility(bool bIsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnHudEvent(FName EventID, UObject* Context);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDialogEnd(AUIActor* Dialog);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDialogBegin(AUIActor* Dialog);
    
    UFUNCTION(BlueprintCallable)
    void LoadLargeIcons(FOnIconsLoaded OnIconsLoaded, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintPure)
    bool IsVisible() const;
    
    UFUNCTION(BlueprintCallable)
    void InsertUIActor(const AUIActor* UIActor, int32 StackIndex);
    
    UFUNCTION(BlueprintCallable)
    AUIActor* GetTopInputActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AUIActor* GetDialog(TSubclassOf<AUIActor> DialogBP) const;
    
    UFUNCTION(BlueprintCallable)
    AUIActor* GetCurrentDialog();
    
    UFUNCTION(BlueprintCallable)
    APawn* GetControllingPawn();
    
    UFUNCTION(BlueprintCallable)
    void EndDialog(FName Result, UObject* EndingDialogContext);
    
    UFUNCTION(BlueprintCallable)
    void EndAllDialogs();
    
    UFUNCTION(BlueprintCallable)
    AUIActor* BeginDialog(TSubclassOf<AUIActor> DialogBP, EDialogLocation Location, FText Text, FText Caption, EDialogBeginMethod Method);
    
    UFUNCTION(BlueprintCallable)
    void AddUIToActorStack(const AUIActor* UIActor);
    
};

