#pragma once
#include "logowanie.h" // To jest MyForm1, czyli formularz logowania/rejestracji
#include "Formularz_paczki.h"
#include <msclr/marshal.h>         // Dodane
#include <msclr/marshal_cppstd.h>

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
            //TODO: W tym miejscu dodaj kod konstruktora
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
    private: System::Windows::Forms::Button^ button1; // Przycisk "zaloguj"
    private: System::Windows::Forms::Button^ button2; // Przycisk "wyjscie"
    private: System::Windows::Forms::Button^ button3; // Przycisk "Nadaj paczke"

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            // ... (Twoja istniej¹ca metoda InitializeComponent bez zmian) ...
            // Upewnij siê, ¿e button1, button2, button3 s¹ poprawnie zainicjalizowane
            // PONI¯EJ JEST TYLKO PRZYK£AD STRUKTURY
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(355, 236);
            this->button1->Margin = System::Windows::Forms::Padding(2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(59, 26);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Zaloguj"; // Zmieniony tekst dla jasnoœci
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            //
            // button2
            //
            this->button2->Location = System::Drawing::Point(8, 236);
            this->button2->Margin = System::Windows::Forms::Padding(2);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(59, 26);
            this->button2->TabIndex = 1;
            this->button2->Text = L"Wyjœcie";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            //
            // button3
            //
            this->button3->Location = System::Drawing::Point(159, 103);
            this->button3->Margin = System::Windows::Forms::Padding(2);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(100, 35); // Trochê szerszy dla czytelnoœci
            this->button3->TabIndex = 2;
            this->button3->Text = L"Nadaj Paczkê";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            //
            // MyForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(423, 270);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
            this->Name = L"MyForm";
            this->Text = L"System Przesy³ek"; // Zmieniony tytu³
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
        }
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Przycisk "Zaloguj"
        try {
            MyForm1^ loginRegForm = gcnew MyForm1(); // MyForm1 to teraz formularz logowania/rejestracji
            // loginRegForm->ShowDialog(); // Poprzednie wywo³anie

            if (loginRegForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) {
                // Logowanie zakoñczy³o siê sukcesem (DialogResult ustawiony w MyForm1)
                MessageBox::Show("Zalogowano kuriera pomyœlnie!", "Logowanie Kuriera", MessageBoxButtons::OK, MessageBoxIcon::Information);
                // Tutaj mo¿esz dodaæ logikê po udanym logowaniu,
                // np. odblokowaæ inne funkcje, zmieniæ widok itp.
            }
            else {
                // Logowanie zosta³o anulowane lub nie powiod³o siê.
                // Komunikat o b³êdzie powinien byæ ju¿ wyœwietlony przez MyForm1.
                // Mo¿esz dodaæ dodatkowy komunikat tutaj, jeœli jest potrzebny.
                // MessageBox::Show("Logowanie anulowane lub nieudane.", "Logowanie Kuriera", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Wyst¹pi³ b³¹d podczas otwierania formularza logowania: " + ex->Message, "B³¹d Krytyczny", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // Przycisk "Wyjœcie"
        if (MessageBox::Show("Napewno chcesz zamkn¹æ aplikacjê?", "Potwierdzenie Wyjœcia", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
        {
            Application::Exit();
        }
    }

    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Przycisk "Nadaj Paczkê"
        try {
            Formularz_paczki^ formularz = gcnew Formularz_paczki();
            formularz->ShowDialog();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Wyst¹pi³ b³¹d podczas otwierania formularza paczki: " + ex->Message, "B³¹d Krytyczny", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    };
}