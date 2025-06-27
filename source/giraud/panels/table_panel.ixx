module;
#include "imgui.h"
export module table_panel;

import database_panel;

export class TablePanel : public DatabasePanel
{
public:
	using DatabasePanel::DatabasePanel;

	std::string GetName() const override { return "TablePanel"; }

	void Draw() override
	{
	}
};