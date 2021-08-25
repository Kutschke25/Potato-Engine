#pragma once

#ifdef PO_PLATFORM_WINDOWS
	#ifdef PO_BUILD_DLL
		#define POTATO_API __declspec(dllexport)
	#else
		#define POTATO_API __declspec(dllimport)
	#endif
#else
	#error Potato only supports Windows!
#endif

#ifdef PO_ENABLE_ASSERTS
	#define PO_ASSERT(x, ...)  {if (!(x)) {PO_ERROR("Assertion failed: {0}", __VA_ARGS__}; __debugbreak(); } }
	#define PO_CORE_ASSERT(x, ...) {if (!(x)) {PO_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PO_ASSERT(x, ...)
	#define PO_CORE_ASSERT(x, ...)
#endif

#include "Log.h"

#define BIT(x) (1 << x)

#define PO_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)