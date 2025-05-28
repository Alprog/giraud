module;
#include "imgui.h"
export module gui_panel;

export import std;

export class GuiPanel
{
public:
	void Render()
	{
		ImGui::Begin(GetName().c_str());
		Draw();
		ImGui::End();
	}

protected:
	virtual std::string GetName() const = 0;
	virtual void Draw() = 0;
};