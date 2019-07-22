#include "Game.h"
#include "tinyXML2/tinyxml2.h"

Game::Game():
myLeftPaddle(10.f, 268.f),
myRightPaddle(760.f, 268.f),
myBall(),
myBackgroundInGame(0, 0.f, 0.f, 1024.f, 1024.f)
{
	HGE* hge = hgeCreate(HGE_VERSION);
	myGameOver = false;

	tinyxml2::XMLDocument doc;

	doc.LoadFile("XML/config.xml");

	if (tinyxml2::XMLElement* root = doc.FirstChildElement("root"))
	{
		if (tinyxml2::XMLElement* element = root->FirstChildElement("gameBackground"))
		{
			HTEXTURE texture = hge->Texture_Load(element->Attribute("file"));
			myBackgroundInGame.SetTexture(texture);
		}
		if (tinyxml2::XMLElement* element = root->FirstChildElement("ball"))
		{
			myBall.Init(static_cast<float>(atof(element->Attribute("speed"))), static_cast<float>(atof(element->Attribute("speedIncrease"))), element->Attribute("file"));
		}
		if (tinyxml2::XMLElement* element = root->FirstChildElement("paddle"))
		{
			myLeftPaddle.Init(element->FloatAttribute("speed"), element->Attribute("file"));
			myRightPaddle.Init(element->FloatAttribute("speed"), element->Attribute("file"));
		}
	}

	myBackgroundInGame.SetHotSpot(400.f, 300.f);

}


Game::~Game()
{
}

void Game::Init(HWND aHwnd, HINSTANCE aHInstance, DWORD aKeyCoopFlags, DWORD aMouseCoopFlags)
{
	myInputWrapper.Init(aHwnd, aHInstance, aKeyCoopFlags, aMouseCoopFlags);
}

//Main update function
bool Game::Update()
{

	myTimerManager.Update();
	myInputWrapper.Update();

	if (myInputWrapper.KeyDown(DIK_ESCAPE) == true)
	{
		return true;
	}

	if (myInputWrapper.KeyDown(DIK_RETURN) == true)
	{
		if (myGameOver == true)
		{
			myGameOver = false;
		}
	}

	myLeftPaddle.Update(myInputWrapper.KeyIsPressed(DIK_W), myInputWrapper.KeyIsPressed(DIK_S), myTimerManager.GetMasterTimer().GetTime().GetFrameTime());
	myRightPaddle.Update(myInputWrapper.KeyIsPressed(DIK_UP), myInputWrapper.KeyIsPressed(DIK_DOWN), myTimerManager.GetMasterTimer().GetTime().GetFrameTime());

	
	float offset = 0;
	bool colLeft = Collision(myLeftPaddle.GetRect(), myBall.GetRect());
	bool colRight = Collision(myRightPaddle.GetRect(), myBall.GetRect());
	myBall.Update(colLeft, colRight, myTimerManager.GetMasterTimer().GetTime().GetFrameTime());
	
	
	//What happens when the someone wins? 
	if (myBall.GoalLeft() == true)
	{
		
	}

	if (myBall.GoalRight() == true)
	{
		
	}



	return false;

}

//Main render function - Eq. Draw
void Game::Render()
{
	myBackgroundInGame.RenderEx(400.f, 300.f, 0, 1.f, 1.f);
	myLeftPaddle.Render();
	myRightPaddle.Render();
	myBall.Render();

}

bool Game::Collision(hgeRect aFirstRect, hgeRect aSecondRect)
{
	if (aFirstRect.x1 > aSecondRect.x2)
	{
		return false;
	}
	if (aFirstRect.x2 < aSecondRect.x1)
	{
		return false;
	}
	if (aFirstRect.y1 > aSecondRect.y2)
	{
		return false;
	}
	if (aFirstRect.y2 < aSecondRect.y1)
	{
		return false;
	}

	float firstPos = (aFirstRect.y1 + aFirstRect.y2) / 2;
	float secondPos = (aSecondRect.y1 + aSecondRect.y2) / 2;

	float max = 48.0f; // (paddleHeight + ballHeight) / 2

	return true;

}