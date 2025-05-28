module;
#include "imgui.h"
#include <windows.h>
#include <shellapi.h>
export module user_panel;

import database_panel;
import configuration;

export class UserPanel : public GuiPanel
{
public:
	UserPanel(Configuration& config)
		: config{ config }
	{
	}

	std::string GetName() const override { return "UserPanel"; }

	void Draw() override
	{
		if (ImGui::Button("Login"))
		{
			auto authUrl = config.app.getAuthUrl();
			ShellExecuteA(0, 0, authUrl.c_str(), 0, 0, SW_SHOW);
		}

		if (ImGui::Button("Login2"))
		{
			ImGui::OpenPopup("Login");
		}

		auto Flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize;

		const ImVec2 center = ImGui::GetMainViewport()->GetCenter();
		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
		if (ImGui::BeginPopupModal("Login", nullptr, Flags))
		{
			ImGui::Text("Paste here auth code from browser:");


			const int bufferSize = 1024 * 16;
			static char buffer[bufferSize] = "efef";


			ImGui::InputTextMultiline("##code", buffer, bufferSize, ImVec2(450, 240));

			if (ImGui::Button("OK", ImVec2(220, 0)))
			{
				ImGui::CloseCurrentPopup();
			}
			ImGui::SameLine();
			if (ImGui::Button("Cancel", ImVec2(220, 0)))
			{
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();
		}
	}

	Configuration& config;
};