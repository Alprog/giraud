module;
#include "windows.h"
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
export module platform_window;

import std;

export class PlatformWindow
{
public:
	static std::unordered_map<HWND, PlatformWindow*> windows;
	
	explicit PlatformWindow()
    {
		//ImGui_ImplWin32_EnableDpiAwareness();
		wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"Giraud", nullptr };
		RegisterClassExW(&wc);
		hwnd = CreateWindowW(wc.lpszClassName, L"Giraud", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, nullptr, nullptr, wc.hInstance, nullptr);

		// Show the window
		ShowWindow(hwnd, SW_SHOWDEFAULT);
		UpdateWindow(hwnd);

		windows[hwnd] = this;
	}

    ~PlatformWindow()
    {
		windows.erase(hwnd);
		DestroyWindow(hwnd);
		UnregisterClassW(wc.lpszClassName, wc.hInstance);
    }

	bool ProcessEvents()
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
			{
				return false;
			}
		}
		return true;
	}

	bool ProcessMessage(UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (OnMessage)
		{
			OnMessage(msg, wParam, lParam);
		}

		switch (msg)
		{
			case WM_SIZE:
				/*if (g_pd3dDevice != nullptr && wParam != SIZE_MINIMIZED)
				{
					WaitForLastSubmittedFrame();
					CleanupRenderTarget();
					HRESULT result = g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT);
					assert(SUCCEEDED(result) && "Failed to resize swapchain.");
					CreateRenderTarget();
				}*/
				return true;
			case WM_SYSCOMMAND:
				if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
				{
					return true;
				}
				break;
			case WM_DESTROY:
				PostQuitMessage(0);
				return true;
		}

		return false;
	}

	std::function<void(UINT, WPARAM, LPARAM)> OnMessage;

	WNDCLASSEXW wc;
	HWND hwnd;
};

LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	auto window = PlatformWindow::windows[hwnd];
	if (window)
	{
		if (window->ProcessMessage(msg, wParam, lParam))
		{
			return 0;
		}
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

std::unordered_map<HWND, PlatformWindow*> PlatformWindow::windows;