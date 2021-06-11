#pragma once

#include "Core.h"
#include "spdlog\spdlog.h"

namespace Potato {

	class POTATO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log Macros
#define PO_CORE_TRACE(...)    ::Potato::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PO_CORE_INFO(...)     ::Potato::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PO_CORE_WARN(...)     ::Potato::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PO_CORE_ERROR(...)    ::Potato::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PO_CORE_CRITICAL(...) ::Potato::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Log Macros
#define PO_TRACE(...)    ::Potato::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PO_INFO(...)     ::Potato::Log::GetClientLogger()->info(__VA_ARGS__)
#define PO_WARN(...)     ::Potato::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PO_ERROR(...)    ::Potato::Log::GetClientLogger()->error(__VA_ARGS__)
#define PO_CRITICAL(...) ::Potato::Log::GetClientLogger()->critical(__VA_ARGS__)