#pragma once
#pragma once
#include <hgerect.h>
#include "InputWrapper.h"
#include "TimerManager.h"

#include "Paddle.h"
#include "Ball.h"


class Game
{
	public:
	Game();
	~Game();

	void Init(HWND aHwnd, HINSTANCE aHInstance, DWORD aKeyCoopFlags, DWORD aMouseCoopFlags);
	bool Update();
	void Render();

	bool Collision(hgeRect aFirstRect, hgeRect aSecondRect);


	private:
		bool IsCollision(hgeRect aFirstRect, hgeRect aSecondRect);

		bool myGameOver;
		CommonUtilities::InputWrapper myInputWrapper;
		CommonUtilities::TimerManager myTimerManager;
		Paddle myLeftPaddle;
		Paddle myRightPaddle;
		Ball myBall;

		hgeSprite myBackgroundInGame;
};

