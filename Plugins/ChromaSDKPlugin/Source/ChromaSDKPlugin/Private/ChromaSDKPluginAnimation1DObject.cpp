// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ChromaSDKPluginAnimation1DObject.h" //___HACK_UE4_VERSION_4_16_OR_GREATER
#include "ChromaSDKPluginPrivatePCH.h"
#include "ChromaSDKPluginBPLibrary.h"
//#include "ChromaSDKPluginAnimation1DObject.h" //___HACK_UE4_VERSION_4_15_OR_LESS

#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
#include "AllowWindowsPlatformTypes.h" 
#endif

//UChromaSDKPluginAnimation1DObject::UChromaSDKPluginAnimation1DObject(const FPostConstructInitializeProperties& PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
//	: Super(PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
UChromaSDKPluginAnimation1DObject::UChromaSDKPluginAnimation1DObject(const FObjectInitializer& ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
	: Super(ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
{
}

bool UChromaSDKPluginAnimation1DObject::IsLoaded()
{
#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	return _mIsLoaded;
#else
	return false;
#endif
}

void UChromaSDKPluginAnimation1DObject::Unload()
{
#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	if (!_mIsLoaded)
	{
		//ignore
		return;
	}

	for (int i = 0; i < _mEffects.Num(); ++i)
	{
		FChromaSDKEffectResult& effect = _mEffects[i];
		int result = UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(effect.EffectId);
		if (result != 0)
		{
			UE_LOG(LogTemp, Error, TEXT("UChromaSDKPluginAnimation1DObject::Unload Failed to delete effect!"));
		}
	}
	_mEffects.Reset();
	_mIsLoaded = false;
#endif
}

void UChromaSDKPluginAnimation1DObject::Tick(float deltaTime)
{
#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	_mTime += deltaTime;
	float nextTime = GetDuration(_mCurrentFrame);
	if (nextTime < _mTime)
	{
		_mTime = 0.0f;
		++_mCurrentFrame;
		if (_mCurrentFrame < _mEffects.Num())
		{
			//UE_LOG(LogTemp, Log, TEXT("UChromaSDKPluginAnimation1DObject::Tick SetEffect."));
			FChromaSDKEffectResult& effect = _mEffects[_mCurrentFrame];
			int result = UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(effect.EffectId);
			if (result != 0)
			{
				UE_LOG(LogTemp, Error, TEXT("UChromaSDKPluginAnimation1DObject::Tick Failed to set effect!"));
			}
		}
		else
		{
			//UE_LOG(LogTemp, Log, TEXT("UChromaSDKPluginAnimation1DObject::Tick Animation Complete."));
			_mIsPlaying = false;
			_mTime = 0.0f;
			_mCurrentFrame = 0;

			// execute the complete event if set
			_mOnComplete.ExecuteIfBound(this);
		}
	}
#endif
}

bool UChromaSDKPluginAnimation1DObject::IsTickable() const
{
#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	return _mIsPlaying;
#else
	return false;
#endif
}

bool UChromaSDKPluginAnimation1DObject::IsTickableInEditor() const
{
#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	return true;
#else
	return false;
#endif
}

bool UChromaSDKPluginAnimation1DObject::IsTickableWhenPaused() const
{
	return false;
}

TStatId UChromaSDKPluginAnimation1DObject::GetStatId() const
{
	return TStatId();
}

float UChromaSDKPluginAnimation1DObject::GetDuration(int index)
{
	if (index < Frames.Num())
	{
		FChromaSDKColorFrame1D& frame = Frames[index];
		return frame.Duration;
	}
	return 0.0f;
}

#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
#include "HideWindowsPlatformTypes.h" 
#endif
