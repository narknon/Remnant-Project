#include "LoreItem.h"

class UObject;

void ALoreItem::LoreNotify(UObject* WorldContextObject, const FLorePage& Page) {
}

ALoreItem::ALoreItem() {
    this->AutoOpenUI = false;
    this->OverrideHideReadUI = false;
}

