export module details_panel;

import database_panel;

export class DetailsPanel : public DatabasePanel
{
public:
	using DatabasePanel::DatabasePanel;

	std::string GetName() const override { return "DetailsPanel"; }

	void Draw() override
	{

	}
};