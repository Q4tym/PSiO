#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>

namespace PSiO {
	// Centralna, jedyna definicja funkcji pomocniczej
	// Konwertuje System::String^ na std::string
	inline std::string toStdString(System::String^ str) {
		if (System::String::IsNullOrEmpty(str)) {
			return std::string();
		}
		msclr::interop::marshal_context context;
		return context.marshal_as<std::string>(str);
	}
}
