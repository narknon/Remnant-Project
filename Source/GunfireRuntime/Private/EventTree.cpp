#include "EventTree.h"
#include "Dialog_Speaker.h"

UEventTree::UEventTree() {
    this->DefaultSpeaker = UDialog_Speaker::StaticClass();
    this->DefaultVocalRange = NULL;
}

