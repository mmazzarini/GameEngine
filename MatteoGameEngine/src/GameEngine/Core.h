#pragma once

#ifdef MATTEO_GENGINE_PLATFORM_WINDOWS
	#ifdef MATTEO_GENGINE_BUILD_DLL
		#define MATTEO_GENGINE_API __declspec(dllexport)
	#else
		#define MATTEO_GENGINE_API __declspec(dllimport)
	#endif
#else
	#error MatteoGameEngine Only Supports Windows
#endif

#define BIT(x) (1 << x)