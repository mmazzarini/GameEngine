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

#ifdef MATTEO_GENGINE_DEBUG
	#define MATTEO_GENGINE_ENABLE_ASSERTS
#endif

#ifdef MATTEO_GENGINE_ENABLE_ASSERTS
	#define MGENGINE_ASSERT(x, ...) {if(!(x)) {MGENGINE_ERROR("Assertion failed: {0}!", __VA_ARGS__); __debugbreak(); } }
	#define MGENGINE_CORE_ASSERT(x, ...) {if(!(x)) {MGENGINE_CORE_ERROR("Assertion failed: {0}!", __VA_ARGS__); __debugbreak(); } }
#else
	#define MGENGINE_ASSERT(x, ...)
	#define MGENGINE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MGENGINE_BIND_FN(fn) std::bind(&fn, this, std::placeholders::_1)