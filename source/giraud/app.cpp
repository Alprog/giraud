module app;

App& App::GetInstance()
{
	static App instance;
	return instance;
}

App::App()
{
}

void App::RunGameLoop()
{
}

