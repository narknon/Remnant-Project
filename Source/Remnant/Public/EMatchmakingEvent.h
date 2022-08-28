#pragma once
#include "CoreMinimal.h"
#include "EMatchmakingEvent.generated.h"

UENUM(BlueprintType)
enum class EMatchmakingEvent : uint8 {
    ConnectionLost,
    SessionLost,
    SessionFull,
    SessionNonexistant,
    AlreadyInSession,
    GenericFailure,
    CreateSessionFailed,
    InternetLost,
    FailedToJoinAny,
    TutorialBeginMsg,
    TutorialEndMsg,
    CouldNotGetAddress,
    KickedFromSession,
    BannedFromSession,
    ChatRestrictions,
    FriendListFailed,
    MatchmakingUnavailable,
    VersionMismatch,
    Destroying,
    ChangeSessionFailed,
    OfflineSessionStarted,
    GameModeMismatch,
    Deceased,
    AFK,
    InProgress,
    MissingDLC,
    MissingDLC1,
    MissingDLC2,
};

