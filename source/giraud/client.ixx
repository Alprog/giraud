export module client;

import native_window;
import gfx_renderer;
import gui_system;
import configuration;
import network;
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
	Network network;
	Database db;
	EditAPI api;
};