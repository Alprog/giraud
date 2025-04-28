module client;

Client& Client::GetInstance()
{
	static Client instance;
	return instance;
}

Client::Client()
{
}

void Client::RunEventLoop()
{
}

