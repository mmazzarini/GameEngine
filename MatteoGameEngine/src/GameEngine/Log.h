#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace MGEngine
{
	class MATTEO_GENGINE_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger();

	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
		
	};

}

//Core log macros
#define MGENGINE_CORE_TRACE(...)    ::MGEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MGENGINE_CORE_INFO(...)     ::MGEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MGENGINE_CORE_WARN(...)     ::MGEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MGENGINE_CORE_ERROR(...)    ::MGEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MGENGINE_CORE_FATAL(...)    ::MGEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define MGENGINE_TRACE(...)    ::MGEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MGENGINE_INFO(...)     ::MGEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define MGENGINE_WARN(...)     ::MGEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MGENGINE_ERROR(...)    ::MGEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define MGENGINE_FATAL(...)    ::MGEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)


