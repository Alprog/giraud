module;
#include "imgui.h"
#include "backends/imgui_impl_win32.h"
#include "backends/imgui_impl_dx12.h"
export module gui_system;

import platform_window;
import gfx_renderer;

export class GuiSystem
{
public:
    explicit GuiSystem(PlatformWindow& platformWindow, GfxRenderer& gfxRenderer)
        : platformWindow{ platformWindow }
        , gfxRenderer{ gfxRenderer }
    {
		InitializeConfig();
		InitializeBackends();
    }

private:
    void InitializeConfig()
    {
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
		//io.ConfigViewportsNoAutoMerge = true;
		//io.ConfigViewportsNoTaskBarIcon = true;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}
    }

	void InitializeBackends()
	{
		// Setup Platform/Renderer backends
		ImGui_ImplWin32_Init(platformWindow.hwnd);

		ImGui_ImplDX12_Init(
			gfxRenderer.pd3dDevice, 
			NUM_FRAMES_IN_FLIGHT, 
			DXGI_FORMAT_R8G8B8A8_UNORM,
			gfxRenderer.pd3dSrvDescHeap, 
			gfxRenderer.pd3dSrvDescHeap->GetCPUDescriptorHandleForHeapStart(), 
			gfxRenderer.pd3dSrvDescHeap->GetGPUDescriptorHandleForHeapStart()
		);
	}

    PlatformWindow& platformWindow;
    GfxRenderer& gfxRenderer;
};