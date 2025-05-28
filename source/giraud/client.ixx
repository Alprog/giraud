export module client;

import native_window;
import gfx_renderer;
import gui_system;
import configuration;
import database;
import edit_api;

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
	Configuration config;
	Database db;
	EditAPI api;
};