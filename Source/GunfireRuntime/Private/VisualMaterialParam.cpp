#include "VisualMaterialParam.h"

FVisualMaterialParam::FVisualMaterialParam() {
    this->AllMaterials = false;
    this->AllMeshes = false;
    this->ParameterType = EVisualMaterialParameterType::Scalar;
    this->ScalarValue = 0.00f;
    this->TextureValue = NULL;
    this->EaseValue = EEaseType::EaseIn;
    this->ApplyValue = EParamApply::ApplyOnAdd;
    this->TweenFrom = 0.00f;
    this->TweenTo = 0.00f;
    this->Duration = 0.00f;
    this->Exponent = 0.00f;
}

