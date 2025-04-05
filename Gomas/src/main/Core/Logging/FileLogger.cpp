
#include "FileLogger.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <iostream>
#include <filesystem>


 // C++17 and later

namespace Gomas {

    FileLogger::FileLogger(const std::string& filename, const std::string& directory)
        : m_Initialized(false) {
        try {
            std::filesystem::create_directories(directory);
            auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(GetLogFilePath(filename));
            Log::GetCoreLogger()->sinks().push_back(fileSink);
            m_Initialized = true;
        }
        catch (const spdlog::spdlog_ex& ex) {
            std::cerr << "FileLogger init failed: " << ex.what() << std::endl;
        }
    }

    FileLogger::~FileLogger() {
        if (m_Initialized) {
            spdlog::drop("FileLogger");
        }
    }

    void FileLogger::LogToFile(const std::string& message) {
        if (m_Initialized) {
            Log::GetCoreLogger()->info(message);
        }
    }

    std::string FileLogger::GetLogFilePath(const std::string& filename) {
        return m_LogDirectory + filename;
    }

}

