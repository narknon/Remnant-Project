/*
* Copyright (c) <2017> Side Effects Software Inc.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*/

#pragma once

#include "HoudiniEngineTask.h"


namespace EHoudiniEngineTaskState
{
    enum Type
    {
        None,

        Processing,
        FinishedInstantiation,
        FinishedInstantiationWithErrors,
        FinishedCooking,
        FinishedCookingWithErrors,
        Aborted
    };
}

struct HOUDINIENGINERUNTIME_API FHoudiniEngineTaskInfo
{
    /** Constructors. **/
    FHoudiniEngineTaskInfo();
    FHoudiniEngineTaskInfo(
        HAPI_Result InResult, HAPI_NodeId InAssetId,
        EHoudiniEngineTaskType::Type InTaskType,
        EHoudiniEngineTaskState::Type InTaskState );

    /** Current HAPI result. **/
    HAPI_Result Result;

    /** Current Asset Id. **/
    HAPI_NodeId AssetId;

    /** Type of task. **/
    EHoudiniEngineTaskType::Type TaskType;

    /** Current status. **/
    EHoudiniEngineTaskState::Type TaskState;

    /** String used for status / progress bar. **/
    FText StatusText;

    /** Is set to true if corresponding task was issued for loaded component. **/
    bool bLoadedComponent;
};
