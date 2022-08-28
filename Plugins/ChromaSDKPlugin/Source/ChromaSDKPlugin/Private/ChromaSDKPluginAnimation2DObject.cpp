#include "ChromaSDKPluginAnimation2DObject.h"

void UChromaSDKPluginAnimation2DObject::Unload() {
}

bool UChromaSDKPluginAnimation2DObject::IsLoaded() {
    return false;
}

UChromaSDKPluginAnimation2DObject::UChromaSDKPluginAnimation2DObject() {
    this->Device = EChromaSDKDevice2DEnum::DE_Keyboard;
}

