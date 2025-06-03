#pragma once
#include "logowanie.h"        // Zawiera MyForm1 (formularz logowania/rejestracji)
#include "Formularz_paczki.h" // Zawiera Formularz_paczki
// Poni¿sze nag³ówki marshal s¹ czêsto potrzebne w nag³ówkach C++/CLI,
// ale nie s¹ bezpoœrednio u¿ywane w tej klasie.
// #include <msclr/marshal.h>
// #include <msclr/marshal_cppstd.h>

namespace PSiO {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            // TODO: W tym miejscu dodaj kod konstruktora, jeœli jest potrzebny
            //
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ buttonLogin;    // Zmieniona nazwa na buttonLogin dla jasnoœci
    private: System::Windows::Forms::Button^ buttonExit;     // Zmieniona nazwa na buttonExit
    private: System::Windows::Forms::Button^ buttonNewPackage; // Zmieniona nazwa na buttonNewPackage

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->buttonLogin = (gcnew System::Windows::Forms::Button());
            this->buttonExit = (gcnew System::Windows::Forms::Button());
            this->buttonNewPackage = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // buttonLogin
            // 
            this->buttonLogin->Location = System::Drawing::Point(150, 180); // Przyk³adowa pozycja
            this->buttonLogin->Margin = System::Windows::Forms::Padding(2);
            this->buttonLogin->Name = L"buttonLogin";
            this->buttonLogin->Size = System::Drawing::Size(120, 30);
            this->buttonLogin->TabIndex = 0;
            this->buttonLogin->Text = L"Zaloguj Kuriera"; // Zmieniony tekst dla jasnoœci
            this->buttonLogin->UseVisualStyleBackColor = true;
            this->buttonLogin->Click += gcnew System::EventHandler(this, &MyForm::buttonLogin_Click);
            // 
            // buttonExit
            // 
            this->buttonExit->Location = System::Drawing::Point(12, 226); // Przyk³adowa pozycja
            this->buttonExit->Margin = System::Windows::Forms::Padding(2);
            this->buttonExit->Name = L"buttonExit";
            this->buttonExit->Size = System::Drawing::Size(100, 26);
            this->buttonExit->TabIndex = 1;
            this->buttonExit->Text = L"Wyjœcie";
            this->buttonExit->UseVisualStyleBackColor = true;
            this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Click);
            // 
            // buttonNewPackage
            // 
            this->buttonNewPackage->Location = System::Drawing::Point(150, 80); // Przyk³adowa pozycja
            this->buttonNewPackage->Margin = System::Windows::Forms::Padding(2);
            this->buttonNewPackage->Name = L"buttonNewPackage";
            this->buttonNewPackage->Size = System::Drawing::Size(120, 45); // Trochê wiêkszy
            this->buttonNewPackage->TabIndex = 2;
            this->buttonNewPackage->Text = L"Nadaj Paczkê";
            this->buttonNewPackage->UseVisualStyleBackColor = true;
            this->buttonNewPackage->Click += gcnew System::EventHandler(this, &MyForm::buttonNewPackage_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(423, 270); // Rozmiar okna g³ównego
            this->Controls->Add(this->buttonNewPackage);
            this->Controls->Add(this->buttonExit);
            this->Controls->Add(this->buttonLogin);
            this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
            this->Name = L"MyForm";
            this->Text = L"System Zarz¹dzania Przesy³kami"; // Zmieniony tytu³ okna
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen; // Wyœrodkowanie na ekranie
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        // Kod wykonywany podczas ³adowania formularza, jeœli potrzebny
    }

    private: System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
        // Otwiera formularz logowania/rejestracji (MyForm1 z logowanie.h)
        try {
            MyForm1^ loginRegForm = gcnew MyForm1();
            if (loginRegForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) {
                // Logowanie zakoñczy³o siê sukcesem (DialogResult ustawiony w MyForm1).
                // MyForm1 sam otwiera Formularz_paczki.
                // Tutaj mo¿na ewentualnie zaktualizowaæ UI MyForm, jeœli jest taka potrzeba,
                // np. zmieniæ status na "Zalogowany" lub odblokowaæ inne opcje.
                MessageBox::Show("Kurier zosta³ pomyœlnie zalogowany.", "Logowanie Kuriera", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else {
                // Logowanie zosta³o anulowane lub nie powiod³o siê.
                // MyForm1 powinien wyœwietliæ odpowiednie komunikaty o b³êdach.
                // Mo¿na dodaæ dodatkowy komunikat tutaj, jeœli jest potrzebny, np. o anulowaniu.
                // MessageBox::Show("Logowanie anulowane lub nieudane.", "Logowanie Kuriera", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Wyst¹pi³ b³¹d podczas otwierania formularza logowania: " + ex->Message, "B³¹d Krytyczny", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
        // Zamyka aplikacjê po potwierdzeniu
        if (MessageBox::Show("Czy na pewno chcesz zamkn¹æ aplikacjê?", "Potwierdzenie Wyjœcia", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
        {
            Application::Exit();
        }
    }

    private: System::Void buttonNewPackage_Click(System::Object^ sender, System::EventArgs^ e) {
        // Otwiera formularz nadawania paczki
        // Ta opcja mo¿e byæ dostêpna niezale¿nie od statusu logowania kuriera,
        // lub mo¿na j¹ uzale¿niæ od logowania (np. ukryæ/zablokowaæ przycisk do czasu zalogowania).
        // W obecnej formie otwiera Formularz_paczki bezpoœrednio.
        try {
            Formularz_paczki^ formularz = gcnew Formularz_paczki();
            formularz->ShowDialog(this); // Poka¿ jako modalny wzglêdem MyForm
        }
        catch (Exception^ ex) {
            MessageBox::Show("Wyst¹pi³ b³¹d podczas otwierania formularza paczki: " + ex->Message, "B³¹d Krytyczny", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    }; // Koniec klasy MyForm
} // Koniec namespace PSiO