module;
#include "imgui.h"
#include <windows.h>
#include <shellapi.h>
export module login_panel;

import database_panel;
import configuration;

export class LoginPanel : public GuiPanel
{
public:
	LoginPanel(Configuration& config)
		: config{ config }
	{
	}

	std::string GetName() const override { return "LoginPanel"; }

	void Draw() override
	{
		if (ImGui::Button("Login"))
		{
			auto authUrl = config.app.getAuthUrl();
			ShellExecuteA(0, 0, authUrl.c_str(), 0, 0, SW_SHOW);
		}
	}

	Configuration& config;
};