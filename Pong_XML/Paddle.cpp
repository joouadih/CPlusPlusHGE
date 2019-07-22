#include "Paddle.h"


Paddle::Paddle(float aX, float aY) :mySprite(0, 0, 0, 32, 96)
{
	myPos.x = aX;
	myPos.y = aY;
}
Paddle::~Paddle()
{
}

void Paddle::Init(float aSpeed, const char* aFileName)
{
	mySpeed = aSpeed;

	HGE* hge = hgeCreate(HGE_VERSION);
	HTEXTURE texture = hge->Texture_Load(aFileName);

	mySprite.SetTexture(texture);
}

void Paddle::Update(bool aUp, bool aDown, float aDelta)
{
	if (aUp == true)
	{
		myPos.y -= mySpeed * aDelta;
	}
	if (aDown == true)
	{
		myPos.y += mySpeed * aDelta;
	}

	if (myPos.y < -50.f)
	{
		myPos.y = -50.f;
	}
	if (myPos.y > 574.f)
	{
		myPos.y = 574.f;
	}
}

void Paddle::Render()
{
	mySprite.Render(myPos.x, myPos.y);
}

hgeRect Paddle::GetRect()
{
	hgeRect rect;
	mySprite.GetBoundingBox(myPos.x, myPos.y, &rect);
	return rect;
}