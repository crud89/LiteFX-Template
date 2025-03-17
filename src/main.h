#pragma once

// Include engine sources.
// NOTE: The LITEFX_DEFINE_GLOBAL_EXPORTS macro is required for exporting symbols that are used to load the D3D12 agility sdk. If you are not using 
//       the DirectX 12 backend or you want to provide a custom agility sdk, you can remove it.
#define LITEFX_DEFINE_GLOBAL_EXPORTS
#define LITEFX_AUTO_IMPORT_BACKEND_HEADERS
#include <litefx/litefx.h>
#include <litefx/graphics.hpp>

using namespace LiteFX;
using namespace LiteFX::Rendering;
using namespace LiteFX::Rendering::Backends;
using namespace LiteFX::Graphics;

// Include glfw.
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#if (defined _WIN32 || defined WINCE)
#  define GLFW_EXPOSE_NATIVE_WIN32
#else 
#  pragma message ("No supported surface platform detected.")
#endif

// Define a smart pointer to store glfw window handles.
struct GlfwWindowDeleter {
	void operator()(GLFWwindow* ptr) noexcept {
		::glfwDestroyWindow(ptr);
	}
};

typedef UniquePtr<GLFWwindow, GlfwWindowDeleter> GlfwWindowPtr;

// Additional STL includes.
#include <memory>
#include <filesystem>
#include <print>
#include <iostream>