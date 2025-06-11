#pragma once

#include <string>
#include "msclr/marshal_cppstd.h"

namespace PSiO {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Drawing::Imaging;

    public ref class EtykietaForm : public Form {
    public:
        EtykietaForm(String^ numerPaczki) {
            this->InitializeComponent();
            this->labelNumerPaczki->Text = "Numer paczki: " + numerPaczki;
            this->pictureBoxKodKreskowy->Image = generujKodKreskowy(numerPaczki);
        }

    protected:
        ~EtykietaForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ labelTytul;
        System::Windows::Forms::Label^ labelNumerPaczki;
        System::Windows::Forms::PictureBox^ pictureBoxKodKreskowy;
        System::Windows::Forms::Button^ buttonZamknij;
        System::ComponentModel::Container^ components;

        void InitializeComponent() {
            this->components = (gcnew System::ComponentModel::Container());
            this->labelTytul = (gcnew System::Windows::Forms::Label());
            this->labelNumerPaczki = (gcnew System::Windows::Forms::Label());
            this->pictureBoxKodKreskowy = (gcnew System::Windows::Forms::PictureBox());
            this->buttonZamknij = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxKodKreskowy))->BeginInit();
            this->SuspendLayout();

            // labelTytul
            this->labelTytul->AutoSize = true;
            this->labelTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold));
            this->labelTytul->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
            this->labelTytul->Location = System::Drawing::Point(12, 9);
            this->labelTytul->Name = L"labelTytul";
            this->labelTytul->Size = System::Drawing::Size(178, 30);
            this->labelTytul->Text = L"Etykieta Paczki";

            // labelNumerPaczki
            this->labelNumerPaczki->AutoSize = true;
            this->labelNumerPaczki->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular));
            this->labelNumerPaczki->ForeColor = System::Drawing::Color::White;
            this->labelNumerPaczki->Location = System::Drawing::Point(14, 55);
            this->labelNumerPaczki->Name = L"labelNumerPaczki";
            this->labelNumerPaczki->Size = System::Drawing::Size(120, 21);
            this->labelNumerPaczki->Text = L"Numer paczki: ";

            // pictureBoxKodKreskowy
            this->pictureBoxKodKreskowy->Location = System::Drawing::Point(18, 90);
            this->pictureBoxKodKreskowy->Name = L"pictureBoxKodKreskowy";
            this->pictureBoxKodKreskowy->Size = System::Drawing::Size(350, 80);
            this->pictureBoxKodKreskowy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;

            // buttonZamknij
            this->buttonZamknij->BackColor = System::Drawing::Color::FromArgb(0, 122, 204);
            this->buttonZamknij->FlatAppearance->BorderSize = 0;
            this->buttonZamknij->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonZamknij->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
            this->buttonZamknij->ForeColor = System::Drawing::Color::White;
            this->buttonZamknij->Location = System::Drawing::Point(18, 190);
            this->buttonZamknij->Name = L"buttonZamknij";
            this->buttonZamknij->Size = System::Drawing::Size(350, 35);
            this->buttonZamknij->Text = L"Zamknij";
            this->buttonZamknij->Click += gcnew System::EventHandler(this, &EtykietaForm::buttonZamknij_Click);

            // EtykietaForm
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
            this->ClientSize = System::Drawing::Size(384, 241);
            this->Controls->Add(this->buttonZamknij);
            this->Controls->Add(this->pictureBoxKodKreskowy);
            this->Controls->Add(this->labelNumerPaczki);
            this->Controls->Add(this->labelTytul);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"EtykietaForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Wydruk Etykiety";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxKodKreskowy))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        // Metoda do generowania wizualizacji kodu kreskowego
        Bitmap^ generujKodKreskowy(String^ tekst) {
            std::string stdText = msclr::interop::marshal_as<std::string>(tekst);
            int width = 350;
            int height = 80;
            Bitmap^ bmp = gcnew Bitmap(width, height);
            Graphics^ g = Graphics::FromImage(bmp);

            g->Clear(Color::White);

            int currentX = 10;
            SolidBrush^ blackBrush = gcnew SolidBrush(Color::Black);

            // Prosta wizualizacja: ka¿dy znak to kreska o innej szerokoœci
            for (char& c : stdText) {
                int barWidth = (c % 4) + 1; // Szerokoœæ kreski od 1 do 4 pikseli
                if (currentX + barWidth < width) {
                    g->FillRectangle(blackBrush, currentX, 0, barWidth, height);
                }
                currentX += barWidth + 2; // Kreska + 2 piksele przerwy
            }

            delete g;
            delete blackBrush;
            return bmp;
        }

        System::Void buttonZamknij_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}