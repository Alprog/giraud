module;
#include "imgui.h"
export module app_panel;

import database_panel;
import configuration;

export class AppPanel : public GuiPanel
{
public:
	AppPanel(Configuration& config)
		: configa{ config }
	{
	}

	std::string GetName() const override { return "AppPanel"; }

	void Draw() override
	{
		auto& app = configa.app;

		ImGui::Text(app.id.c_str());

		ImGui::Text(app.redirect_uri.c_str());

	}

	Configuration& configa;
};