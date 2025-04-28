module;
#include "windows.h"
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
export module platform_window;

export class PlatformWindow
{
public:
    explicit PlatformWindow()
    {
		//ImGui_ImplWin32_EnableDpiAwareness();
		wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"Giraud", nullptr };
		RegisterClassExW(&wc);
		hwnd = CreateWindowW(wc.lpszClassName, L"Giraud", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, nullptr, nullptr, wc.hInstance, nullptr);

		// Show the window
		ShowWindow(hwnd, SW_SHOWDEFAULT);
		UpdateWindow(hwnd);
	}

    ~PlatformWindow()
    {
		DestroyWindow(hwnd);
		UnregisterClassW(wc.lpszClassName, wc.hInstance);
    }

	WNDCLASSEXW wc;
	HWND hwnd;
};