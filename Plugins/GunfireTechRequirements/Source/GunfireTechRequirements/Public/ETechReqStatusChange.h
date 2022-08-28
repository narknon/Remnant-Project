#pragma once
#include "CoreMinimal.h"
#include "ETechReqStatusChange.generated.h"

UENUM(BlueprintType)
enum class ETechReqStatusChange : uint8 {
    ConnectionLost,
    InternetLost,
    LiveLost,
    PlusLost,
    SessionLost,
    UpdateRequired,
    PatchRequired,
    AgeRestricted,
    UserNotLoggedIn,
    NeedsFullInstall,
    DlcLicenseLost,
    Normal,
    Unknown,
    ProfileAgeRestricted,
    PreOrderInstalled,
    MissingDLCParty,
    MissingDLC1,
    MissingDLC2,
    MissingDLC2Party,
};

