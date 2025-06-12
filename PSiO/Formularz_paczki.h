#pragma once

#include <string>
#include "Klasy.h"
#include "Utils.h"
#include "EtykietaForm.h"

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	// Klasa AnimationForm pozostaje bez zmian...
	public ref class AnimationForm : public Form {
	public:
		AnimationForm() {
			this->InitializeComponent();
			this->animationStep = 0;
			this->animationTimer->Start();
		}

	protected:
		~AnimationForm() {
			if (components) {
				delete components;
			}
		}

	private:
		System::Windows::Forms::Timer^ animationTimer;
		System::Windows::Forms::Label^ personLabel;
		System::Windows::Forms::Label^ packageLabel;
		System::Windows::Forms::Label^ truckLabel;
		System::ComponentModel::Container^ components;
		int animationStep;

		void InitializeComponent() {
			this->components = (gcnew System::ComponentModel::Container());
			this->animationTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->personLabel = (gcnew System::Windows::Forms::Label());
			this->packageLabel = (gcnew System::Windows::Forms::Label());
			this->truckLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			// animationTimer
			this->animationTimer->Interval = 15;
			this->animationTimer->Tick += gcnew System::EventHandler(this, &AnimationForm::animationTimer_Tick);

			// personLabel
			this->personLabel->AutoSize = true;
			this->personLabel->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold));
			this->personLabel->ForeColor = System::Drawing::Color::White;
			this->personLabel->Location = System::Drawing::Point(20, 50);
			this->personLabel->Name = L"personLabel";
			this->personLabel->Size = System::Drawing::Size(104, 32);
			this->personLabel->Text = L"(^_^)/";

			// packageLabel
			this->packageLabel->BackColor = System::Drawing::Color::SaddleBrown;
			this->packageLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->packageLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold));
			this->packageLabel->ForeColor = System::Drawing::Color::White;
			this->packageLabel->Location = System::Drawing::Point(110, 60);
			this->packageLabel->Name = L"packageLabel";
			this->packageLabel->Size = System::Drawing::Size(30, 30);
			this->packageLabel->Text = L"📦";
			this->packageLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;


			// truckLabel
			this->truckLabel->AutoSize = true;
			this->truckLabel->Font = (gcnew System::Drawing::Font(L"Consolas", 48, System::Drawing::FontStyle::Bold));
			this->truckLabel->ForeColor = System::Drawing::Color::LightGray;
			this->truckLabel->Location = System::Drawing::Point(350, 25);
			this->truckLabel->Name = L"truckLabel";
			this->truckLabel->Size = System::Drawing::Size(102, 75);
			this->truckLabel->Text = L"🚛";

			// AnimationForm
			this->ClientSize = System::Drawing::Size(500, 120);
			this->Controls->Add(this->truckLabel);
			this->Controls->Add(this->packageLabel);
			this->Controls->Add(this->personLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->BackColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->Name = L"AnimationForm";
			this->ResumeLayout(false);
			this->PerformLayout();
		}

		void animationTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			int targetX = this->truckLabel->Location.X - this->packageLabel->Width;
			int currentX = this->packageLabel->Location.X;

			if (currentX < targetX) {
				this->packageLabel->Left += 5;
				// Prosty ruch paraboliczny
				double progress = (double)(this->packageLabel->Left - 110) / (targetX - 110);
				this->packageLabel->Top = 60 - (int)(60 * sin(progress * 3.14159));
			}
			else {
				this->animationTimer->Stop();
				System::Threading::Thread::Sleep(500); // Krótka pauza
				this->Close();
			}
		}
	};

	public ref class Formularz_paczki : public System::Windows::Forms::Form
	{
	public:
		Formularz_paczki(void);

	protected:
		~Formularz_paczki();

	private:
		System::String^ fileName;
		// --- Deklaracje wszystkich kontrolek ---
		System::Windows::Forms::GroupBox^ groupNadawca;
		System::Windows::Forms::TextBox^ textNadawcaImie;
		System::Windows::Forms::Label^ labelNadawcaImie;
		System::Windows::Forms::TextBox^ textNadawcaNazwisko;
		System::Windows::Forms::Label^ labelNadawcaNazwisko;
		System::Windows::Forms::TextBox^ textNadawcaTelefon;
		System::Windows::Forms::Label^ labelNadawcaTelefon;
		System::Windows::Forms::TextBox^ textNadawcaEmail;
		System::Windows::Forms::Label^ labelNadawcaEmail;
		System::Windows::Forms::TextBox^ textNadawcaUlica;
		System::Windows::Forms::Label^ labelNadawcaUlica;
		System::Windows::Forms::TextBox^ textNadawcaMiasto;
		System::Windows::Forms::Label^ labelNadawcaMiasto;
		System::Windows::Forms::TextBox^ textNadawcaWojewodztwo;
		System::Windows::Forms::Label^ labelNadawcaWojewodztwo;
		System::Windows::Forms::TextBox^ textNadawcaKod;
		System::Windows::Forms::Label^ labelNadawcaKod;
		System::Windows::Forms::TextBox^ textNadawcaKraj;
		System::Windows::Forms::Label^ labelNadawcaKraj;
		System::Windows::Forms::GroupBox^ groupOdbiorca;
		System::Windows::Forms::TextBox^ textOdbiorcaImie;
		System::Windows::Forms::Label^ labelOdbiorcaImie;
		System::Windows::Forms::TextBox^ textOdbiorcaNazwisko;
		System::Windows::Forms::Label^ labelOdbiorcaNazwisko;
		System::Windows::Forms::TextBox^ textOdbiorcaTelefon;
		System::Windows::Forms::Label^ labelOdbiorcaTelefon;
		System::Windows::Forms::TextBox^ textOdbiorcaEmail;
		System::Windows::Forms::Label^ labelOdbiorcaEmail;
		System::Windows::Forms::TextBox^ textOdbiorcaUlica;
		System::Windows::Forms::Label^ labelOdbiorcaUlica;
		System::Windows::Forms::TextBox^ textOdbiorcaMiasto;
		System::Windows::Forms::Label^ labelOdbiorcaMiasto;
		System::Windows::Forms::TextBox^ textOdbiorcaWojewodztwo;
		System::Windows::Forms::Label^ labelOdbiorcaWojewodztwo;
		System::Windows::Forms::TextBox^ textOdbiorcaKod;
		System::Windows::Forms::Label^ labelOdbiorcaKod;
		System::Windows::Forms::TextBox^ textOdbiorcaKraj;
		System::Windows::Forms::Label^ labelOdbiorcaKraj;
		System::Windows::Forms::GroupBox^ groupPaczka;
		System::Windows::Forms::RadioButton^ radioMala;
		System::Windows::Forms::RadioButton^ radioSrednia;
		System::Windows::Forms::RadioButton^ radioDuza;
		System::Windows::Forms::Button^ buttonNadaj;
		System::Windows::Forms::Button^ buttonAnuluj;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda obsługi projektanta — nie należy modyfikować 
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			// Inicjalizacja wszystkich kontrolek
			this->groupNadawca = (gcnew System::Windows::Forms::GroupBox());
			this->textNadawcaImie = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaImie = (gcnew System::Windows::Forms::Label());
			this->textNadawcaNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaNazwisko = (gcnew System::Windows::Forms::Label());
			this->textNadawcaTelefon = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaTelefon = (gcnew System::Windows::Forms::Label());
			this->textNadawcaEmail = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaEmail = (gcnew System::Windows::Forms::Label());
			this->textNadawcaUlica = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaUlica = (gcnew System::Windows::Forms::Label());
			this->textNadawcaMiasto = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaMiasto = (gcnew System::Windows::Forms::Label());
			this->textNadawcaWojewodztwo = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaWojewodztwo = (gcnew System::Windows::Forms::Label());
			this->textNadawcaKod = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaKod = (gcnew System::Windows::Forms::Label());
			this->textNadawcaKraj = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaKraj = (gcnew System::Windows::Forms::Label());

			this->groupOdbiorca = (gcnew System::Windows::Forms::GroupBox());
			this->textOdbiorcaImie = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaImie = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaNazwisko = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaTelefon = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaTelefon = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaEmail = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaEmail = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaUlica = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaUlica = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaMiasto = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaMiasto = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaWojewodztwo = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaWojewodztwo = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaKod = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaKod = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaKraj = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaKraj = (gcnew System::Windows::Forms::Label());

			this->groupPaczka = (gcnew System::Windows::Forms::GroupBox());
			this->radioMala = (gcnew System::Windows::Forms::RadioButton());
			this->radioSrednia = (gcnew System::Windows::Forms::RadioButton());
			this->radioDuza = (gcnew System::Windows::Forms::RadioButton());
			this->buttonNadaj = (gcnew System::Windows::Forms::Button());
			this->buttonAnuluj = (gcnew System::Windows::Forms::Button());

			this->groupNadawca->SuspendLayout();
			this->groupOdbiorca->SuspendLayout();
			this->groupPaczka->SuspendLayout();
			this->SuspendLayout();

			// --- Konfiguracja GroupBox Nadawcy ---
			this->groupNadawca->Controls->AddRange(gcnew cli::array< System::Windows::Forms::Control^  >(18) {
				this->labelNadawcaImie, this->textNadawcaImie, this->labelNadawcaNazwisko, this->textNadawcaNazwisko,
					this->labelNadawcaTelefon, this->textNadawcaTelefon, this->labelNadawcaEmail, this->textNadawcaEmail,
					this->labelNadawcaUlica, this->textNadawcaUlica, this->labelNadawcaMiasto, this->textNadawcaMiasto,
					this->labelNadawcaWojewodztwo, this->textNadawcaWojewodztwo, this->labelNadawcaKod, this->textNadawcaKod,
					this->labelNadawcaKraj, this->textNadawcaKraj
			});
			this->groupNadawca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->groupNadawca->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->groupNadawca->Location = System::Drawing::Point(12, 12);
			this->groupNadawca->Name = L"groupNadawca";
			this->groupNadawca->Size = System::Drawing::Size(310, 470);
			this->groupNadawca->TabIndex = 0;
			this->groupNadawca->TabStop = false;
			this->groupNadawca->Text = L"Dane Nadawcy";

			// --- Konfiguracja GroupBox Odbiorcy ---
			this->groupOdbiorca->Controls->AddRange(gcnew cli::array< System::Windows::Forms::Control^  >(18) {
				this->labelOdbiorcaImie, this->textOdbiorcaImie, this->labelOdbiorcaNazwisko, this->textOdbiorcaNazwisko,
					this->labelOdbiorcaTelefon, this->textOdbiorcaTelefon, this->labelOdbiorcaEmail, this->textOdbiorcaEmail,
					this->labelOdbiorcaUlica, this->textOdbiorcaUlica, this->labelOdbiorcaMiasto, this->textOdbiorcaMiasto,
					this->labelOdbiorcaWojewodztwo, this->textOdbiorcaWojewodztwo, this->labelOdbiorcaKod, this->textOdbiorcaKod,
					this->labelOdbiorcaKraj, this->textOdbiorcaKraj
			});
			this->groupOdbiorca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->groupOdbiorca->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->groupOdbiorca->Location = System::Drawing::Point(338, 12);
			this->groupOdbiorca->Name = L"groupOdbiorca";
			this->groupOdbiorca->Size = System::Drawing::Size(310, 470);
			this->groupOdbiorca->TabIndex = 1;
			this->groupOdbiorca->TabStop = false;
			this->groupOdbiorca->Text = L"Dane Odbiorcy";

			// Konfiguracja kontrolek (etykiety i pola tekstowe)
			int yPos = 30;
			int yStep = 50;
			for (int i = 0; i < 2; ++i) {
				GroupBox^ currentGroup = (i == 0) ? groupNadawca : groupOdbiorca;
				auto controls = currentGroup->Controls;
				yPos = 30;
				for (int j = 0; j < controls->Count / 2; ++j) {
					Label^ lbl = dynamic_cast<Label^>(controls[j * 2]);
					TextBox^ txt = dynamic_cast<TextBox^>(controls[j * 2 + 1]);

					lbl->AutoSize = true;
					lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
					lbl->ForeColor = System::Drawing::Color::Gainsboro;
					lbl->Location = System::Drawing::Point(17, yPos - 18);

					txt->BackColor = System::Drawing::Color::FromArgb(50, 50, 50);
					txt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					txt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
					txt->ForeColor = System::Drawing::Color::White;
					txt->Location = System::Drawing::Point(20, yPos);
					txt->Size = System::Drawing::Size(270, 25);

					yPos += yStep;
				}
			}

			// Ustawienie etykiet tekstowych
			labelNadawcaImie->Text = L"Imię";
			labelNadawcaNazwisko->Text = L"Nazwisko";
			labelNadawcaTelefon->Text = L"Telefon";
			labelNadawcaEmail->Text = L"E-mail";
			labelNadawcaUlica->Text = L"Ulica i numer";
			labelNadawcaMiasto->Text = L"Miasto";
			labelNadawcaWojewodztwo->Text = L"Województwo";
			labelNadawcaKod->Text = L"Kod pocztowy";
			labelNadawcaKraj->Text = L"Kraj";

			labelOdbiorcaImie->Text = L"Imię";
			labelOdbiorcaNazwisko->Text = L"Nazwisko";
			labelOdbiorcaTelefon->Text = L"Telefon";
			labelOdbiorcaEmail->Text = L"E-mail";
			labelOdbiorcaUlica->Text = L"Ulica i numer";
			labelOdbiorcaMiasto->Text = L"Miasto";
			labelOdbiorcaWojewodztwo->Text = L"Województwo";
			labelOdbiorcaKod->Text = L"Kod pocztowy";
			labelOdbiorcaKraj->Text = L"Kraj";

			// --- Konfiguracja GroupBox Paczka (Rozmiar) ---
			this->groupPaczka->Controls->Add(this->radioDuza);
			this->groupPaczka->Controls->Add(this->radioSrednia);
			this->groupPaczka->Controls->Add(this->radioMala);
			this->groupPaczka->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->groupPaczka->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->groupPaczka->Location = System::Drawing::Point(12, 490);
			this->groupPaczka->Name = L"groupPaczka";
			this->groupPaczka->Size = System::Drawing::Size(636, 60);
			this->groupPaczka->TabIndex = 2;
			this->groupPaczka->TabStop = false;
			this->groupPaczka->Text = L"Rozmiar Paczki";

			// radioMala
			this->radioMala->AutoSize = true;
			this->radioMala->Checked = true;
			this->radioMala->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->radioMala->ForeColor = System::Drawing::Color::White;
			this->radioMala->Location = System::Drawing::Point(20, 25);
			this->radioMala->Name = L"radioMala";
			this->radioMala->Size = System::Drawing::Size(98, 21);
			this->radioMala->Text = L"Mała (A)";
			this->radioMala->UseVisualStyleBackColor = true;

			// radioSrednia
			this->radioSrednia->AutoSize = true;
			this->radioSrednia->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->radioSrednia->ForeColor = System::Drawing::Color::White;
			this->radioSrednia->Location = System::Drawing::Point(250, 25);
			this->radioSrednia->Name = L"radioSrednia";
			this->radioSrednia->Size = System::Drawing::Size(107, 21);
			this->radioSrednia->Text = L"Średnia (B)";
			this->radioSrednia->UseVisualStyleBackColor = true;

			// radioDuza
			this->radioDuza->AutoSize = true;
			this->radioDuza->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->radioDuza->ForeColor = System::Drawing::Color::White;
			this->radioDuza->Location = System::Drawing::Point(480, 25);
			this->radioDuza->Name = L"radioDuza";
			this->radioDuza->Size = System::Drawing::Size(96, 21);
			this->radioDuza->Text = L"Duża (C)";
			this->radioDuza->UseVisualStyleBackColor = true;

			// buttonNadaj
			this->buttonNadaj->BackColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->buttonNadaj->FlatAppearance->BorderSize = 0;
			this->buttonNadaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonNadaj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->buttonNadaj->ForeColor = System::Drawing::Color::White;
			this->buttonNadaj->Location = System::Drawing::Point(338, 560);
			this->buttonNadaj->Name = L"buttonNadaj";
			this->buttonNadaj->Size = System::Drawing::Size(310, 41);
			this->buttonNadaj->TabIndex = 3;
			this->buttonNadaj->Text = L"Nadaj Paczkę";
			this->buttonNadaj->UseVisualStyleBackColor = false;
			this->buttonNadaj->Click += gcnew System::EventHandler(this, &Formularz_paczki::buttonNadaj_Click);

			// buttonAnuluj
			this->buttonAnuluj->BackColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->buttonAnuluj->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonAnuluj->FlatAppearance->BorderSize = 0;
			this->buttonAnuluj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAnuluj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->buttonAnuluj->ForeColor = System::Drawing::Color::White;
			this->buttonAnuluj->Location = System::Drawing::Point(12, 560);
			this->buttonAnuluj->Name = L"buttonAnuluj";
			this->buttonAnuluj->Size = System::Drawing::Size(310, 41);
			this->buttonAnuluj->TabIndex = 4;
			this->buttonAnuluj->Text = L"Anuluj";
			this->buttonAnuluj->UseVisualStyleBackColor = false;
			this->buttonAnuluj->Click += gcnew System::EventHandler(this, &Formularz_paczki::buttonAnuluj_Click);

			// Formularz_paczki
			this->AcceptButton = this->buttonNadaj;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->CancelButton = this->buttonAnuluj;
			this->ClientSize = System::Drawing::Size(664, 615);
			this->Controls->Add(this->buttonAnuluj);
			this->Controls->Add(this->buttonNadaj);
			this->Controls->Add(this->groupPaczka);
			this->Controls->Add(this->groupOdbiorca);
			this->Controls->Add(this->groupNadawca);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"Formularz_paczki";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Nowa Paczka";
			this->groupNadawca->ResumeLayout(false);
			this->groupNadawca->PerformLayout();
			this->groupOdbiorca->ResumeLayout(false);
			this->groupOdbiorca->PerformLayout();
			this->groupPaczka->ResumeLayout(false);
			this->groupPaczka->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion
	private:
		// Pozostawiamy tylko deklaracje metod, których implementacja jest w pliku .cpp
		System::Void buttonAnuluj_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonNadaj_Click(System::Object^ sender, System::EventArgs^ e);
	};
}