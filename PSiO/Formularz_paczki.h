#pragma once

#include "Klasy.h"
#include "json.hpp"
#include "Utils.h" // Używamy centralnej funkcji toStdString
#include <iomanip>
#include <fstream>

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Formularz_paczki : public System::Windows::Forms::Form
	{
	public:
		Formularz_paczki(void)
		{
			InitializeComponent();
			initializePlaceholders();
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
		System::String^ numerWygenerowanejPaczki;
		System::Windows::Forms::Label^ labelNadawca;
		System::Windows::Forms::Label^ labelOdbiorca;
		System::Windows::Forms::Button^ buttonUtworz;
		System::Windows::Forms::Timer^ animationTimer;
		System::Windows::Forms::Timer^ fadeOutTimer;
		System::Windows::Forms::Timer^ fadeInTimer;
		int fadeStep;

		// Kontrolki wejściowe zgrupowane dla łatwiejszego zarządzania
		System::Collections::Generic::List<TextBox^>^ inputTextBoxes;

		// Kontrolki wyjściowe (etykieta i kod kreskowy)
		System::Windows::Forms::Panel^ panelKodKreskowy;
		System::Windows::Forms::Label^ labelNumerPaczki;
		System::Windows::Forms::Label^ labelTytulKodu;

		SoundPlayer^ successSound;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->labelNadawca = (gcnew System::Windows::Forms::Label());
			this->labelOdbiorca = (gcnew System::Windows::Forms::Label());
			this->buttonUtworz = (gcnew System::Windows::Forms::Button());
			this->panelKodKreskowy = (gcnew System::Windows::Forms::Panel());
			this->labelNumerPaczki = (gcnew System::Windows::Forms::Label());
			this->labelTytulKodu = (gcnew System::Windows::Forms::Label());
			this->animationTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->fadeOutTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->fadeInTimer = (gcnew System::Windows::Forms::Timer(this->components));

			this->inputTextBoxes = gcnew System::Collections::Generic::List<TextBox^>();
			for (int i = 0; i < 18; ++i) {
				this->inputTextBoxes->Add(gcnew TextBox());
			}

			this->panelKodKreskowy->SuspendLayout();
			this->SuspendLayout();

			// 
			// labelNadawca
			// 
			this->labelNadawca->AutoSize = true;
			this->labelNadawca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold));
			this->labelNadawca->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->labelNadawca->Location = System::Drawing::Point(22, 20);
			this->labelNadawca->Text = L"NADAWCA";

			// 
			// labelOdbiorca
			// 
			this->labelOdbiorca->AutoSize = true;
			this->labelOdbiorca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold));
			this->labelOdbiorca->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->labelOdbiorca->Location = System::Drawing::Point(305, 20);
			this->labelOdbiorca->Text = L"ODBIORCA";

			// 
			// TextBoxes
			// 
			int startXNadawca = 27, startXOdbiorca = 310, startY = 60, stepY = 35;
			for (int i = 0; i < 18; ++i) {
				TextBox^ tb = this->inputTextBoxes[i];
				tb->Location = System::Drawing::Point(i < 9 ? startXNadawca : startXOdbiorca, startY + (i % 9) * stepY);
				tb->Size = System::Drawing::Size(250, 25);
				tb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
				tb->BackColor = System::Drawing::Color::FromArgb(50, 50, 50);
				tb->ForeColor = System::Drawing::Color::White;
				tb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				tb->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox_Enter);
				tb->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox_Leave);
				this->Controls->Add(tb);
			}

			// 
			// buttonUtworz
			// 
			this->buttonUtworz->BackColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->buttonUtworz->FlatAppearance->BorderSize = 0;
			this->buttonUtworz->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonUtworz->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->buttonUtworz->ForeColor = System::Drawing::Color::White;
			this->buttonUtworz->Location = System::Drawing::Point(175, 390);
			this->buttonUtworz->Size = System::Drawing::Size(230, 45);
			this->buttonUtworz->Text = L"Utwórz Przesyłkę";
			this->buttonUtworz->UseVisualStyleBackColor = false;
			this->buttonUtworz->Click += gcnew System::EventHandler(this, &Formularz_paczki::buttonUtworz_Click);

			// 
			// labelTytulKodu
			// 
			this->labelTytulKodu->AutoSize = true;
			this->labelTytulKodu->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->labelTytulKodu->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->labelTytulKodu->Location = System::Drawing::Point(36, 450);
			this->labelTytulKodu->Text = L"Etykieta została wygenerowana:";
			this->labelTytulKodu->Visible = false;

			// 
			// panelKodKreskowy
			// 
			this->panelKodKreskowy->Controls->Add(this->labelNumerPaczki);
			this->panelKodKreskowy->Location = System::Drawing::Point(40, 480);
			this->panelKodKreskowy->Size = System::Drawing::Size(500, 150);
			this->panelKodKreskowy->Visible = false;
			this->panelKodKreskowy->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Formularz_paczki::panelKodKreskowy_Paint);
			this->labelNumerPaczki->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->labelNumerPaczki->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold));
			this->labelNumerPaczki->ForeColor = System::Drawing::Color::White;
			this->labelNumerPaczki->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// animationTimer
			// 
			this->animationTimer->Interval = 15;
			this->animationTimer->Tick += gcnew System::EventHandler(this, &Formularz_paczki::animationTimer_Tick);

			// 
			// fadeOutTimer
			// 
			this->fadeOutTimer->Interval = 30;
			this->fadeOutTimer->Tick += gcnew System::EventHandler(this, &Formularz_paczki::fadeOutTimer_Tick);

			// 
			// fadeInTimer
			// 
			this->fadeInTimer->Interval = 30;
			this->fadeInTimer->Tick += gcnew System::EventHandler(this, &Formularz_paczki::fadeInTimer_Tick);

			// 
			// Formularz_paczki
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->ClientSize = System::Drawing::Size(583, 650);
			this->Controls->Add(this->labelTytulKodu);
			this->Controls->Add(this->panelKodKreskowy);
			this->Controls->Add(this->buttonUtworz);
			this->Controls->Add(this->labelOdbiorca);
			this->Controls->Add(this->labelNadawca);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"Formularz_paczki";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Formularz nadania paczki";
			this->panelKodKreskowy->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

			// Load custom sound
			this->successSound = gcnew SoundPlayer("success.wav");
		}
#pragma endregion

	private:
		void initializePlaceholders() {
			array<String^>^ placeholders = {
				"Imię nadawcy", "Nazwisko nadawcy", "Telefon nadawcy", "Email nadawcy", "Ulica nadawcy", "Miasto nadawcy", "Województwo nadawcy", "Kod pocztowy nadawcy", "Kraj nadawcy",
				"Kraj odbiorcy", "Kod pocztowy odbiorcy", "Województwo odbiorcy", "Miasto odbiorcy", "Ulica odbiorcy", "Email odbiorcy", "Telefon odbiorcy", "Nazwisko odbiorcy", "Imię odbiorcy"
			};

			for (int i = 0; i < this->inputTextBoxes->Count; ++i) {
				TextBox^ tb = this->inputTextBoxes[i];
				String^ placeholder = (i < 9) ? placeholders[i] : placeholders[17 - (i - 9)];
				tb->Tag = placeholder;
				tb->Text = placeholder;
				tb->ForeColor = Color::Gray;
			}
		}

		System::Void textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
			TextBox^ tb = dynamic_cast<TextBox^>(sender);
			if (tb->ForeColor == Color::Gray) {
				tb->Text = "";
				tb->ForeColor = Color::White;
			}
		}

		System::Void textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			TextBox^ tb = dynamic_cast<TextBox^>(sender);
			if (String::IsNullOrWhiteSpace(tb->Text)) {
				tb->Text = safe_cast<String^>(tb->Tag);
				tb->ForeColor = Color::Gray;
			}
		}

		System::Void panelKodKreskowy_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			if (String::IsNullOrEmpty(this->numerWygenerowanejPaczki)) return;

			Graphics^ g = e->Graphics;
			Random^ rand = gcnew Random(this->numerWygenerowanejPaczki->GetHashCode());
			int panelWidth = panelKodKreskowy->Width;
			int panelHeight = panelKodKreskowy->Height - 30;
			g->Clear(this->BackColor);

			for (int x = 0; x < panelWidth; ) {
				int lineWidth = rand->Next(1, 5);
				if (x + lineWidth > panelWidth) lineWidth = panelWidth - x;
				g->FillRectangle(Brushes::White, x, 0, lineWidth, panelHeight);
				int spaceWidth = rand->Next(1, 5);
				x += lineWidth + spaceWidth;
			}
		}

		System::Void buttonUtworz_Click(System::Object^ sender, System::EventArgs^ e) {
			// Walidacja - miasto nadawcy i odbiorcy
			if (this->inputTextBoxes[5]->ForeColor == Color::Gray || this->inputTextBoxes[12]->ForeColor == Color::Gray) {
				MessageBox::Show("Proszę wypełnić przynajmniej miasto nadawcy i odbiorcy.", "Błąd Walidacji", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Tworzenie obiektów
			Nadawca nadawcaObj;
			nadawcaObj.imie = toStdString(this->inputTextBoxes[0]->Text);
			nadawcaObj.nazwisko = toStdString(this->inputTextBoxes[1]->Text);
			nadawcaObj.miasto = toStdString(this->inputTextBoxes[5]->Text);
			nadawcaObj.kodPocztowy = toStdString(this->inputTextBoxes[7]->Text);

			Odbiorca odbiorcaObj;
			odbiorcaObj.imie = toStdString(this->inputTextBoxes[17]->Text);
			odbiorcaObj.nazwisko = toStdString(this->inputTextBoxes[16]->Text);
			odbiorcaObj.miasto = toStdString(this->inputTextBoxes[12]->Text);
			odbiorcaObj.kodPocztowy = toStdString(this->inputTextBoxes[10]->Text);

			// Tworzenie paczki i zapis
			Paczka paczka(nadawcaObj, odbiorcaObj);
			this->numerWygenerowanejPaczki = msclr::interop::marshal_as<String^>(paczka.getNumerPaczki());

			// Zapis do JSON
			nlohmann::json new_package_json;
			new_package_json["numerPaczki"] = paczka.getNumerPaczki();
			new_package_json["nadawca"] = { {"imie", paczka.getNadawca().imie}, {"nazwisko", paczka.getNadawca().nazwisko}, {"adres", {{"miasto", paczka.getNadawca().miasto}, {"kodPocztowy", paczka.getNadawca().kodPocztowy}}} };
			new_package_json["odbiorca"] = { {"imie", paczka.getOdbiorca().imie}, {"nazwisko", paczka.getOdbiorca().nazwisko}, {"adres", {{"miasto", paczka.getOdbiorca().miasto}, {"kodPocztowy", paczka.getOdbiorca().kodPocztowy}}} };

			std::string filename = "paczka_data.json";
			nlohmann::json existing_data_array = nlohmann::json::array();
			std::ifstream ifs(filename);
			if (ifs.is_open()) {
				try { ifs >> existing_data_array; }
				catch (nlohmann::json::parse_error&) {}
				ifs.close();
			}
			if (!existing_data_array.is_array()) { existing_data_array = nlohmann::json::array(); }
			existing_data_array.push_back(new_package_json);

			std::ofstream ofs(filename);
			if (ofs.is_open()) {
				ofs << std::setw(4) << existing_data_array << std::endl;
				ofs.close();

				// Play fancy sound on success
				this->successSound->Play();

				// Start animation sequence
				fadeStep = 20;
				fadeOutTimer->Start();

				MessageBox::Show("Paczka została pomyślnie zarejestrowana!\nNumer: " + this->numerWygenerowanejPaczki, "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Błąd: Nie można zapisać pliku paczka_data.json", "Błąd Zapisu", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		// Animation step timers
		System