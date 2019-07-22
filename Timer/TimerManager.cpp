#include "TimerManager.h"

#include <Windows.h>
#include <assert.h>
#include "Time.h"

CommonUtilities::TimerManager::TimerManager()
{
	LARGE_INTEGER largeInteger;
	QueryPerformanceFrequency(&largeInteger);
	myFrequency = largeInteger.QuadPart;

	QueryPerformanceCounter(&largeInteger);
	myLastTime = largeInteger.QuadPart * 1000000 / myFrequency;
}


CommonUtilities::TimerManager::~TimerManager()
{
}

void CommonUtilities::TimerManager::Update()
{
	TimeUnit time = GetTime();

	myMasterTimer.AddTime(time);

	for (unsigned int i = 0; i < myTimers.size(); ++i)
	{
		myTimers[i].AddTime(time);
	}


	myLastTime += time;
}


const CommonUtilities::Timer& CommonUtilities::TimerManager::GetMasterTimer() const
{
	return myMasterTimer;
}

CommonUtilities::TimeUnit CommonUtilities::TimerManager::GetTime()
{
	LARGE_INTEGER current;
	QueryPerformanceCounter(&current);

	return (current.QuadPart * 1000000 / myFrequency) - myLastTime;
}

CommonUtilities::TimerHandle CommonUtilities::TimerManager::CreateTimer()
{
	myTimers.push_back(Timer());
	return myTimers.size() - 1;
}


const CommonUtilities::Timer& CommonUtilities::TimerManager::GetTimer(CommonUtilities::TimerHandle aId) const
{
	assert(aId < myTimers.size() && "GetTimer handle out of bounds.");
	return myTimers[aId];
}


void CommonUtilities::TimerManager::PauseAll()
{
	for (unsigned int i = 0; i < myTimers.size(); ++i)
	{
		myTimers[i].Pause();
	}
}

void CommonUtilities::TimerManager::StartAll()
{
	for (unsigned int i = 0; i < myTimers.size(); ++i)
	{
		myTimers[i].Start();
	}
}