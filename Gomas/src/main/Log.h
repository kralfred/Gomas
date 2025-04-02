#pragma once
#include "Core.h"
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