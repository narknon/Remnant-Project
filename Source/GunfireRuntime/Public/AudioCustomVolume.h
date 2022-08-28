#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Sound/AudioVolume.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Attenuation.h"
#include "WorldSound.h"
#include "AudioState.h"
#include "AudioCustomVolume.generated.h"

class UMusicSet;
class AAudioCustomVolume;
class UWorldSoundSet;
class USoundAttenuation;
class UAudioStateID;
class UAmbientAudioComponent;
class UAudioComponent;
class UWorldSoundComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AAudioCustomVolume : public AAudioVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AAudioCustomVolume*> HasPriorityOver;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInfiniteExtent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldSoundSet* WorldSoundSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldSound> WorldSounds;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EAttenuationShape::Type> AttenShape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AttenExtents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMusicSet* MusicSet;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAudioState> States;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundAttenuation* AttenuationSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideFalloff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FalloffOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAudioStateID> CurrentStateID;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAmbientAudioComponent* PrimaryAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* OnEnterAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* OnExitAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWorldSoundComponent* WorldSoundComponent;
    
public:
    AAudioCustomVolume();
    UFUNCTION(BlueprintCallable)
    void SetState(TSubclassOf<UAudioStateID> StateID, bool bPlayTransitions);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEndActiveVolume();
    
    UFUNCTION(BlueprintCallable)
    void OnBeginActiveVolume();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActiveVolume() const;
    
};

