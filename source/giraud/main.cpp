
import client;

#include "Windows.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Client::GetInstance().RunEventLoop();
	return 0;
}
