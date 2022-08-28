#include "MiniMapActorInfo.h"

FMiniMapActorInfo::FMiniMapActorInfo() {
    this->ID = 0;
    this->Type = EMiniMapActorType::Default;
    this->RefActor = NULL;
    this->AbsoluteScale = false;
    this->Scale = 0.00f;
    this->Context = 0;
    this->ContextType = 0;
    this->ActorClass = NULL;
    this->WidgetClass = NULL;
    this->MiniMapLevel = 0;
}

