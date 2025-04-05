#pragma once
#include "../Base.h"
#include "spdlog/spdlog.h"
#include <memory>
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Gomas {
    class GOMAS_API Log {
    public:
        Log();
        ~Log();
        static void Init();
        static spdlog::logger* GetCoreLogger(); 
        static spdlog::logger* GetClientLogger(); 

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define GM_CORE_ERROR(...) ::Gomas::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GM_CORE_INFO(...) ::Gomas::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GM_CORE_TRACE(...) ::Gomas::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GM_CORE_WARN(...) ::Gomas::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GM_CORE_FATAL(...) ::Gomas::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define GM_CLIENT_INFO(...) ::Gomas::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GM_CLIENT_TRACE(...) ::Gomas::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GM_CLIENT_ERROR(...) ::Gomas::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GM_CLIENT_WARN(...) ::Gomas::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GM_CLIENT_FATAL(...) ::Gomas::Log::GetCoreLogger()->fatal(__VA_ARGS__)