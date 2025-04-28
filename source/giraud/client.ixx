export module client;

import platform_window;
import gfx_renderer;

export class Client
{
public:
	static Client& GetInstance();

	void RunEventLoop();

public:
	Client();

	PlatformWindow window;
	GfxRenderer gfxRenderer;
};