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

#include "HoudiniApi.h"
#include "HoudiniAssetParameterInt.h"
#include "HoudiniEngineRuntimePrivatePCH.h"
#include "HoudiniAssetComponent.h"
#include "HoudiniEngine.h"
#include "HoudiniEngineUtils.h"

#include "Misc/Variant.h"
#include "Internationalization/Internationalization.h"
#define LOCTEXT_NAMESPACE HOUDINI_LOCTEXT_NAMESPACE 

UHoudiniAssetParameterInt::UHoudiniAssetParameterInt( const FObjectInitializer & ObjectInitializer )
    : Super( ObjectInitializer )
    , ValueMin( TNumericLimits<int32>::Lowest() )
    , ValueMax( TNumericLimits<int32>::Max() )
    , ValueUIMin( TNumericLimits<int32>::Lowest() )
    , ValueUIMax( TNumericLimits<int32>::Max() )
{
    // Parameter will have at least one value.
    Values.AddZeroed( 1 );
}

UHoudiniAssetParameterInt *
UHoudiniAssetParameterInt::Create(
    UObject * InPrimaryObject,
    UHoudiniAssetParameter * InParentParameter,
    HAPI_NodeId InNodeId, const HAPI_ParmInfo & ParmInfo )
{
    UObject * Outer = InPrimaryObject;
    if ( !Outer )
    {
        Outer = InParentParameter;
        if ( !Outer )
        {
            // Must have either component or parent not null.
            check( false );
        }
    }

    UHoudiniAssetParameterInt * HoudiniAssetParameterInt = NewObject< UHoudiniAssetParameterInt >(
        Outer, UHoudiniAssetParameterInt::StaticClass(), NAME_None, RF_Public | RF_Transactional );

    HoudiniAssetParameterInt->CreateParameter( InPrimaryObject, InParentParameter, InNodeId, ParmInfo );
    return HoudiniAssetParameterInt;
}

bool
UHoudiniAssetParameterInt::CreateParameter(
    UObject * InPrimaryObject,
    UHoudiniAssetParameter * InParentParameter,
    HAPI_NodeId InNodeId, const HAPI_ParmInfo & ParmInfo )
{
    if ( !Super::CreateParameter( InPrimaryObject, InParentParameter, InNodeId, ParmInfo ) )
        return false;

    // We can only handle integer type.
    if ( ParmInfo.type != HAPI_PARMTYPE_INT )
        return false;

    // Assign internal Hapi values index.
    SetValuesIndex( ParmInfo.intValuesIndex );

    // Get the actual value for this property.
    Values.SetNumZeroed( TupleSize );
    if ( FHoudiniApi::GetParmIntValues(
        FHoudiniEngine::Get().GetSession(), InNodeId, &Values[ 0 ],
        ValuesIndex, TupleSize ) != HAPI_RESULT_SUCCESS )
    {
        return false;
    }

    // Set min and max for this property.
    if ( ParmInfo.hasMin )
        ValueMin = (int32) ParmInfo.min;

    if ( ParmInfo.hasMax )
        ValueMax = (int32) ParmInfo.max;

    // Set min and max for UI for this property.
    if ( ParmInfo.hasUIMin )
    {
        ValueUIMin = (int32) ParmInfo.UIMin;
    }
    else
    {
        // If it is not set, use supplied min.
        if ( ParmInfo.hasMin )
        {
            ValueUIMin = ValueMin;
        }
        else
        {
            // Min value Houdini uses by default.
            ValueUIMin = HAPI_UNREAL_PARAM_INT_UI_MIN;
        }
    }

    if ( ParmInfo.hasUIMax )
    {
        ValueUIMax = (int32) ParmInfo.UIMax;
    }
    else
    {
        // If it is not set, use supplied max.
        if ( ParmInfo.hasMax )
        {
            ValueUIMax = ValueMax;
        }
        else
        {
            // Max value Houdini uses by default.
            ValueUIMax = HAPI_UNREAL_PARAM_INT_UI_MAX;
        }
    }

    // Get this parameter's unit if it has one
    FHoudiniEngineUtils::HapiGetParameterUnit( InNodeId, ParmId, ValueUnit );

    return true;
}

bool
UHoudiniAssetParameterInt::UploadParameterValue()
{
    if ( FHoudiniApi::SetParmIntValues(
        FHoudiniEngine::Get().GetSession(), NodeId, &Values[ 0 ],
        ValuesIndex, TupleSize) != HAPI_RESULT_SUCCESS )
    {
        return false;
    }

    return Super::UploadParameterValue();
}

bool
UHoudiniAssetParameterInt::SetParameterVariantValue( const FVariant & Variant, int32 Idx, bool bTriggerModify, bool bRecordUndo )
{
    EVariantTypes VariantType = Variant.GetType();
    int32 VariantValue = 0;

    if ( Idx >= 0 && Idx < Values.Num() )
        return false;

    switch ( VariantType )
    {
        case EVariantTypes::Int8:
        case EVariantTypes::Int16:
        case EVariantTypes::Int32:
        case EVariantTypes::Int64:
        case EVariantTypes::UInt8:
        case EVariantTypes::UInt16:
        case EVariantTypes::UInt32:
        case EVariantTypes::UInt64:
        {
            VariantValue = Variant.GetValue< int32 >();
            break;
        }

        default:
        {
            return false;
        }
    }

#if WITH_EDITOR

    FScopedTransaction Transaction(
        TEXT( HOUDINI_MODULE_RUNTIME ),
        LOCTEXT( "HoudiniAssetParameterIntChange", "Houdini Parameter Integer: Changing a value" ),
        PrimaryObject );

    Modify();

    if ( !bRecordUndo )
        Transaction.Cancel();

#endif

    Values[ Idx ] = VariantValue;
    MarkChanged( bTriggerModify );

    return true;
}

TOptional< int32 >
UHoudiniAssetParameterInt::GetValue( int32 Idx ) const
{
    return TOptional< int32 >( Values[ Idx ] );
}

void
UHoudiniAssetParameterInt::SetValue( int32 InValue, int32 Idx, bool bTriggerModify, bool bRecordUndo )
{
    if (!Values.IsValidIndex(Idx))
        return;

    if ( Values[ Idx ] != InValue )
    {

#if WITH_EDITOR

        // If this is not a slider change (user typed in values manually), record undo information.
        FScopedTransaction Transaction(
            TEXT( HOUDINI_MODULE_RUNTIME ),
            LOCTEXT( "HoudiniAssetParameterIntChange", "Houdini Parameter Integer: Changing a value" ),
            PrimaryObject );
        Modify();

        if ( !bRecordUndo )
            Transaction.Cancel();
#endif

        Values[ Idx ] = FMath::Clamp< int32 >( InValue, ValueMin, ValueMax );

        // Mark this parameter as changed.
        MarkChanged( bTriggerModify );
    }
}

int32
UHoudiniAssetParameterInt::GetParameterValue( int32 Idx, int32 DefaultValue ) const
{
    if ( Values.Num() <= Idx )
        return DefaultValue;

    return Values[ Idx ];
}

#if WITH_EDITOR

void
UHoudiniAssetParameterInt::OnSliderMovingBegin( int32 Idx )
{
    bSliderDragged = true;

    // We want to record undo increments only when user lets go of the slider.
    FScopedTransaction Transaction(
        TEXT( HOUDINI_MODULE_RUNTIME ),
        LOCTEXT( "HoudiniAssetParameterIntChange", "Houdini Parameter Float: Changing a value" ),
        PrimaryObject );

    Modify();
}

void
UHoudiniAssetParameterInt::OnSliderMovingFinish( int32 InValue, int32 Idx )
{
    bSliderDragged = false;

    // Mark this parameter as changed.
    MarkChanged(true);
}

#endif

void
UHoudiniAssetParameterInt::Serialize( FArchive & Ar )
{
    // Call base implementation.
    Super::Serialize( Ar );

    Ar.UsingCustomVersion( FHoudiniCustomSerializationVersion::GUID );

    Ar << Values;

    Ar << ValueMin;
    Ar << ValueMax;

    Ar << ValueUIMin;
    Ar << ValueUIMax;
    
    if ( HoudiniAssetParameterVersion >= VER_HOUDINI_PLUGIN_SERIALIZATION_VERSION_PARAMETERS_UNIT )
        Ar << ValueUnit;
}

#undef LOCTEXT_NAMESPACE