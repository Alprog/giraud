module client;

Client& Client::GetInstance()
{
	static Client instance;
	return instance;
}

Client::Client()
	: window{}
	, gfxRenderer{ window }
{
}

void Client::RunEventLoop()
{
}

