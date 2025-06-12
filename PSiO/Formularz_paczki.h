#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "json.hpp"
#include "Klasy.h"
#include "Utils.h" // Konwersja String^ na std::string
#include "EtykietaForm.h" // Dołączony nowy plik nagłówkowy

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	using json = nlohmann::json;

	// --- NOWA KLASA: Formularz z animacją ---
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

	// --- GŁÓWNA KLASA FORMULARZA PACZKI ---
	public ref class Formularz_paczki : public System::Windows::Forms::Form
	{
	public:
		Formularz_paczki(void)
		{
			InitializeComponent();
			this->fileName = "paczka_data.json";
		}

	protected:
		~Formularz_paczki()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::String^ fileName;
		System::Windows::Forms::GroupBox^ groupNadawca;
		System::Windows::Forms::TextBox^ textNadawcaKod;
		System::Windows::Forms::Label^ labelNadawcaKod;
		System::Windows::Forms::TextBox^ textNadawcaMiasto;
		System::Windows::Forms::Label^ labelNadawcaMiasto;
		System::Windows::Forms::TextBox^ textNadawcaNazwisko;
		System::Windows::Forms::Label^ labelNadawcaNazwisko;
		System::Windows::Forms::TextBox^ textNadawcaImie;
		System::Windows::Forms::Label^ labelNadawcaImie;
		System::Windows::Forms::GroupBox^ groupOdbiorca;
		System::Windows::Forms::TextBox^ textOdbiorcaKod;
		System::Windows::Forms::Label^ labelOdbiorcaKod;
		System::Windows::Forms::TextBox^ textOdbiorcaMiasto;
		System::Windows::Forms::Label^ labelOdbiorcaMiasto;
		System::Windows::Forms::TextBox^ textOdbiorcaNazwisko;
		System::Windows::Forms::Label^ labelOdbiorcaNazwisko;
		System::Windows::Forms::TextBox^ textOdbiorcaImie;
		System::Windows::Forms::Label^ labelOdbiorcaImie;
		System::Windows::Forms::Button^ buttonNadaj;
		System::Windows::Forms::Button^ buttonAnuluj;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->groupNadawca = (gcnew System::Windows::Forms::GroupBox());
			this->textNadawcaKod = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaKod = (gcnew System::Windows::Forms::Label());
			this->textNadawcaMiasto = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaMiasto = (gcnew System::Windows::Forms::Label());
			this->textNadawcaNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaNazwisko = (gcnew System::Windows::Forms::Label());
			this->textNadawcaImie = (gcnew System::Windows::Forms::TextBox());
			this->labelNadawcaImie = (gcnew System::Windows::Forms::Label());
			this->groupOdbiorca = (gcnew System::Windows::Forms::GroupBox());
			this->textOdbiorcaKod = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaKod = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaMiasto = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaMiasto = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaNazwisko = (gcnew System::Windows::Forms::Label());
			this->textOdbiorcaImie = (gcnew System::Windows::Forms::TextBox());
			this->labelOdbiorcaImie = (gcnew System::Windows::Forms::Label());
			this->buttonNadaj = (gcnew System::Windows::Forms::Button());
			this->buttonAnuluj = (gcnew System::Windows::Forms::Button());
			this->groupNadawca->SuspendLayout();
			this->groupOdbiorca->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupNadawca
			// 
			this->groupNadawca->Controls->Add(this->textNadawcaKod);
			this->groupNadawca->Controls->Add(this->labelNadawcaKod);
			this->groupNadawca->Controls->Add(this->textNadawcaMiasto);
			this->groupNadawca->Controls->Add(this->labelNadawcaMiasto);
			this->groupNadawca->Controls->Add(this->textNadawcaNazwisko);
			this->groupNadawca->Controls->Add(this->labelNadawcaNazwisko);
			this->groupNadawca->Controls->Add(this->textNadawcaImie);
			this->groupNadawca->Controls->Add(this->labelNadawcaImie);
			this->groupNadawca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->groupNadawca->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->groupNadawca->Location = System::Drawing::Point(12, 12);
			this->groupNadawca->Name = L"groupNadawca";
			this->groupNadawca->Size = System::Drawing::Size(310, 250);
			this->groupNadawca->TabIndex = 0;
			this->groupNadawca->TabStop = false;
			this->groupNadawca->Text = L"Dane Nadawcy";
			// 
			// textNadawcaKod
			// 
			this->textNadawcaKod->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textNadawcaKod->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textNadawcaKod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textNadawcaKod->ForeColor = System::Drawing::Color::White;
			this->textNadawcaKod->Location = System::Drawing::Point(20, 200);
			this->textNadawcaKod->Name = L"textNadawcaKod";
			this->textNadawcaKod->Size = System::Drawing::Size(270, 25);
			this->textNadawcaKod->TabIndex = 7;
			// 
			// labelNadawcaKod
			// 
			this->labelNadawcaKod->AutoSize = true;
			this->labelNadawcaKod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelNadawcaKod->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelNadawcaKod->Location = System::Drawing::Point(17, 182);
			this->labelNadawcaKod->Name = L"labelNadawcaKod";
			this->labelNadawcaKod->Size = System::Drawing::Size(82, 15);
			this->labelNadawcaKod->TabIndex = 6;
			this->labelNadawcaKod->Text = L"Kod pocztowy";
			// 
			// textNadawcaMiasto
			// 
			this->textNadawcaMiasto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textNadawcaMiasto->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textNadawcaMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textNadawcaMiasto->ForeColor = System::Drawing::Color::White;
			this->textNadawcaMiasto->Location = System::Drawing::Point(20, 150);
			this->textNadawcaMiasto->Name = L"textNadawcaMiasto";
			this->textNadawcaMiasto->Size = System::Drawing::Size(270, 25);
			this->textNadawcaMiasto->TabIndex = 5;
			// 
			// labelNadawcaMiasto
			// 
			this->labelNadawcaMiasto->AutoSize = true;
			this->labelNadawcaMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelNadawcaMiasto->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelNadawcaMiasto->Location = System::Drawing::Point(17, 132);
			this->labelNadawcaMiasto->Name = L"labelNadawcaMiasto";
			this->labelNadawcaMiasto->Size = System::Drawing::Size(43, 15);
			this->labelNadawcaMiasto->TabIndex = 4;
			this->labelNadawcaMiasto->Text = L"Miasto";
			// 
			// textNadawcaNazwisko
			// 
			this->textNadawcaNazwisko->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textNadawcaNazwisko->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textNadawcaNazwisko->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textNadawcaNazwisko->ForeColor = System::Drawing::Color::White;
			this->textNadawcaNazwisko->Location = System::Drawing::Point(20, 100);
			this->textNadawcaNazwisko->Name = L"textNadawcaNazwisko";
			this->textNadawcaNazwisko->Size = System::Drawing::Size(270, 25);
			this->textNadawcaNazwisko->TabIndex = 3;
			// 
			// labelNadawcaNazwisko
			// 
			this->labelNadawcaNazwisko->AutoSize = true;
			this->labelNadawcaNazwisko->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelNadawcaNazwisko->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelNadawcaNazwisko->Location = System::Drawing::Point(17, 82);
			this->labelNadawcaNazwisko->Name = L"labelNadawcaNazwisko";
			this->labelNadawcaNazwisko->Size = System::Drawing::Size(57, 15);
			this->labelNadawcaNazwisko->TabIndex = 2;
			this->labelNadawcaNazwisko->Text = L"Nazwisko";
			// 
			// textNadawcaImie
			// 
			this->textNadawcaImie->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textNadawcaImie->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textNadawcaImie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textNadawcaImie->ForeColor = System::Drawing::Color::White;
			this->textNadawcaImie->Location = System::Drawing::Point(20, 50);
			this->textNadawcaImie->Name = L"textNadawcaImie";
			this->textNadawcaImie->Size = System::Drawing::Size(270, 25);
			this->textNadawcaImie->TabIndex = 1;
			// 
			// labelNadawcaImie
			// 
			this->labelNadawcaImie->AutoSize = true;
			this->labelNadawcaImie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelNadawcaImie->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelNadawcaImie->Location = System::Drawing::Point(17, 32);
			this->labelNadawcaImie->Name = L"labelNadawcaImie";
			this->labelNadawcaImie->Size = System::Drawing::Size(30, 15);
			this->labelNadawcaImie->TabIndex = 0;
			this->labelNadawcaImie->Text = L"Imię";
			// 
			// groupOdbiorca
			// 
			this->groupOdbiorca->Controls->Add(this->textOdbiorcaKod);
			this->groupOdbiorca->Controls->Add(this->labelOdbiorcaKod);
			this->groupOdbiorca->Controls->Add(this->textOdbiorcaMiasto);
			this->groupOdbiorca->Controls->Add(this->labelOdbiorcaMiasto);
			this->groupOdbiorca->Controls->Add(this->textOdbiorcaNazwisko);
			this->groupOdbiorca->Controls->Add(this->labelOdbiorcaNazwisko);
			this->groupOdbiorca->Controls->Add(this->textOdbiorcaImie);
			this->groupOdbiorca->Controls->Add(this->labelOdbiorcaImie);
			this->groupOdbiorca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->groupOdbiorca->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->groupOdbiorca->Location = System::Drawing::Point(338, 12);
			this->groupOdbiorca->Name = L"groupOdbiorca";
			this->groupOdbiorca->Size = System::Drawing::Size(310, 250);
			this->groupOdbiorca->TabIndex = 1;
			this->groupOdbiorca->TabStop = false;
			this->groupOdbiorca->Text = L"Dane Odbiorcy";
			// 
			// textOdbiorcaKod
			// 
			this->textOdbiorcaKod->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textOdbiorcaKod->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textOdbiorcaKod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textOdbiorcaKod->ForeColor = System::Drawing::Color::White;
			this->textOdbiorcaKod->Location = System::Drawing::Point(20, 200);
			this->textOdbiorcaKod->Name = L"textOdbiorcaKod";
			this->textOdbiorcaKod->Size = System::Drawing::Size(270, 25);
			this->textOdbiorcaKod->TabIndex = 7;
			// 
			// labelOdbiorcaKod
			// 
			this->labelOdbiorcaKod->AutoSize = true;
			this->labelOdbiorcaKod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelOdbiorcaKod->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelOdbiorcaKod->Location = System::Drawing::Point(17, 182);
			this->labelOdbiorcaKod->Name = L"labelOdbiorcaKod";
			this->labelOdbiorcaKod->Size = System::Drawing::Size(82, 15);
			this->labelOdbiorcaKod->TabIndex = 6;
			this->labelOdbiorcaKod->Text = L"Kod pocztowy";
			// 
			// textOdbiorcaMiasto
			// 
			this->textOdbiorcaMiasto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textOdbiorcaMiasto->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textOdbiorcaMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textOdbiorcaMiasto->ForeColor = System::Drawing::Color::White;
			this->textOdbiorcaMiasto->Location = System::Drawing::Point(20, 150);
			this->textOdbiorcaMiasto->Name = L"textOdbiorcaMiasto";
			this->textOdbiorcaMiasto->Size = System::Drawing::Size(270, 25);
			this->textOdbiorcaMiasto->TabIndex = 5;
			// 
			// labelOdbiorcaMiasto
			// 
			this->labelOdbiorcaMiasto->AutoSize = true;
			this->labelOdbiorcaMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelOdbiorcaMiasto->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelOdbiorcaMiasto->Location = System::Drawing::Point(17, 132);
			this->labelOdbiorcaMiasto->Name = L"labelOdbiorcaMiasto";
			this->labelOdbiorcaMiasto->Size = System::Drawing::Size(43, 15);
			this->labelOdbiorcaMiasto->TabIndex = 4;
			this->labelOdbiorcaMiasto->Text = L"Miasto";
			// 
			// textOdbiorcaNazwisko
			// 
			this->textOdbiorcaNazwisko->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textOdbiorcaNazwisko->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textOdbiorcaNazwisko->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textOdbiorcaNazwisko->ForeColor = System::Drawing::Color::White;
			this->textOdbiorcaNazwisko->Location = System::Drawing::Point(20, 100);
			this->textOdbiorcaNazwisko->Name = L"textOdbiorcaNazwisko";
			this->textOdbiorcaNazwisko->Size = System::Drawing::Size(270, 25);
			this->textOdbiorcaNazwisko->TabIndex = 3;
			// 
			// labelOdbiorcaNazwisko
			// 
			this->labelOdbiorcaNazwisko->AutoSize = true;
			this->labelOdbiorcaNazwisko->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelOdbiorcaNazwisko->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelOdbiorcaNazwisko->Location = System::Drawing::Point(17, 82);
			this->labelOdbiorcaNazwisko->Name = L"labelOdbiorcaNazwisko";
			this->labelOdbiorcaNazwisko->Size = System::Drawing::Size(57, 15);
			this->labelOdbiorcaNazwisko->TabIndex = 2;
			this->labelOdbiorcaNazwisko->Text = L"Nazwisko";
			// 
			// textOdbiorcaImie
			// 
			this->textOdbiorcaImie->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textOdbiorcaImie->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textOdbiorcaImie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textOdbiorcaImie->ForeColor = System::Drawing::Color::White;
			this->textOdbiorcaImie->Location = System::Drawing::Point(20, 50);
			this->textOdbiorcaImie->Name = L"textOdbiorcaImie";
			this->textOdbiorcaImie->Size = System::Drawing::Size(270, 25);
			this->textOdbiorcaImie->TabIndex = 1;
			// 
			// labelOdbiorcaImie
			// 
			this->labelOdbiorcaImie->AutoSize = true;
			this->labelOdbiorcaImie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelOdbiorcaImie->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelOdbiorcaImie->Location = System::Drawing::Point(17, 32);
			this->labelOdbiorcaImie->Name = L"labelOdbiorcaImie";
			this->labelOdbiorcaImie->Size = System::Drawing::Size(30, 15);
			this->labelOdbiorcaImie->TabIndex = 0;
			this->labelOdbiorcaImie->Text = L"Imię";
			// 
			// buttonNadaj
			// 
			this->buttonNadaj->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->buttonNadaj->FlatAppearance->BorderSize = 0;
			this->buttonNadaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonNadaj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->buttonNadaj->ForeColor = System::Drawing::Color::White;
			this->buttonNadaj->Location = System::Drawing::Point(338, 278);
			this->buttonNadaj->Name = L"buttonNadaj";
			this->buttonNadaj->Size = System::Drawing::Size(310, 41);
			this->buttonNadaj->TabIndex = 2;
			this->buttonNadaj->Text = L"Nadaj Paczkę";
			this->buttonNadaj->UseVisualStyleBackColor = false;
			this->buttonNadaj->Click += gcnew System::EventHandler(this, &Formularz_paczki::buttonNadaj_Click);
			// 
			// buttonAnuluj
			// 
			this->buttonAnuluj->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->buttonAnuluj->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonAnuluj->FlatAppearance->BorderSize = 0;
			this->buttonAnuluj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAnuluj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->buttonAnuluj->ForeColor = System::Drawing::Color::White;
			this->buttonAnuluj->Location = System::Drawing::Point(12, 278);
			this->buttonAnuluj->Name = L"buttonAnuluj";
			this->buttonAnuluj->Size = System::Drawing::Size(310, 41);
			this->buttonAnuluj->TabIndex = 3;
			this->buttonAnuluj->Text = L"Anuluj";
			this->buttonAnuluj->UseVisualStyleBackColor = false;
			this->buttonAnuluj->Click += gcnew System::EventHandler(this, &Formularz_paczki::buttonAnuluj_Click);
			// 
			// Formularz_paczki
			// 
			this->AcceptButton = this->buttonNadaj;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->CancelButton = this->buttonAnuluj;
			this->ClientSize = System::Drawing::Size(664, 341);
			this->Controls->Add(this->buttonAnuluj);
			this->Controls->Add(this->buttonNadaj);
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
			this->ResumeLayout(false);
		}
#pragma endregion
	private:
		System::Void buttonAnuluj_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void buttonNadaj_Click(System::Object^ sender, System::EventArgs^ e) {
			// Walidacja
			if (String::IsNullOrWhiteSpace(textNadawcaImie->Text) || String::IsNullOrWhiteSpace(textOdbiorcaImie->Text) ||
				String::IsNullOrWhiteSpace(textNadawcaNazwisko->Text) || String::IsNullOrWhiteSpace(textOdbiorcaNazwisko->Text) ||
				String::IsNullOrWhiteSpace(textNadawcaMiasto->Text) || String::IsNullOrWhiteSpace(textOdbiorcaMiasto->Text) ||
				String::IsNullOrWhiteSpace(textNadawcaKod->Text) || String::IsNullOrWhiteSpace(textOdbiorcaKod->Text)) {
				MessageBox::Show("Wszystkie pola muszą być wypełnione.", "Błąd Walidacji", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Tworzenie obiektów C++
			Nadawca n;
			n.imie = toStdString(textNadawcaImie->Text);
			n.nazwisko = toStdString(textNadawcaNazwisko->Text);
			n.miasto = toStdString(textNadawcaMiasto->Text);
			n.kodPocztowy = toStdString(textNadawcaKod->Text);

			Odbiorca o;
			o.imie = toStdString(textOdbiorcaImie->Text);
			o.nazwisko = toStdString(textOdbiorcaNazwisko->Text);
			o.miasto = toStdString(textOdbiorcaMiasto->Text);
			o.kodPocztowy = toStdString(textOdbiorcaKod->Text);

			Paczka nowaPaczka(n, o);

			// Zapis do pliku JSON
			std::string stdFileName = toStdString(this->fileName);
			json paczkiJson;

			// Odczytaj istniejący plik
			std::ifstream ifs(stdFileName);
			if (ifs.is_open()) {
				try {
					paczkiJson = json::parse(ifs);
					if (!paczkiJson.is_array()) paczkiJson = json::array();
				}
				catch (json::parse_error&) {
					paczkiJson = json::array(); // Plik uszkodzony, zacznij od nowa
				}
				ifs.close();
			}
			else {
				paczkiJson = json::array(); // Plik nie istnieje, utwórz nową tablicę
			}

			// Dodaj nową paczkę
			json jPaczka;
			jPaczka["numerPaczki"] = nowaPaczka.getNumerPaczki();
			jPaczka["nadawca"]["imie"] = n.imie;
			jPaczka["nadawca"]["nazwisko"] = n.nazwisko;
			jPaczka["nadawca"]["adres"]["miasto"] = n.miasto;
			jPaczka["nadawca"]["adres"]["kodPocztowy"] = n.kodPocztowy;
			jPaczka["odbiorca"]["imie"] = o.imie;
			jPaczka["odbiorca"]["nazwisko"] = o.nazwisko;
			jPaczka["odbiorca"]["adres"]["miasto"] = o.miasto;
			jPaczka["odbiorca"]["adres"]["kodPocztowy"] = o.kodPocztowy;

			paczkiJson.push_back(jPaczka);

			// Zapisz z powrotem do pliku
			std::ofstream ofs(stdFileName);
			ofs << std::setw(4) << paczkiJson << std::endl;
			ofs.close();

			String^ numerPaczki = msclr::interop::marshal_as<String^>(nowaPaczka.getNumerPaczki());
			MessageBox::Show("Paczka o numerze " + numerPaczki + " została pomyślnie nadana!", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Pokaż animację
			this->Hide();
			AnimationForm^ animForm = gcnew AnimationForm();
			animForm->ShowDialog();

			// Po zamknięciu animacji, pokaż etykietę
			EtykietaForm^ etykietaForm = gcnew EtykietaForm(numerPaczki);
			etykietaForm->ShowDialog();

			
			this->Close();
		}
	};
}