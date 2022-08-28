#include "ChromaThread.h" //___HACK_UE4_VERSION_4_16_OR_GREATER
#include "ChromaSDKPluginPrivatePCH.h"
//#include "ChromaThread.h" //___HACK_UE4_VERSION_4_15_OR_LESS
#include <chrono>

using namespace ChromaSDK;
using namespace std;
using namespace std::chrono;

ChromaThread* ChromaThread::_sInstance = new ChromaThread();

ChromaThread::ChromaThread()
{
	_mThread = nullptr;
	_mWaitForExit = true;
}

ChromaThread* ChromaThread::Instance()
{
	return _sInstance;
}

void ChromaThread::ProcessAnimations(float deltaTime)
{
	std::lock_guard<std::mutex> guard(_mMutex);

	// update animations
	vector<AnimationBase*> doneList = vector<AnimationBase*>();
	for (unsigned int i = 0; i < _mAnimations.size(); ++i)
	{
		AnimationBase* animation = _mAnimations[i];
		if (animation != nullptr)
		{
			animation->Update(deltaTime);
			// no need to update animations that are no longer playing
			if (!animation->IsPlaying())
			{
				doneList.push_back(animation);
			}
		}
	}

	for (int i = 0; i < doneList.size(); ++i)
	{
		AnimationBase* animation = doneList[i];
		if (animation != nullptr)
		{
			auto it = find(_mAnimations.begin(), _mAnimations.end(), animation);
			if (it != _mAnimations.end())
			{
				_mAnimations.erase(it);
			}
		}
	}
}

void ChromaThread::ChromaWorker()
{
	// get current time
	high_resolution_clock::time_point timer = high_resolution_clock::now();
	high_resolution_clock::time_point timerLast = high_resolution_clock::now();

	_mWaitForExit = true;

	while (_mWaitForExit)
	{
		// get current time
		timer = high_resolution_clock::now();

		// get time in seconds
		duration<double, std::milli> time_span = timer - timerLast;
		float deltaTime = (float)(time_span.count() / 1000.0f);
		timerLast = timer;

		ProcessAnimations(deltaTime);

		if (!_mWaitForExit)
		{
			break;
		}

		std::this_thread::sleep_for(std::chrono::microseconds(1));
	}

	_mThread = nullptr;
}

void ChromaThread::Start()
{
	if (_mThread != nullptr)
	{
		return;
	}
	_mThread = new thread(&ChromaThread::ChromaWorker, this);
	_mThread->detach();
}

void ChromaThread::Stop()
{
	_mWaitForExit = false;

	std::lock_guard<std::mutex> guard(_mMutex);
	_mAnimations.clear();
}

void ChromaThread::AddAnimation(AnimationBase* animation)
{
	std::lock_guard<std::mutex> guard(_mMutex);
	// Add animation if it's not found
	if (std::find(_mAnimations.begin(), _mAnimations.end(), animation) == _mAnimations.end())
	{
		_mAnimations.push_back(animation);
	}
	
}

void ChromaThread::RemoveAnimation(AnimationBase* animation)
{
	std::lock_guard<std::mutex> guard(_mMutex);
	if (animation != nullptr)
	{
		auto it = std::find(_mAnimations.begin(), _mAnimations.end(), animation);
		if (it != _mAnimations.end())
		{
			_mAnimations.erase(it);
		}
	}
}

int ChromaThread::GetAnimationCount()
{
	lock_guard<mutex> guard(_mMutex);
	return _mAnimations.size();
}

int ChromaThread::GetAnimationId(int index)
{
	lock_guard<mutex> guard(_mMutex);
	if (index < 0)
	{
		return -1;
	}
	if (index < _mAnimations.size())
	{
		AnimationBase* animation = _mAnimations[index];
		if (animation != nullptr)
		{
			return IChromaSDKPlugin::Get().GetAnimationIdFromInstance(animation);
		}
	}
	return -1;
}
