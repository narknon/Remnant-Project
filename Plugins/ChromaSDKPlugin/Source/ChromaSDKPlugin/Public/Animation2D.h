#pragma once

#include "AnimationBase.h"

#if PLATFORM_WINDOWS || PLATFORM_XBOXONE

namespace ChromaSDK
{
	class Animation2D : public AnimationBase
	{
	public:
		Animation2D();
		~Animation2D();
		void Reset();
		EChromaSDKDeviceTypeEnum::Type GetDeviceType();
		EChromaSDKDevice2DEnum::Type GetDevice();
		bool SetDevice(EChromaSDKDevice2DEnum::Type device);
		int GetDeviceId();
		std::vector<FChromaSDKColorFrame2D>& GetFrames();
		int GetFrameCount();
		float GetDuration(unsigned int index);
		void Load();
		void Unload();
		void Play(bool loop);
		void Stop();
		void Update(float deltaTime);
		void ResetFrames();
		int Save(const char* path);
		void SetChromaCustom(bool flag);
		bool UseChromaCustom();
	private:
		EChromaSDKDevice2DEnum::Type _mDevice;
		std::vector<FChromaSDKColorFrame2D> _mFrames;
		bool _mLoop;
		bool _mUseChromaCustom;
	};
}

#endif
