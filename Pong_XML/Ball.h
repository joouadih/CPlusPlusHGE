#pragma once
#include <hgesprite.h>
#include "Struct.h"

class Ball
{
	public:
		Ball();
		~Ball();

		void Init(float aTotalSpeed, float aSpeedIncrease, const char* aFileName);

		void Update(bool aBounceToRight, bool aBounceToLeft, float aDelta);

		void Render();

		hgeRect GetRect();

		bool GoalLeft();
		bool GoalRight();

	private:
	hgeSprite mySprite;
	float mySpeedX;
	float mySpeedY;
	float mySpeedIncrease;
	float myAngle;
	float myTotalSpeed;
	float myTotalSpeedStart;
	bool myDirection;
	Pos myPos;
};

