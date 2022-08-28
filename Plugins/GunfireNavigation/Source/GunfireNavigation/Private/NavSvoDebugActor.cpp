#include "NavSvoDebugActor.h"

ANavSvoDebugActor::ANavSvoDebugActor() {
    this->bTestPath = true;
    this->bTestRaycast = true;
    this->NumPathNodesSearched = 0;
    this->PathSearchTime = 0.00f;
    this->bIsPartialPath = false;
    this->bPathExists = false;
    this->bPathNodeLimitReached = false;
    this->MaxPathSearchNodes = 4096;
    this->HeuristicScale = 20.00f;
    this->NodeSizeCompensation = 1.00f;
    this->BlockedNodeCompensation = 1.00f;
    this->bAllowPartialPath = true;
    this->bPathStringPull = false;
    this->bDrawPath = true;
    this->bDrawPathSearch = false;
    this->PathSearchDisplayCount = 0;
    this->bAutoIncrementPathSearch = true;
    this->PathSearchDisplayRate = 0.00f;
    this->bDrawRaycast = false;
    this->bDrawAffectedNodes = true;
    this->NavData = NULL;
    this->StartLocationActor = NULL;
    this->EndLocationActor = NULL;
}

