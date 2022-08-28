#pragma once
#include "CoreMinimal.h"
#include "OnInputActionDelegateDelegate.h"
#include "Blueprint/UserWidget.h"
#include "OnAdvButtonClickedEventDelegate.h"
#include "OnButtonClickedContextEventDelegate.h"
#include "OnAdvButtonReleasedEventDelegate.h"
#include "OnAdvButtonPressedEventDelegate.h"
#include "OnNavigationDelegateDelegate.h"
#include "FocusWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UFocusWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAdvButtonClickedEvent OnFocus;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAdvButtonClickedEvent OnClicked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnButtonClickedContextEvent OnClickedContext;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAdvButtonPressedEvent OnPressed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAdvButtonReleasedEvent OnReleased;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInputActionDelegate OnKey;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNavigationDelegate OnNavigate;
    
    UFocusWidget();
    UFUNCTION(BlueprintCallable)
    void SetInactiveFocus();
    
    UFUNCTION(BlueprintCallable)
    void Remove();
    
    UFUNCTION(BlueprintCallable)
    void Focus();
    
    UFUNCTION(BlueprintCallable)
    void ClearFocus();
    
};

