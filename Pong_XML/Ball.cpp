#include "Ball.h"
#include <cmath>

Ball::Ball() : mySprite(0, 0, 0, 32, 32)
{
	
}

Ball::~Ball()
{
}


void Ball::Init(float aTotalSpeed, float aSpeedIncrease, const char* aFileName)
{
	myTotalSpeedStart = aTotalSpeed;
	mySpeedIncrease = aSpeedIncrease;

	HGE* hge = hgeCreate(HGE_VERSION);
	mySprite.SetTexture(hge->Texture_Load(aFileName));

	myPos.x = 400;
	myPos.y = 300;
	myAngle = 150;
	myTotalSpeed = 5;
	mySpeedX = 1;
}


void Ball::Update(bool aBounceToRight, bool aBounceToLeft, float aDelta)
{

	myTotalSpeed += mySpeedIncrease * aDelta;

	int TestShit = (mySpeedX * aDelta) * 210;
	bool test = false;



	if (aBounceToRight == true)
	{
		myDirection = true;
	}
	else if (aBounceToLeft == true)
	{
		myDirection = false;
	}


	if (myDirection == true)
	{
		myPos.x += TestShit;
		myPos.y += TestShit-1;
	}
	else
	{
		myPos.x -= TestShit;
		myPos.y -= TestShit-1;
	}



	

}

void Ball::Render()
{
	mySprite.Render(myPos.x, myPos.y);
}

hgeRect Ball::GetRect()
{
	hgeRect rect;
	mySprite.GetBoundingBox(myPos.x, myPos.y, &rect);
	return rect;
}

bool Ball::GoalLeft()
{
	return myPos.x < -20.f;
}

bool Ball::GoalRight()
{
	return myPos.x > 800.f;
}