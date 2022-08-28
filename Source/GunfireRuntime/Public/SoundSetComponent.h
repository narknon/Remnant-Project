#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SoundSetComponent.generated.h"

class USoundBase;
class UMeshComponent;
class USoundSet;
class USoundCue;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USoundSetComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundSet* SoundSet;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SoundTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMeshComponent* MeshComp;
    
public:
    USoundSetComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveSoundTag(FName SoundTag);
    
    UFUNCTION(BlueprintCallable)
    void PlaySound2D(FName SoundIDName, float VolumeMultiplier, float PitchMultiplier);
    
    UFUNCTION(BlueprintCallable)
    void PlaySound(FName SoundIDName, float VolumeMultiplier, float PitchMultiplier, bool bAttach, FName SocketName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSoundTag(FName SoundTag) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetSoundTags();
    
    UFUNCTION(BlueprintCallable)
    TSoftObjectPtr<USoundBase> GetSoundSoft(FName SoundIDName);
    
    UFUNCTION(BlueprintCallable)
    USoundCue* GetSoundCue(FName SoundIDName);
    
    UFUNCTION(BlueprintCallable)
    USoundBase* GetSound(FName SoundIDName);
    
    UFUNCTION(BlueprintCallable)
    void AddUniqueSoundTag(FName SoundTag);
    
};

