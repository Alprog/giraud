export module tree_panel;

import gui_panel;

export class TreePanel : public GuiPanel
{
	std::string GetName() const override { return "TreePanel"; }

	void Draw() override
	{

	}
};