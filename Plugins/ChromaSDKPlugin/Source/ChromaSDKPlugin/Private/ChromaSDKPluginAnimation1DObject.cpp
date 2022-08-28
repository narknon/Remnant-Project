#include "ChromaSDKPluginAnimation1DObject.h"

void UChromaSDKPluginAnimation1DObject::Unload() {
}

bool UChromaSDKPluginAnimation1DObject::IsLoaded() {
    return false;
}

UChromaSDKPluginAnimation1DObject::UChromaSDKPluginAnimation1DObject() {
    this->Device = EChromaSDKDevice1DEnum::DE_ChromaLink;
}

