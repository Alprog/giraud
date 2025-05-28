export module tree_panel;

import database_panel;

export class TreePanel : public DatabasePanel
{
public:
	using DatabasePanel::DatabasePanel;

	std::string GetName() const override { return "TreePanel"; }

	void Draw() override
	{

	}
};