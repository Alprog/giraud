export module client;

import platform_window;

export class Client
{
public:
	static Client& GetInstance();

	void RunEventLoop();

public:
	Client();

	PlatformWindow window;
};