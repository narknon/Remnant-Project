#pragma once
#include "CoreMinimal.h"
#include "EPlayerTravelState.generated.h"

UENUM(BlueprintType)
enum class EPlayerTravelState : uint8 {
    Idle,
    PendingTravel,
    Traveling,
    PostTravel,
    WaitingForClientToBeginTravel,
    WaitingForClientToLoad,
    WaitingForFinishTravel,
    LoadingDestinationZone,
    FinalizingTravel,
    WaitingForClient,
    WaitingForServer,
    WaitingForIntroQuest,
    PendingCharSwap,
};

