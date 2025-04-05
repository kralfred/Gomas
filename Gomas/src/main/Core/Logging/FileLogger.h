#pragma once

#include "spdlog/sinks/basic_file_sink.h"
#include <iostream>
#include <filesystem>
#include <string>
#include "Log.h"
#include "../Base.h"


namespace Gomas {

    class GOMAS_API FileLogger {
    public:
        FileLogger(const std::string& filename, const std::string& directory = "temp/logs/");
        ~FileLogger();

        void LogToFile(const std::string& message);

    private:
        std::string GetLogFilePath(const std::string& filename);
        bool m_Initialized;
        std::string m_LogDirectory;
    };

}

