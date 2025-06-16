#pragma once

#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ostream>
#include <sstream> // <-- POPRAWKA: Dodano brakuj�cy nag��wek

//--[REQUIREMENT: Generic Class (template)]--
// Klasa generyczna Logger potrafi zapisywa� do pliku logi
// dowolnego typu T, dla kt�rego zdefiniowano operator<<.
template <typename T>
class Logger {
private:
    std::ofstream logFile;

    std::string getCurrentTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss; // Teraz kompilator wie, czym jest stringstream
        tm timeinfo;

        // localtime_s jest bezpieczniejsz� wersj� localtime
        localtime_s(&timeinfo, &in_time_t);

        ss << std::put_time(&timeinfo, "%Y-%m-%d %X");
        return ss.str();
    }

public:
    //--[REQUIREMENT: Constructor]--
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios_base::app); // Otw�rz plik w trybie dopisywania
    }

    void log(const T& message) {
        if (logFile.is_open()) {
            logFile << "[" << getCurrentTimestamp() << "] " << message << std::endl;
        }
    }

    //--[REQUIREMENT: Destructor]--
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};