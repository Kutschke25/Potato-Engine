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