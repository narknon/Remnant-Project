#include "AIPathPoint.h"

AAIPathPoint::AAIPathPoint() {
    this->Next = NULL;
    this->WaitTimeMin = 0.00f;
    this->WaitTimeMax = 0.00f;
    this->FacePathPointDirection = false;
}

