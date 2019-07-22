#include "Time.h"

CommonUtilities::Time::Time(CommonUtilities::TimeUnit aMicroSeconds, CommonUtilities::TimeUnit aFrameMicroSeconds)
{
	myMicroSeconds = aMicroSeconds;
	myFrameMicroSeconds = aFrameMicroSeconds;
}

CommonUtilities::Time::~Time()
{
}