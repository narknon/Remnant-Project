#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GunfireSaveSystemSettings.generated.h"

class USaveGameWorld;
class USaveGameProfile;

UCLASS(Blueprintable, DefaultConfig)
class GUNFIRESAVESYSTEM_API UGunfireSaveSystemSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<USaveGameWorld> SaveGameClass;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<USaveGameProfile> SaveProfileClass;
    
    UGunfireSaveSystemSettings();
};

