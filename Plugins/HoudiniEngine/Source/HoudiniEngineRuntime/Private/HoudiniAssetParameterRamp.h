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
*/

#pragma once

#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterMultiparm.h"
#include "Tickable.h"
#include "Curves/CurveFloat.h"
#include "Curves/CurveLinearColor.h"
#include "HoudiniAssetParameterRamp.generated.h"


class UCurveBase;
class UHoudiniAssetParameterRamp;
class UHoudiniAssetParameterFloat;
class UHoudiniAssetParameterColor;
class UHoudiniAssetParameterChoice;
class SCurveEditor;

UCLASS(BlueprintType)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterRampCurveFloat : public UCurveFloat
{
    GENERATED_UCLASS_BODY()

    public:

        /** Set parent ramp parameter. **/
        void SetParentRampParameter( UHoudiniAssetParameterRamp * InHoudiniAssetParameterRamp );

    /** FCurveOwnerInterface methods. **/
    public:

#if WITH_EDITOR

        virtual void OnCurveChanged( const TArray< FRichCurveEditInfo > & ChangedCurveEditInfos ) override;

#endif

    protected:

        /** Parent ramp parameter. **/
        TWeakObjectPtr<UHoudiniAssetParameterRamp> HoudiniAssetParameterRamp;
};

namespace EHoudiniAssetParameterRampCurveColorEvent
{
    enum Type
    {
        None = 0,
        MoveStop,
        ChangeStopTime,
        ChangeStopColor,
        AddStop,
        RemoveStop
    };
}

UCLASS( BlueprintType )
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterRampCurveColor : public UCurveLinearColor, public FTickableGameObject
{
    GENERATED_UCLASS_BODY()


    public:

        /** Set parent ramp parameter. **/
        void SetParentRampParameter( UHoudiniAssetParameterRamp * InHoudiniAssetParameterRamp );

        /** Return the current type of event. **/
        EHoudiniAssetParameterRampCurveColorEvent::Type GetColorEvent() const;

        /** Reset the current type of event. **/
        void ResetColorEvent();


    /** FCurveOwnerInterface methods. **/
    public:

#if WITH_EDITOR

        virtual void OnCurveChanged( const TArray< FRichCurveEditInfo > & ChangedCurveEditInfos ) override;

#endif

    /** UObject methods. **/
    public:

        virtual bool Modify( bool bAlwaysMarkDirty );

    /** FTickableGameObject methods. **/
    public:

        virtual bool IsTickableInEditor() const;
        virtual bool IsTickableWhenPaused() const;
        virtual void Tick( float DeltaTime ) override;
        virtual TStatId GetStatId() const override;
        virtual bool IsTickable() const override;

    protected:

        /** Attempt to map current editor transaction type to curve transactions. **/
        EHoudiniAssetParameterRampCurveColorEvent::Type GetEditorCurveTransaction() const;

    protected:

        /** Parent ramp parameter. **/
        TWeakObjectPtr<UHoudiniAssetParameterRamp> HoudiniAssetParameterRamp;

        /** Current event. **/
        EHoudiniAssetParameterRampCurveColorEvent::Type ColorEvent;
};

namespace EHoudiniAssetParameterRampKeyInterpolation
{
    enum Type
    {
        Constant = 0,
        Linear,
        CatmullRom,
        MonotoneCubic,
        Bezier,
        BSpline,
        Hermite
    };
}

UCLASS()
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterRamp : public UHoudiniAssetParameterMultiparm
{
    GENERATED_UCLASS_BODY()

    friend struct FHoudiniParameterDetails;

    public:

        virtual ~UHoudiniAssetParameterRamp();

        /** Create instance of this class. **/
        static UHoudiniAssetParameterRamp * Create(
            UObject * InPrimaryObject,
            UHoudiniAssetParameter * InParentParameter,
            HAPI_NodeId InNodeId, const HAPI_ParmInfo & ParmInfo );

    public:

        /** Create this parameter from HAPI information. **/
        virtual bool CreateParameter(
            UObject * InPrimaryObject,
            UHoudiniAssetParameter * InParentParameter,
            HAPI_NodeId InNodeId, const HAPI_ParmInfo & ParmInfo) override;

        /** Notification from component that all child parameters have been created. **/
        virtual void NotifyChildParametersCreated();

        /** Duplicates this object as well as owned subobjects */
        virtual UHoudiniAssetParameter * Duplicate( UObject* InOuter ) override;

    /** UObject methods. **/
    public:

        virtual void Serialize( FArchive & Ar ) override;
        virtual void PostLoad() override;
        static void AddReferencedObjects( UObject * InThis, FReferenceCollector & Collector );

        /** Called when curve editing is finished and update should take place. **/
        void OnCurveEditingFinished();

        /** Called when float ramp parameter changes via user interface. **/
        void OnCurveFloatChanged( UHoudiniAssetParameterRampCurveFloat * CurveFloat );

        /** Called when color ramp parameter changes via user interface. **/
        void OnCurveColorChanged( UHoudiniAssetParameterRampCurveColor * CurveColor );

    protected:

        /** Populate curve with point data. **/
        void GenerateCurvePoints();

        /** Return number of ramp keys. **/
        int32 GetRampKeyCount() const;

        /** Translate choice value into interpolation enumeration. **/
        EHoudiniAssetParameterRampKeyInterpolation::Type
        TranslateChoiceKeyInterpolation( UHoudiniAssetParameterChoice * ChoiceParam ) const;

        /** Return Unreal ramp key interpolation type from Houdini ramp key interpolation type. **/
        ERichCurveInterpMode TranslateHoudiniRampKeyInterpolation(
            EHoudiniAssetParameterRampKeyInterpolation::Type KeyInterpolation ) const;

        /** Return Houdini ramp key interpolation type from Unreal ramp key interpolation type. **/
        EHoudiniAssetParameterRampKeyInterpolation::Type
        TranslateUnrealRampKeyInterpolation( ERichCurveInterpMode RichCurveInterpMode ) const;

        /** Retrieve ramp key parameters for a given index of a float ramp. **/
        bool GetRampKeysCurveFloat(
            int32 Idx, UHoudiniAssetParameterFloat *& Position,
            UHoudiniAssetParameterFloat *& Value,
            UHoudiniAssetParameterChoice *& Interp ) const;

        /** Retrieve ramp key parameters for a given index of a color ramp. **/
        bool GetRampKeysCurveColor(
            int32 Idx, UHoudiniAssetParameterFloat *& Position,
            UHoudiniAssetParameterColor *& Value,
            UHoudiniAssetParameterChoice *& Interp ) const;

    protected:

        //! Default spline interpolation method.
        static const EHoudiniAssetParameterRampKeyInterpolation::Type DefaultSplineInterpolation;

        //! Default unknown interpolation method.
        static const EHoudiniAssetParameterRampKeyInterpolation::Type DefaultUnknownInterpolation;

    protected:

        //! Curves which are being edited.
        UHoudiniAssetParameterRampCurveFloat * HoudiniAssetParameterRampCurveFloat;
        UHoudiniAssetParameterRampCurveColor * HoudiniAssetParameterRampCurveColor;
#if WITH_EDITOR
        TSharedPtr<SCurveEditor> CurveEditor;
#endif

        //! Set to true if this ramp is a float ramp. Otherwise is considered a color ramp.
        bool bIsFloatRamp;

        //! Set to true if the curve has changed through Slate interaction.
        bool bIsCurveChanged;

        //! Set to true when curve data needs to be re-uploaded to Houdini Engine.
        bool bIsCurveUploadRequired;
};
