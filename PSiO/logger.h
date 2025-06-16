#pragma once
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ostream>
#include <sstream>

template <typename T>
class Logger {
private:
    std::ofstream logFile;

    std::string getCurrentTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        tm timeinfo;
        localtime_s(&timeinfo, &in_time_t);
        ss << std::put_time(&timeinfo, "%Y-%m-%d %X");
        return ss.str();
    }

public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios_base::app);
    }

    void log(const T& message) {
        if (logFile.is_open()) {
            logFile << "[" << getCurrentTimestamp() << "] " << message << std::endl;
        }
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};