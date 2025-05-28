export module client;

import native_window;
import gfx_renderer;
import gui_system;

export class Client
{
public:
	static Client& GetInstance();

	void RunEventLoop();

public:
	Client();

	NativeWindow window;
	GfxRenderer gfxRenderer;
	GuiSystem guiSystem;
};