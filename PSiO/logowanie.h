#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "json.hpp"
#include <iomanip>
#include <Windows.h>

#include <vcclr.h>
#include <msclr/auto_gcroot.h>


namespace PSiO {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Runtime::InteropServices;

    std::string toStdString(System::String^ str);

    public ref class MyForm1 : public System::Windows::Forms::Form
    {
    public:
        MyForm1(void)
        {
            InitializeComponent();
            this->textBoxUsername->Text = "Nazwa użytkownika";
            this->textBoxUsername->ForeColor = System::Drawing::Color::Gray;
            this->textBoxPassword->Text = "";
            this->textBoxPassword->PasswordChar = '*';
            this->couriersFilename = "kurierzy.json";
        }

    protected:
        ~MyForm1()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ labelUsername;
    private: System::Windows::Forms::TextBox^ textBoxUsername;
    private: System::Windows::Forms::Label^ labelPassword;
    private: System::Windows::Forms::TextBox^ textBoxPassword;
    private: System::Windows::Forms::Button^ buttonLoginCourier;
    private: System::Windows::Forms::Button^ buttonRegisterCourier;
    private: System::Windows::Forms::Label^ labelStatus;
    private: System::String^ couriersFilename;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            // Uzupełnij według kodu generowanego przez Visual Studio Designer
        }
#pragma endregion

    private: nlohmann::json readCouriersFile() {
        std::string fileNameStd = toStdString(this->couriersFilename);
        std::ifstream ifs(fileNameStd);
        nlohmann::json couriers_json_array = nlohmann::json::array();
        if (ifs.is_open()) {
            try {
                ifs >> couriers_json_array;
                if (!couriers_json_array.is_array()) {
                    couriers_json_array = nlohmann::json::array();
                }
            }
            catch (...) {}
            ifs.close();
        }
        return couriers_json_array;
    }

    private: bool writeCouriersFile(const nlohmann::json& couriers_json_array) {
        std::string fileNameStd = toStdString(this->couriersFilename);
        std::ofstream ofs(fileNameStd);
        if (ofs.is_open()) {
            ofs << std::setw(4) << couriers_json_array << std::endl;
            ofs.close();
            return true;
        }
        return false;
    }

    private: System::Void buttonRegisterCourier_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string username = toStdString(this->textBoxUsername->Text);
        std::string password = toStdString(this->textBoxPassword->Text);

        if (username.empty() || password.empty() || username == "Nazwa użytkownika") {
            this->labelStatus->Text = "Nazwa użytkownika i hasło nie mogą być puste.";
            this->labelStatus->ForeColor = Color::Red;
            return;
        }

        nlohmann::json couriers = readCouriersFile();

        for (const auto& courier : couriers) {
            if (courier.is_object() && courier.contains("username") && courier["username"] == username) {
                this->labelStatus->Text = "Nazwa użytkownika już istnieje.";
                this->labelStatus->ForeColor = Color::Red;
                return;
            }
        }

        couriers.push_back({ {"username", username}, {"password", password} });

        if (writeCouriersFile(couriers)) {
            this->labelStatus->Text = "Rejestracja zakończona pomyślnie.";
            this->labelStatus->ForeColor = Color::Green;
            this->textBoxUsername->Text = "Nazwa użytkownika";
            this->textBoxUsername->ForeColor = Color::Gray;
            this->textBoxPassword->Text = "";
        }
        else {
            this->labelStatus->Text = "Błąd zapisu do pliku kurierów.";
            this->labelStatus->ForeColor = Color::Red;
        }
    }

    private: System::Void buttonLoginCourier_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string username = toStdString(this->textBoxUsername->Text);
        std::string password = toStdString(this->textBoxPassword->Text);

        if (username.empty() || password.empty() || username == "Nazwa użytkownika") {
            this->labelStatus->Text = "Wprowadź nazwę użytkownika i hasło.";
            this->labelStatus->ForeColor = Color::Red;
            return;
        }

        nlohmann::json couriers = readCouriersFile();
        bool loggedIn = false;

        for (const auto& courier : couriers) {
            if (courier.is_object() && courier.contains("username") && courier.contains("password") &&
                courier["username"] == username && courier["password"] == password) {
                loggedIn = true;
                break;
            }
        }

        if (loggedIn) {
            this->labelStatus->Text = "Logowanie pomyślne!";
            this->labelStatus->ForeColor = Color::Green;
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }
        else {
            this->labelStatus->Text = "Nieprawidłowa nazwa użytkownika lub hasło.";
            this->labelStatus->ForeColor = Color::Red;
            this->DialogResult = System::Windows::Forms::DialogResult::None;
        }
    }
    };
}