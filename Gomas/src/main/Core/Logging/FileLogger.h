#pragma once

#include "spdlog/sinks/basic_file_sink.h"
#include <iostream>
#include <filesystem>
#include <string>
#include "Log.h"


namespace Gomas {

    class FileLogger {
    public:
        FileLogger(const std::string& filename, const std::string& directory = "temp/logs/");
        ~FileLogger();

        void Log(const std::string& message);

    private:
        std::string GetLogFilePath(const std::string& filename);
        std::shared_ptr<spdlog::logger> m_FileLogger;
        std::string m_LogDirectory;
    };

}

