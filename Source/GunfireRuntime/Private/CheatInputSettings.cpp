#include "CheatInputSettings.h"

UCheatInputSettings::UCheatInputSettings() {
    this->bCheatsEnabled = true;
    this->ActionMappings.AddDefaulted(39);
    this->DebugToggleKeys.AddDefaulted(1);
    this->DebugActionMappings.AddDefaulted(9);
}

