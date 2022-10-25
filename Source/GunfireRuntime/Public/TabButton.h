#pragma once
#include "CoreMinimal.h"
#include "Components/Button.h"
#include "AdvButtonStyle.h"
#include "Components/ContentWidget.h"
#include "OnTabFocusDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "Components/Button.h"
#include "TabButton.generated.h"

class UWidget;
class UFocusWidget;
class UFocusManager;
class UTexture2D;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UTabButton : public UContentWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TabPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdvButtonStyle WidgetStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorAndOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BackgroundColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TabNextKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TabPrevKey;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnButtonPressedEvent OnPressed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnButtonReleasedEvent OnReleased;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTabFocusDelegate OnTabFocused;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWidget* TabPanelCached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFocusManager* CachedFocusManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFocusWidget* UserFocusWidget;
    
public:
    UTabButton();
    UFUNCTION(BlueprintCallable)
    void SetTexture(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable)
    void SetTabPanel(UWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    void SetColorAndOpacity(FLinearColor InColorAndOpacity);
    
    UFUNCTION(BlueprintCallable)
    void SetBackgroundColor(FLinearColor InBackgroundColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPressed() const;
    
    UFUNCTION(BlueprintCallable)
    UWidget* GetTabPanel();
    
    UFUNCTION(BlueprintCallable)
    void FocusTab();
    
};

