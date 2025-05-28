export module client;

import native_window;
import gfx_renderer;
import gui_system;
import jira_app;

export class Client
{
public:
	static Client& GetInstance();

	void RunEventLoop();

private:
	Client();

	NativeWindow window;
	GfxRenderer renderer;
	GuiSystem gui;
	JiraApp app;
};