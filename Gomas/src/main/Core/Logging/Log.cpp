#include "Log.h"
#include <filesystem>
#include <iostream>


namespace Gomas {
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
    std::shared_ptr<spdlog::sinks::basic_file_sink_mt> Log::s_FileSink = nullptr;
    std::string Log::s_LogFilePath = "temp/logs";
    bool Log::s_FileLoggingEnabled = false;

  

    void Log::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("Gomas");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }

    Log::Log() {}
    Log::~Log() {}

    void Log::StartFileLogging(const std::string& filename, const std::string& directory) {
        try {
            std::filesystem::create_directories(directory);
            s_LogFilePath = directory + filename;
            s_FileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(s_LogFilePath);
            s_CoreLogger->sinks().push_back(s_FileSink);
            s_FileLoggingEnabled = true;
        }
        catch (const spdlog::spdlog_ex& ex) {
            std::cerr << "Log file creation failed: " << ex.what() << std::endl;
            s_FileLoggingEnabled = false;
        }
    }
    void Log::StopFileLogging() {
        if (s_FileLoggingEnabled) {
            s_CoreLogger->sinks().erase(std::remove(s_CoreLogger->sinks().begin(), s_CoreLogger->sinks().end(), s_FileSink), s_CoreLogger->sinks().end());
            s_FileSink.reset();
            s_FileLoggingEnabled = false;
        }
    }

    void Log::LogToFile(const std::string& message) {
        if (s_FileLoggingEnabled) {
            s_CoreLogger->info(message);
        }
    }

    spdlog::logger* Log::GetCoreLogger() {
        return s_CoreLogger.get();
    }

    spdlog::logger* Log::GetClientLogger() {
        return s_ClientLogger.get();
    }
}