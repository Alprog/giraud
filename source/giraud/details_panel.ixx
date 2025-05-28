export module details_panel;

import gui_panel;

export class DetailsPanel : public GuiPanel
{
public:
	using GuiPanel::GuiPanel;

	std::string GetName() const override { return "DetailsPanel"; }

	void Draw() override
	{

	}
};