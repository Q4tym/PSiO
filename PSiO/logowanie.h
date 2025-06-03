#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "json.hpp" // Upewnij się, że ten plik nagłówkowy jest dostępny
#include <iomanip>   // Dla std::setw
#include <Windows.h> // Dla definicji systemowych, np. Color, Point itp. używanych przez Windows Forms

// Nagłówki C++/CLI
#include <vcclr.h> // Dla GCHandle, itp.
#include <msclr/auto_gcroot.h>
#include <msclr/marshal_cppstd.h> // Dla marshal_as

// Nagłówek formularza, który ma być otwarty po zalogowaniu
#include "Formularz_paczki.h" // Upewnij się, że Formularz_paczki.h jest poprawnie załączony

namespace PSiO {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Runtime::InteropServices; // Dla Marshal (jeśli byłby używany starszy sposób)

    // Definicja toStdString (inline, aby uniknąć problemów z wielokrotną definicją)
    // Ta wersja używa nowoczesnego msclr::interop::marshal_as
    inline std::string toStdString(System::String^ str) {
        if (String::IsNullOrEmpty(str)) {
            return std::string();
        }
        msclr::interop::marshal_context context;
        return context.marshal_as<std::string>(str);
    }

    public ref class MyForm1 : public System::Windows::Forms::Form // Nazwa MyForm1 pochodzi z Twojego pliku MyForm.h
    {
    public:
        MyForm1(void)
        {
            InitializeComponent();
            // Inicjalizacja placeholderów i ustawień początkowych
            this->textBoxUsername->Text = "Nazwa użytkownika";
            this->textBoxUsername->ForeColor = System::Drawing::Color::Gray;
            this->textBoxPassword->Text = ""; // Pole hasła powinno być początkowo puste
            this->textBoxPassword->PasswordChar = '*'; // Maskowanie hasła
            this->couriersFilename = "kurierzy.json"; // Inicjalizacja nazwy pliku
            this->labelStatus->Text = ""; // Początkowo brak statusu
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
    private: System::String^ couriersFilename; // Nazwa pliku z danymi kurierów

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->labelUsername = (gcnew System::Windows::Forms::Label());
            this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
            this->labelPassword = (gcnew System::Windows::Forms::Label());
            this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
            this->buttonLoginCourier = (gcnew System::Windows::Forms::Button());
            this->buttonRegisterCourier = (gcnew System::Windows::Forms::Button());
            this->labelStatus = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // labelUsername
            // 
            this->labelUsername->AutoSize = true;
            this->labelUsername->Location = System::Drawing::Point(30, 30);
            this->labelUsername->Name = L"labelUsername";
            this->labelUsername->Size = System::Drawing::Size(102, 13);
            this->labelUsername->TabIndex = 0;
            this->labelUsername->Text = L"Nazwa użytkownika:";
            // 
            // textBoxUsername
            // 
            this->textBoxUsername->Location = System::Drawing::Point(140, 27);
            this->textBoxUsername->Name = L"textBoxUsername";
            this->textBoxUsername->Size = System::Drawing::Size(150, 20);
            this->textBoxUsername->TabIndex = 1;
            this->textBoxUsername->Enter += gcnew System::EventHandler(this, &MyForm1::textBoxUsername_Enter);
            this->textBoxUsername->Leave += gcnew System::EventHandler(this, &MyForm1::textBoxUsername_Leave);
            // 
            // labelPassword
            // 
            this->labelPassword->AutoSize = true;
            this->labelPassword->Location = System::Drawing::Point(30, 70);
            this->labelPassword->Name = L"labelPassword";
            this->labelPassword->Size = System::Drawing::Size(39, 13);
            this->labelPassword->TabIndex = 2;
            this->labelPassword->Text = L"Hasło:";
            // 
            // textBoxPassword
            // 
            this->textBoxPassword->Location = System::Drawing::Point(140, 67);
            this->textBoxPassword->Name = L"textBoxPassword";
            this->textBoxPassword->Size = System::Drawing::Size(150, 20);
            this->textBoxPassword->TabIndex = 2; // TabIndex powinien być unikalny lub odpowiednio zarządzany
            this->textBoxPassword->PasswordChar = '*'; // Upewnienie się, że hasło jest maskowane
            // 
            // buttonLoginCourier
            // 
            this->buttonLoginCourier->Location = System::Drawing::Point(33, 110);
            this->buttonLoginCourier->Name = L"buttonLoginCourier";
            this->buttonLoginCourier->Size = System::Drawing::Size(120, 23);
            this->buttonLoginCourier->TabIndex = 3;
            this->buttonLoginCourier->Text = L"Zaloguj";
            this->buttonLoginCourier->UseVisualStyleBackColor = true;
            this->buttonLoginCourier->Click += gcnew System::EventHandler(this, &MyForm1::buttonLoginCourier_Click);
            // 
            // buttonRegisterCourier
            // 
            this->buttonRegisterCourier->Location = System::Drawing::Point(170, 110);
            this->buttonRegisterCourier->Name = L"buttonRegisterCourier";
            this->buttonRegisterCourier->Size = System::Drawing::Size(120, 23);
            this->buttonRegisterCourier->TabIndex = 4;
            this->buttonRegisterCourier->Text = L"Rejestruj";
            this->buttonRegisterCourier->UseVisualStyleBackColor = true;
            this->buttonRegisterCourier->Click += gcnew System::EventHandler(this, &MyForm1::buttonRegisterCourier_Click);
            // 
            // labelStatus
            // 
            this->labelStatus->AutoSize = true;
            this->labelStatus->Location = System::Drawing::Point(30, 150);
            this->labelStatus->Name = L"labelStatus";
            this->labelStatus->Size = System::Drawing::Size(0, 13); // Początkowo pusty
            this->labelStatus->MinimumSize = System::Drawing::Size(260, 0); // Minimalna szerokość, aby tekst się mieścił
            this->labelStatus->TabIndex = 5;
            // 
            // MyForm1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(320, 185);
            this->Controls->Add(this->labelStatus);
            this->Controls->Add(this->buttonRegisterCourier);
            this->Controls->Add(this->buttonLoginCourier);
            this->Controls->Add(this->textBoxPassword);
            this->Controls->Add(this->labelPassword);
            this->Controls->Add(this->textBoxUsername);
            this->Controls->Add(this->labelUsername);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; // Zapobiega zmianie rozmiaru
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"MyForm1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent; // Wyśrodkowanie względem rodzica
            this->Text = L"Logowanie / Rejestracja Kuriera";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // Obsługa placeholderów dla pola Nazwa użytkownika
    private: System::Void textBoxUsername_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBoxUsername->Text == "Nazwa użytkownika") {
            this->textBoxUsername->Text = "";
            this->textBoxUsername->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBoxUsername_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBoxUsername->Text)) {
            this->textBoxUsername->Text = "Nazwa użytkownika";
            this->textBoxUsername->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody do obsługi pliku JSON z kurierami
    private: nlohmann::json readCouriersFile() {
        std::string fileNameStd = toStdString(this->couriersFilename);
        std::ifstream ifs(fileNameStd);
        nlohmann::json couriers_json_array = nlohmann::json::array();

        if (ifs.is_open()) {
            try {
                ifs >> couriers_json_array;
                if (!couriers_json_array.is_array()) { // Upewnij się, że to tablica
                    couriers_json_array = nlohmann::json::array();
                }
            }
            catch (nlohmann::json::parse_error& e) {
                // Plik może być pusty lub uszkodzony, traktuj jako pustą tablicę
                // Można dodać logowanie błędu e.what()
                couriers_json_array = nlohmann::json::array();
            }
            ifs.close();
        }
        return couriers_json_array;
    }

    private: bool writeCouriersFile(const nlohmann::json& couriers_json_array) {
        std::string fileNameStd = toStdString(this->couriersFilename);
        std::ofstream ofs(fileNameStd);
        if (ofs.is_open()) {
            ofs << std::setw(4) << couriers_json_array << std::endl; // Formatowanie JSON dla czytelności
            ofs.close();
            return true;
        }
        return false;
    }

           // Obsługa przycisku "Rejestruj"
    private: System::Void buttonRegisterCourier_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string username = toStdString(this->textBoxUsername->Text);
        std::string password = toStdString(this->textBoxPassword->Text);

        if (username.empty() || password.empty() || username == "Nazwa użytkownika") {
            this->labelStatus->Text = "Nazwa użytkownika i hasło nie mogą być puste.";
            this->labelStatus->ForeColor = Color::Red;
            return;
        }

        nlohmann::json couriers = readCouriersFile();

        // Sprawdzenie, czy użytkownik już istnieje
        for (const auto& courier : couriers) {
            if (courier.is_object() && courier.contains("username") && courier["username"] == username) {
                this->labelStatus->Text = "Nazwa użytkownika już istnieje.";
                this->labelStatus->ForeColor = Color::Red;
                return;
            }
        }

        // Dodanie nowego kuriera
        couriers.push_back({ {"username", username}, {"password", password} }); // Hasło powinno być hashowane w prawdziwej aplikacji

        if (writeCouriersFile(couriers)) {
            this->labelStatus->Text = "Rejestracja zakończona pomyślnie.";
            this->labelStatus->ForeColor = Color::Green;
            // Resetowanie pól po pomyślnej rejestracji
            this->textBoxUsername->Text = "Nazwa użytkownika";
            this->textBoxUsername->ForeColor = Color::Gray;
            this->textBoxPassword->Text = "";
        }
        else {
            this->labelStatus->Text = "Błąd zapisu do pliku kurierów.";
            this->labelStatus->ForeColor = Color::Red;
        }
    }

           // Obsługa przycisku "Zaloguj"
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
                courier["username"] == username && courier["password"] == password) { // Porównanie hasła w formie jawnej - NIEBEZPIECZNE w produkcji
                loggedIn = true;
                break;
            }
        }

        if (loggedIn) {
            this->labelStatus->Text = "Logowanie pomyślne!";
            this->labelStatus->ForeColor = Color::Green;

            // *** DODANA LINIA - Ustawienie DialogResult ***
            this->DialogResult = System::Windows::Forms::DialogResult::OK;

            this->Hide(); // Ukryj formularz logowania

            // Utwórz i pokaż formularz paczki
            Formularz_paczki^ paczkaForm = gcnew Formularz_paczki();
            paczkaForm->ShowDialog(); // Pokaż jako modalny - czeka, aż zostanie zamknięty

            this->Close(); // Zamknij formularz logowania po zamknięciu formularza paczki
        }
        else {
            this->labelStatus->Text = "Nieprawidłowa nazwa użytkownika lub hasło.";
            this->labelStatus->ForeColor = Color::Red;
        }
    }
    }; // Koniec klasy MyForm1
} // Koniec namespace PSiO