#pragma once
#include "struct.h"
#include <hgesprite.h>

class Paddle
{
	public:
		Paddle(float aX, float aY);
		~Paddle();

		void Init(float aSpeed, const char* aFileName);
		void Update(bool aUp, bool aDown, float aDelta);
		void Render();
		hgeRect GetRect();

	private:
		hgeSprite mySprite;
		Pos myPos;
		float mySpeed;

};

