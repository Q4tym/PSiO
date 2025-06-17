#pragma once

#include <string>
#include "msclr/marshal_cppstd.h"
#include "Klasy.h" // Potrzebne do obiektu Paczka

namespace PSiO {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Drawing::Imaging;
    using namespace System::Drawing::Text;

    public ref class EtykietaForm : public Form {
    public:
        EtykietaForm(const Paczka& paczka)
            : numerPaczki(msclr::interop::marshal_as<String^>(paczka.getNumerPaczki()))
        {
            this->InitializeComponent();

            const Nadawca& nadawca = paczka.getNadawca();
            const Odbiorca& odbiorca = paczka.getOdbiorca();

            // Ustaw dane nadawcy
            this->labelNadawca->Text = "OD: " + msclr::interop::marshal_as<String^>(nadawca.imie) + " " + msclr::interop::marshal_as<String^>(nadawca.nazwisko);
            this->labelAdresNadawcy->Text = msclr::interop::marshal_as<String^>(nadawca.ulica) + "\n" +
                msclr::interop::marshal_as<String^>(nadawca.kodPocztowy) + " " +
                msclr::interop::marshal_as<String^>(nadawca.miasto);

            // Ustaw dane odbiorcy
            this->labelOdbiorca->Text = "DO: " + msclr::interop::marshal_as<String^>(odbiorca.imie) + " " + msclr::interop::marshal_as<String^>(odbiorca.nazwisko);
            this->labelAdresOdbiorcy->Text = msclr::interop::marshal_as<String^>(odbiorca.ulica) + "\n" +
                msclr::interop::marshal_as<String^>(odbiorca.kodPocztowy) + " " +
                msclr::interop::marshal_as<String^>(odbiorca.miasto);

            // Ustaw numer paczki i wygeneruj kod kreskowy
            this->labelNumerPaczki->Text = numerPaczki;
            this->pictureBoxKodKreskowy->Image = generujKodKreskowy(numerPaczki);

            ostatniPlikEtykiety = nullptr;
        }

        // Publiczna metoda do zapisu etykiety do pliku PNG bez pokazywania okna
        void ZapiszEtykieteDoPliku() {
            String^ fileName = numerPaczki + ".png";
            // Ukryj okno na czas renderowania (nie jest wyœwietlane, ale na wszelki wypadek)
            this->Visible = false;
            Bitmap^ bmp = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
            this->DrawToBitmap(bmp, System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height));
            bmp->Save(fileName, Imaging::ImageFormat::Png);
            ostatniPlikEtykiety = fileName;
            delete bmp;
        }

        // Getter do numeru paczki (przydatny przy automatyzacji)
        String^ GetNumerPaczki() { return numerPaczki; }

    protected:
        ~EtykietaForm() {
            if (components) {
                delete components;
            }
        }

    private:
        Label^ labelTytul;
        Label^ labelNadawca;
        Label^ labelAdresNadawcy;
        Label^ labelOdbiorca;
        Label^ labelAdresOdbiorcy;
        Label^ labelNumerPaczki;
        PictureBox^ pictureBoxKodKreskowy;
        Button^ buttonZamknij;
        Button^ buttonDrukuj;
        Button^ buttonZapisz;
        Panel^ panelSeparator;
        System::Drawing::Printing::PrintDocument^ printDocument;
        System::ComponentModel::Container^ components;
        String^ numerPaczki;
        String^ ostatniPlikEtykiety;

        void InitializeComponent() {
            this->components = (gcnew System::ComponentModel::Container());
            this->labelTytul = (gcnew System::Windows::Forms::Label());
            this->labelNadawca = (gcnew System::Windows::Forms::Label());
            this->labelAdresNadawcy = (gcnew System::Windows::Forms::Label());
            this->labelOdbiorca = (gcnew System::Windows::Forms::Label());
            this->labelAdresOdbiorcy = (gcnew System::Windows::Forms::Label());
            this->labelNumerPaczki = (gcnew System::Windows::Forms::Label());
            this->pictureBoxKodKreskowy = (gcnew System::Windows::Forms::PictureBox());
            this->buttonZamknij = (gcnew System::Windows::Forms::Button());
            this->buttonDrukuj = (gcnew System::Windows::Forms::Button());
            this->buttonZapisz = (gcnew System::Windows::Forms::Button());
            this->panelSeparator = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxKodKreskowy))->BeginInit();
            this->SuspendLayout();
            // 
            // labelTytul
            // 
            this->labelTytul->AutoSize = true;
            this->labelTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold));
            this->labelTytul->ForeColor = System::Drawing::Color::Black;
            this->labelTytul->Location = System::Drawing::Point(12, 9);
            this->labelTytul->Name = L"labelTytul";
            this->labelTytul->Size = System::Drawing::Size(212, 25);
            this->labelTytul->Text = L"ETYKIETA PRZEWOZOWA";
            // 
            // labelNadawca
            // 
            this->labelNadawca->AutoSize = true;
            this->labelNadawca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
            this->labelNadawca->Location = System::Drawing::Point(14, 50);
            this->labelNadawca->Name = L"labelNadawca";
            this->labelNadawca->Size = System::Drawing::Size(33, 17);
            this->labelNadawca->Text = L"OD:";
            // 
            // labelAdresNadawcy
            // 
            this->labelAdresNadawcy->AutoSize = true;
            this->labelAdresNadawcy->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
            this->labelAdresNadawcy->Location = System::Drawing::Point(14, 70);
            this->labelAdresNadawcy->Name = L"labelAdresNadawcy";
            this->labelAdresNadawcy->Size = System::Drawing::Size(88, 17);
            this->labelAdresNadawcy->Text = L"Adres nadawcy";
            // 
            // labelOdbiorca
            // 
            this->labelOdbiorca->AutoSize = true;
            this->labelOdbiorca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold));
            this->labelOdbiorca->Location = System::Drawing::Point(12, 130);
            this->labelOdbiorca->Name = L"labelOdbiorca";
            this->labelOdbiorca->Size = System::Drawing::Size(48, 25);
            this->labelOdbiorca->Text = L"DO:";
            // 
            // labelAdresOdbiorcy
            // 
            this->labelAdresOdbiorcy->AutoSize = true;
            this->labelAdresOdbiorcy->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->labelAdresOdbiorcy->Location = System::Drawing::Point(13, 160);
            this->labelAdresOdbiorcy->Name = L"labelAdresOdbiorcy";
            this->labelAdresOdbiorcy->Size = System::Drawing::Size(114, 21);
            this->labelAdresOdbiorcy->Text = L"Adres odbiorcy";
            // 
            // panelSeparator
            // 
            this->panelSeparator->BackColor = System::Drawing::Color::Black;
            this->panelSeparator->Location = System::Drawing::Point(12, 220);
            this->panelSeparator->Name = L"panelSeparator";
            this->panelSeparator->Size = System::Drawing::Size(460, 2);
            // 
            // labelNumerPaczki
            // 
            this->labelNumerPaczki->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->labelNumerPaczki->Location = System::Drawing::Point(12, 330);
            this->labelNumerPaczki->Name = L"labelNumerPaczki";
            this->labelNumerPaczki->Size = System::Drawing::Size(460, 23);
            this->labelNumerPaczki->Text = L"numerPaczki";
            this->labelNumerPaczki->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pictureBoxKodKreskowy
            // 
            this->pictureBoxKodKreskowy->Location = System::Drawing::Point(12, 235);
            this->pictureBoxKodKreskowy->Name = L"pictureBoxKodKreskowy";
            this->pictureBoxKodKreskowy->Size = System::Drawing::Size(460, 90);
            this->pictureBoxKodKreskowy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            // 
            // buttonZamknij
            // 
            this->buttonZamknij->BackColor = System::Drawing::Color::FromArgb(210, 210, 210);
            this->buttonZamknij->FlatAppearance->BorderSize = 1;
            this->buttonZamknij->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonZamknij->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
            this->buttonZamknij->ForeColor = System::Drawing::Color::Black;
            this->buttonZamknij->Location = System::Drawing::Point(12, 370);
            this->buttonZamknij->Name = L"buttonZamknij";
            this->buttonZamknij->Size = System::Drawing::Size(460, 35);
            this->buttonZamknij->Text = L"Zamknij";
            this->buttonZamknij->Click += gcnew System::EventHandler(this, &EtykietaForm::buttonZamknij_Click);
            // 
            // buttonDrukuj
            // 
            this->buttonDrukuj->BackColor = System::Drawing::Color::FromArgb(210, 210, 210);
            this->buttonDrukuj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonDrukuj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
            this->buttonDrukuj->ForeColor = System::Drawing::Color::Black;
            this->buttonDrukuj->Location = System::Drawing::Point(12, 410);
            this->buttonDrukuj->Name = L"buttonDrukuj";
            this->buttonDrukuj->Size = System::Drawing::Size(460, 35);
            this->buttonDrukuj->Text = L"Drukuj";
            this->buttonDrukuj->Click += gcnew System::EventHandler(this, &EtykietaForm::buttonDrukuj_Click);
            // 
            // buttonZapisz
            // 
            this->buttonZapisz->BackColor = System::Drawing::Color::FromArgb(210, 210, 210);
            this->buttonZapisz->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonZapisz->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
            this->buttonZapisz->ForeColor = System::Drawing::Color::Black;
            this->buttonZapisz->Location = System::Drawing::Point(12, 450);
            this->buttonZapisz->Name = L"buttonZapisz";
            this->buttonZapisz->Size = System::Drawing::Size(460, 35);
            this->buttonZapisz->Text = L"Zapisz etykietê do pliku";
            this->buttonZapisz->Click += gcnew System::EventHandler(this, &EtykietaForm::buttonZapisz_Click);
            // 
            // EtykietaForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(484, 500);
            this->Controls->Add(this->buttonZapisz);
            this->Controls->Add(this->buttonDrukuj);
            this->Controls->Add(this->buttonZamknij);
            this->Controls->Add(this->pictureBoxKodKreskowy);
            this->Controls->Add(this->labelNumerPaczki);
            this->Controls->Add(this->panelSeparator);
            this->Controls->Add(this->labelAdresOdbiorcy);
            this->Controls->Add(this->labelOdbiorca);
            this->Controls->Add(this->labelAdresNadawcy);
            this->Controls->Add(this->labelNadawca);
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

        Bitmap^ generujKodKreskowy(String^ tekst) {
            const int width = 460;
            const int height = 90;
            Bitmap^ bmp = gcnew Bitmap(width, height);
            Graphics^ g = Graphics::FromImage(bmp);
            g->Clear(Color::White);

            int barWidths[] = { 1, 1, 2, 2, 3, 3, 1, 2, 3, 1 }; // Proste mapowanie dla cyfr 0-9
            int currentX = 20;
            SolidBrush^ blackBrush = gcnew SolidBrush(Color::Black);
            std::string stdText = msclr::interop::marshal_as<std::string>(tekst);

            for (char& c : stdText) {
                if (isdigit(c)) {
                    int digit = c - '0';
                    int barWidth = barWidths[digit] * 2; // Mno¿nik dla lepszej widocznoœci
                    g->FillRectangle(blackBrush, currentX, 0, barWidth, height);
                    currentX += barWidth;
                }
                currentX += 2; // Przerwa miêdzy kreskami
                if (currentX >= width - 20) break;
            }

            delete g;
            delete blackBrush;
            return bmp;
        }

        System::Void buttonZamknij_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }

        System::Void buttonZapisz_Click(System::Object^ sender, System::EventArgs^ e) {
            ZapiszEtykieteDoPliku();
            MessageBox::Show("Etykieta zosta³a zapisana do pliku:\n" + numerPaczki + ".png", "Zapisano", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void buttonDrukuj_Click(System::Object^ sender, System::EventArgs^ e) {
            if (String::IsNullOrEmpty(ostatniPlikEtykiety) || !System::IO::File::Exists(ostatniPlikEtykiety)) {
                MessageBox::Show("Najpierw zapisz etykietê do pliku!", "Brak pliku", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            printDocument = gcnew System::Drawing::Printing::PrintDocument();
            printDocument->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &EtykietaForm::printDocument_PrintPage);
            System::Windows::Forms::PrintDialog^ dlg = gcnew System::Windows::Forms::PrintDialog();
            dlg->Document = printDocument;
            if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                printDocument->Print();
            }
        }

        void printDocument_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
            if (!String::IsNullOrEmpty(ostatniPlikEtykiety) && System::IO::File::Exists(ostatniPlikEtykiety)) {
                Bitmap^ bmp = gcnew Bitmap(ostatniPlikEtykiety);
                e->Graphics->DrawImage(bmp, 0, 0);
                delete bmp;
            }
        }
    };
}
