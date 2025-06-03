
#include "logowanie.h"

namespace PSiO {
    std::string toStdString(System::String^ str) {
        if (str == nullptr) {
            return "";
        }
        const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(str)).ToPointer();
        std::string os(chars);
        Marshal::FreeHGlobal(IntPtr((void*)chars));
        return os;
    }
}