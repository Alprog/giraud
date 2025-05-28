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
	, app{ GetPublicGiraudApp() }
{
	gui.AddPanel<AppPanel>();
	gui.AddPanel<TreePanel>();
	gui.AddPanel<TablePanel>();
	gui.AddPanel<DetailsPanel>();

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

