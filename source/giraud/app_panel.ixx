export module app_panel;

import gui_panel;

export class AppPanel : public GuiPanel
{
	std::string GetName() const override { return "AppPanel"; }

	void Draw() override
	{

	}
};