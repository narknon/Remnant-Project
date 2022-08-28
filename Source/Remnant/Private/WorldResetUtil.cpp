#include "WorldResetUtil.h"

class UObject;

bool UWorldResetUtil::IsWorldResetInProgress(const UObject* WorldContextObject) {
    return false;
}

uint8 UWorldResetUtil::GetWorldResetColorIndex() {
    return 0;
}

UWorldResetUtil::UWorldResetUtil() {
}

