module;
#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"
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

			codeString = "";
			ImGui::OpenPopup("Auth");
		}

		auto Flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize;

		const ImVec2 center = ImGui::GetMainViewport()->GetCenter();
		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
		if (ImGui::BeginPopupModal("Auth", nullptr, Flags))
		{
			ImGui::Text("You are redirecting to authentication page in your browser.");
			ImGui::Text("Paste here auth code from there:");

			static int textVersion = 0;
			std::string label = std::format("##{}", textVersion);
			if (ImGui::InputTextMultiline(label.c_str(), &codeString, ImVec2(430, 240)))
			{
				codeString.erase(std::remove(codeString.begin(), codeString.end(), '\n'), codeString.end());

				constexpr int line_width = 58;
				for (int i = line_width; i < codeString.size(); i += line_width + 1)
				{
					codeString.insert(codeString.begin() + i, '\n');
				}
				textVersion++;
			}

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

	std::string codeString;
	Configuration& config;
};