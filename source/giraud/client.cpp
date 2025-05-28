module client;

Client& Client::GetInstance()
{
	static Client instance;
	return instance;
}

Client::Client()
	: window{}
	, gfxRenderer{ window }
	, guiSystem{ window, gfxRenderer }
{
	guiSystem.ShowDemoWindow();
}

void Client::RunEventLoop()
{
	while (window.ProcessEvents())
	{
		guiSystem.NewFrame();

		guiSystem.PrepareDraw();

		FrameContext* frameCtx = gfxRenderer.StartFrame();
		guiSystem.Draw();
		gfxRenderer.EndFrame(frameCtx);

		guiSystem.RenderPlatformWindows();

		gfxRenderer.Present(frameCtx);
	}

	gfxRenderer.WaitForLastSubmittedFrame();

}

