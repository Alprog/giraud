module;
#include "imgui.h"
#include "backends/imgui_impl_win32.h"
#include "backends/imgui_impl_dx12.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>

#ifdef _DEBUG
#define DX12_ENABLE_DEBUG_LAYER
#endif

#ifdef DX12_ENABLE_DEBUG_LAYER
#include <dxgidebug.h>
#pragma comment(lib, "dxguid.lib")
#endif
export module gfx_renderer;

import platform_window;

export class GfxRenderer
{
public:
    explicit GfxRenderer(const PlatformWindow& window)
    {

    }

    ~GfxRenderer()
    {

    }
};