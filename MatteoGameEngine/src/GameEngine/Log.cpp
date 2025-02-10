#include "GenginePCH.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace MGEngine
{
	std::shared_ptr<spdlog::logger> Log::CoreLogger;
	std::shared_ptr<spdlog::logger> Log::ClientLogger;

	void Log::Init()
	{
		//Color - timestamp - logger name - actual log 
		spdlog::set_pattern("%^[%T] %n: %v%$");
		CoreLogger = spdlog::stdout_color_mt("MGENGINE");
		ClientLogger = spdlog::stdout_color_mt("APP");
		CoreLogger->set_level(spdlog::level::trace);
		ClientLogger->set_level(spdlog::level::trace);

	}

	inline std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return CoreLogger;
	}

	inline std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
	{
		return ClientLogger;
	}
}