/*-------------------------------------------------------------

	[main.cpp]
	Author : èoçá„ƒëæ

--------------------------------------------------------------*/
#include <Windows.h>
#include "Application.h"

int APIENTRY WinMain(HINSTANCE h, HINSTANCE p, LPSTR l, int c)
{
	auto& app = Application::GetInstance();
	app.Init(h);
	app.Run();
	return 0;
}