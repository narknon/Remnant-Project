#include "AnimNotifyState_MaterialParam.h"

UAnimNotifyState_MaterialParam::UAnimNotifyState_MaterialParam() {
    this->Material = NULL;
    this->from = 0.00f;
    this->to = 1.00f;
    this->EaseType = EEaseType::EaseInOut;
    this->Exponent = 3.00f;
}

