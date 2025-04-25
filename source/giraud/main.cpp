
#include <SDL.h>

import app;

int main(int argc, char* argv[])
{
	App& app = App::GetInstance();
	app.RunGameLoop();

	return 0;
}
