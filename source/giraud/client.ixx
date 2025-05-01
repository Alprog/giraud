export module client;

import platform_window;
import gfx_renderer;
import gui_system;

export class Client
{
public:
	static Client& GetInstance();

	void RunEventLoop();

public:
	Client();

	PlatformWindow window;
	GfxRenderer gfxRenderer;
	GuiSystem guiSystem;
};