#pragma once
#include "Timer.h"
#include <vector>

namespace CommonUtilities
{
	typedef unsigned int TimerHandle;

	class TimerManager
	{
	public:
		TimerManager();
		~TimerManager();
		const Timer& GetTimer(TimerHandle aId) const;
		const Timer& GetMasterTimer() const;
		TimerHandle CreateTimer();
		void Update();
		void PauseAll();
		void StartAll();
	private:
		Timer myMasterTimer;
		TimeUnit GetTime();
		std::vector<Timer> myTimers;
		TimeUnit myLastTime;
		unsigned long long myFrequency;
	};
}
