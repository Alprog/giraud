module client;

import app_panel;
import tree_panel;
import table_panel;
import details_panel;

Client& Client::GetInstance()
{
	static Client instance;
	return instance;
}

Client::Client()
	: window{}
	, renderer{ window }
	, gui{ window, renderer }
	, config{}
	, db{}
	, api{ config, db }
{
	gui.AddPanel<AppPanel>(db, api);
	gui.AddPanel<TreePanel>(db, api);
	gui.AddPanel<TablePanel>(db, api);
	gui.AddPanel<DetailsPanel>(db, api);

	gui.ShowDemoPanel();
}

void Client::RunEventLoop()
{
	while (window.ProcessEvents())
	{
		gui.NewFrame();

		gui.PrepareDraw();

		renderer.StartFrame();
		gui.Draw();
		renderer.EndFrame();

		gui.RenderPlatformWindows();

		renderer.Present();
	}

	renderer.WaitForLastSubmittedFrame();
}

