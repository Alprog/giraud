module;
#include <SDL.h>
#include <SDL_syswm.h>
module app;

App& App::GetInstance()
{
	static App instance;
	return instance;
}

App::App()
{
	SDL_Init(SDL_INIT_VIDEO);
}

void App::RunGameLoop()
{
}

