#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SubtitleDelegateDelegate.h"
#include "SubtitleInfo.h"
#include "SubtitlesComponent.generated.h"

class USoundBase;
class USubtitleInstance;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USubtitlesComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSubtitleDelegate OnAddSubtitle;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSubtitleDelegate OnRemoveSubtitle;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USubtitleInstance*> Subtitles;
    
public:
    USubtitlesComponent();
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemoveSubtitle(int32 ID);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveSubtitle(int32 ID);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRemoveSubtitle(int32 ID);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientAddSubtitle(const FSubtitleInfo& Info);
    
public:
    UFUNCTION(BlueprintCallable)
    USubtitleInstance* AddSubtitle(AActor* Source, FText Text, TSoftObjectPtr<USoundBase> Audio, FName Emote, bool AutoRemove);
    
};

