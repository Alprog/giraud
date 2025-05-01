module client;

Client& Client::GetInstance()
{
	static Client instance;
	return instance;
}

Client::Client()
	: window{}
	, gfxRenderer{ window }
	, guiSystem{ window, gfxRenderer }
{
}

void Client::RunEventLoop()
{
}

