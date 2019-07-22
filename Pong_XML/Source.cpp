#include <hge.h>
#include <stdlib.h>
#include "Game.h"
HGE* hge = nullptr;


int WINAPI WinMain(HINSTANCE aHinstance, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_WINDOWED, false);
	hge->System_SetState(HGE_HIDEMOUSE, true);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_FPS, HGEFPS_VSYNC);
	hge->System_SetState(HGE_TITLE, "Pong - The Game");
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_HIDEMOUSE, true);



	if (hge->System_Initiate())
	{
		Game game;
		game.Init(GetActiveWindow(), aHinstance, DISCL_NONEXCLUSIVE, DISCL_NONEXCLUSIVE);


		bool quit = false;

		while (quit == false)
		{
			quit = game.Update();
			hge->Gfx_BeginScene();

			game.Render();

			hge->Gfx_EndScene();


			MSG message;
			if (hge->System_GetState(HGE_HWNDPARENT) == false)
			{
				while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
				{
					if (message.message == WM_QUIT)
					{
						quit = true;
					}
					else
					{
						DispatchMessage(&message);
					}
				}
			}
		}
	}
	else
	{
		MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}

	hge->System_Shutdown();
	hge->Release();

	return 0;
}