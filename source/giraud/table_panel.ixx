export module table_panel;

import gui_panel;

export class TablePanel : public GuiPanel
{
public:
	using GuiPanel::GuiPanel;

	std::string GetName() const override { return "TablePanel"; }

	void Draw() override
	{

	}
};