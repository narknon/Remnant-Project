#include "MiniMapEntry.h"

FMiniMapEntry::FMiniMapEntry() {
    this->ID = 0;
    this->Context = 0;
    this->MiniMapLevel = 0;
    this->Actor = NULL;
    this->Type = EMiniMapActorType::Default;
    this->WidgetClass = NULL;
}

