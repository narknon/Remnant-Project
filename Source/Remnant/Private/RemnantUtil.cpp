#include "RemnantUtil.h"

class UObject;
class AZoneActor;

bool URemnantUtil::IsGameSessionReady(const UObject* WorldContextObject) {
    return false;
}

int32 URemnantUtil::GetGameSeed() {
    return 0;
}

bool URemnantUtil::GetBaseZoneLinkByLabel(const UObject* WorldContextObject, const FString& Label, FZoneLinkInfo& OutZoneLink) {
    return false;
}

bool URemnantUtil::GetBaseZoneLink(const UObject* WorldContextObject, FZoneLinkInfo& OutZoneLink) {
    return false;
}

int32 URemnantUtil::GetBaseZoneID() {
    return 0;
}

AZoneActor* URemnantUtil::GetBaseZoneActor(const UObject* WorldContextObject) {
    return NULL;
}

bool URemnantUtil::CanPlayerExitGame(const UObject* WorldContextObject) {
    return false;
}

URemnantUtil::URemnantUtil() {
}

