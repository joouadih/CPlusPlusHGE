#pragma once
#pragma comment(lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")

#include <dinput.h>

namespace CommonUtilities
{
	struct Position
	{
		double x = 0;
		double y = 0;
		double z = 0;
	};

	class InputWrapper
	{
	public:
		InputWrapper();
		~InputWrapper();

		void Init(HWND aHwnd, HINSTANCE aHInstance, DWORD aKeyCoopFlags, DWORD aMouseCoopFlags);

		double GetMouseDX() const;
		double GetMouseDY() const;
		double GetMouseDZ() const; //scrollwheel

		const Position& GetMousePosition() const;

		bool MouseDown(int aButton) const; //specifik musknapp nere this frame
		bool MouseUp(int aButton) const;
		bool MouseIsPressed(int aButton) const; //musknapp nere 

		bool KeyDown(unsigned int aKey) const; //Returns true if specified key is down THIS FRAME
		bool KeyUp(unsigned int aKey) const;
		bool KeyIsPressed(unsigned int aKey) const; //Returns true if specified key is down 

		void Update();

	private:
		void CapturePreviousState();

		LPDIRECTINPUT8 myDirectInput;
		LPDIRECTINPUTDEVICE8 myKeyboardDevice;
		UCHAR myKeyState[256];
		UCHAR myPreviousKeyState[256];

		LPDIRECTINPUTDEVICE8 myMouseDevice;
		DIMOUSESTATE myMouseState;
		DIMOUSESTATE myPreviousMouseState;

		Position myMousePos;

		HWND myWindowHandler;
	};
}
