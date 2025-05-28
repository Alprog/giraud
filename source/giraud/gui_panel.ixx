module;
#include "imgui.h"
export module gui_panel;

export import std;
export import database;
export import edit_api;

export class GuiPanel
{
public:
	GuiPanel(const Database& database, EditAPI& api)
		: database{ database }
		, api{ api }
	{
	}

	void Render()
	{
		ImGui::Begin(GetName().c_str());
		Draw();
		ImGui::End();
	}

protected:
	const Database& database;
	EditAPI& api;

	virtual std::string GetName() const = 0;
	virtual void Draw() = 0;
};