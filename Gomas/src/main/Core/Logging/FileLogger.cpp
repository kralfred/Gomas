

#include "FileLogger.h"
#include <spdlog/spdlog.h>


 // C++17 and later

namespace Gomas {

    FileLogger::FileLogger(const std::string& filename, const std::string& directory)
        : m_LogDirectory(directory) {
        try {
            std::filesystem::create_directories(m_LogDirectory); // Create directory if it doesn't exist
            m_FileLogger = spdlog::basic_logger_mt("FileLogger", GetLogFilePath(filename));
            m_FileLogger->set_level(spdlog::level::trace);
        }
        catch (const spdlog::spdlog_ex& ex) {
            std::cerr << "FileLogger init failed: " << ex.what() << std::endl;
            m_FileLogger = nullptr;
        }
    }

    FileLogger::~FileLogger() {
        if (m_FileLogger) {
            m_FileLogger->flush();
            spdlog::drop("FileLogger");
        }
    }

    void FileLogger::Log(const std::string& message) {
        if (m_FileLogger) {
            m_FileLogger->info(message);
        }
    }

    std::string FileLogger::GetLogFilePath(const std::string& filename) {
        return m_LogDirectory + filename;
    }

}

