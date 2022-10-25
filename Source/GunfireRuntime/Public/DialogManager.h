#pragma once
#include "CoreMinimal.h"
#include "DialogInfo.h"
#include "Components/ActorComponent.h"
#include "DialogCompleteAllEventDelegate.h"
#include "DialogManager.generated.h"

class UDialogInstance;
class USoundBase;
class AActor;
class UDialogManager;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UDialogManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DialogCullDistance;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogCompleteAllEvent OnCompleteAll;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDialogInstance*> ActiveDialog;
    
public:
    UDialogManager();
    UFUNCTION(BlueprintCallable)
    bool StopDialog(AActor* Source);
    
    UFUNCTION(BlueprintCallable)
    bool StopActiveDialog();
    
    UFUNCTION(BlueprintCallable)
    UDialogInstance* PlayDialogFromSound(AActor* Source, TSoftObjectPtr<USoundBase> Dialog);
    
    UFUNCTION(BlueprintCallable)
    UDialogInstance* PlayDialog(AActor* Source, const FDialogInfo& Info);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UDialogManager* GetDialogManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    UDialogInstance* GetActiveDialog(AActor* Source);
    
};

