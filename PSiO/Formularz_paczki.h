#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Klasy.h" 
#include "json.hpp" 
#include <msclr/marshal_cppstd.h>

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media; // Dla SystemSounds

	// Funkcja pomocnicza do konwersji System::String^ na std::string
	inline std::string toStdString(System::String^ str) {
		if (String::IsNullOrEmpty(str)) {
			return std::string();
		}
		msclr::interop::marshal_context context;
		return context.marshal_as<std::string>(str);
	}

	public ref class Formularz_paczki : public System::Windows::Forms::Form
	{
	public:
		Formularz_paczki(void)
		{
			InitializeComponent();
			initializePlaceholders(); // Wywołanie nowej, ulepszonej funkcji
		}

	protected:
		~Formularz_paczki()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::String^ numerWygenerowanejPaczki;

	private: System::Windows::Forms::Label^ labelNadawca;
	private: System::Windows::Forms::Label^ labelOdbiorca;
	private: System::Windows::Forms::Button^ buttonUtworz;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::TextBox^ textBox18;

	private: System::Windows::Forms::Panel^ panelKodKreskowy;
	private: System::Windows::Forms::Label^ labelNumerPaczki;
	private: System::Windows::Forms::Label^ labelTytulKodu;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->labelNadawca = (gcnew System::Windows::Forms::Label());
			   this->labelOdbiorca = (gcnew System::Windows::Forms::Label());
			   this->buttonUtworz = (gcnew System::Windows::Forms::Button());
			   this->panelKodKreskowy = (gcnew System::Windows::Forms::Panel());
			   this->labelNumerPaczki = (gcnew System::Windows::Forms::Label());
			   this->labelTytulKodu = (gcnew System::Windows::Forms::Label());

			   this->textBox1 = (gcnew System::Windows::Forms::TextBox()); this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox()); this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox()); this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox7 = (gcnew System::Windows::Forms::TextBox()); this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox9 = (gcnew System::Windows::Forms::TextBox()); this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox11 = (gcnew System::Windows::Forms::TextBox()); this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox13 = (gcnew System::Windows::Forms::TextBox()); this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox15 = (gcnew System::Windows::Forms::TextBox()); this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox17 = (gcnew System::Windows::Forms::TextBox()); this->textBox18 = (gcnew System::Windows::Forms::TextBox());

			   this->SuspendLayout();
			   this->panelKodKreskowy->SuspendLayout();

			   // Etykiety
			   this->labelNadawca->AutoSize = true;
			   this->labelNadawca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold));
			   this->labelNadawca->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			   this->labelNadawca->Location = System::Drawing::Point(22, 20);
			   this->labelNadawca->Text = L"NADAWCA";

			   this->labelOdbiorca->AutoSize = true;
			   this->labelOdbiorca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold));
			   this->labelOdbiorca->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			   this->labelOdbiorca->Location = System::Drawing::Point(305, 20);
			   this->labelOdbiorca->Text = L"ODBIORCA";

			   // TextBoxes - pętla do ustawień
			   array<TextBox^>^ textboxes = { textBox1, textBox2, textBox3, textBox4, textBox5, textBox6, textBox7, textBox8, textBox9, textBox18, textBox17, textBox16, textBox15, textBox14, textBox13, textBox12, textBox11, textBox10 };
			   int startXNadawca = 27, startXOdbiorca = 310, startY = 60, stepY = 35;
			   for (int i = 0; i < 18; ++i) {
				   TextBox^ tb = textboxes[i < 9 ? i : 26 - i];
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

			   // Przycisk
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

			   // Animacja kodu kreskowego (początkowo niewidoczna)
			   this->labelTytulKodu->AutoSize = true;
			   this->labelTytulKodu->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			   this->labelTytulKodu->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			   this->labelTytulKodu->Location = System::Drawing::Point(36, 450);
			   this->labelTytulKodu->Text = L"Etykieta została wygenerowana:";
			   this->labelTytulKodu->Visible = false;

			   this->panelKodKreskowy->Controls->Add(this->labelNumerPaczki);
			   this->panelKodKreskowy->Location = System::Drawing::Point(40, 480);
			   this->panelKodKreskowy->Size = System::Drawing::Size(500, 150);
			   this->panelKodKreskowy->Visible = false;
			   this->panelKodKreskowy->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Formularz_paczki::panelKodKreskowy_Paint);

			   this->labelNumerPaczki->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->labelNumerPaczki->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold));
			   this->labelNumerPaczki->ForeColor = System::Drawing::Color::White;
			   this->labelNumerPaczki->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->labelNumerPaczki->Visible = false;

			   // Główny formularz
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
		   }
#pragma endregion

	private:
		// Ulepszona obsługa placeholderów
		void initializePlaceholders() {
			array<TextBox^>^ textboxes = { textBox1, textBox2, textBox3, textBox4, textBox5, textBox6, textBox7, textBox8, textBox9,
											textBox18, textBox17, textBox16, textBox15, textBox14, textBox13, textBox12, textBox11, textBox10 };
			array<String^>^ placeholders = { "Imię nadawcy", "Nazwisko nadawcy", "Telefon nadawcy", "Email nadawcy", "Ulica nadawcy", "Miasto nadawcy", "Województwo nadawcy", "Kod pocztowy nadawcy", "Kraj nadawcy",
											 "Imię odbiorcy", "Nazwisko odbiorcy", "Telefon odbiorcy", "Email odbiorcy", "Ulica odbiorcy", "Miasto odbiorcy", "Województwo odbiorcy", "Kod pocztowy odbiorcy", "Kraj odbiorcy" };

			for (int i = 0; i < textboxes->Length; ++i) {
				TextBox^ tb = textboxes[i];
				tb->Tag = placeholders[i]; // Używamy właściwości Tag do przechowywania tekstu placeholdera
				tb->Text = placeholders[i];
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

		// Rysowanie animacji kodu kreskowego
		System::Void panelKodKreskowy_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			// Sprawdzenie, czy numer paczki istnieje, aby uniknąć błędu
			if (String::IsNullOrEmpty(this->numerWygenerowanejPaczki)) {
				return;
			}

			Graphics^ g = e->Graphics;
			Random^ rand = gcnew Random(this->numerWygenerowanejPaczki->GetHashCode());
			int panelWidth = panelKodKreskowy->Width;
			int panelHeight = panelKodKreskowy->Height - 30; // Zostaw miejsce na numer
			g->Clear(this->BackColor);

			for (int x = 0; x < panelWidth; ) {
				int lineWidth = rand->Next(1, 5);
				if (x + lineWidth > panelWidth) lineWidth = panelWidth - x;
				g->FillRectangle(Brushes::White, x, 0, lineWidth, panelHeight);
				int spaceWidth = rand->Next(1, 5);
				x += lineWidth + spaceWidth;
			}
		}

		// Kliknięcie głównego przycisku
		System::Void buttonUtworz_Click(System::Object^ sender, System::EventArgs^ e) {
			if (textBox6->ForeColor == Color::Gray || textBox13->ForeColor == Color::Gray) {
				MessageBox::Show("Proszę wypełnić przynajmniej miasto nadawcy i odbiorcy.", "Błąd Walidacji", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			Nadawca nadawcaObj;
			nadawcaObj.imie = textBox1->ForeColor == Color::Gray ? "" : toStdString(textBox1->Text);
			nadawcaObj.nazwisko = textBox2->ForeColor == Color::Gray ? "" : toStdString(textBox2->Text);
			nadawcaObj.miasto = toStdString(textBox6->Text);
			// ... uzupełnij resztę pól nadawcy w razie potrzeby ...

			Odbiorca odbiorcaObj;
			odbiorcaObj.imie = textBox18->ForeColor == Color::Gray ? "" : toStdString(textBox18->Text);
			odbiorcaObj.nazwisko = textBox17->ForeColor == Color::Gray ? "" : toStdString(textBox17->Text);
			odbiorcaObj.miasto = toStdString(textBox13->Text);
			// ... uzupełnij resztę pól odbiorcy w razie potrzeby ...

			Paczka paczka(nadawcaObj, odbiorcaObj);
			this->numerWygenerowanejPaczki = msclr::interop::marshal_as<String^>(paczka.getNumerPaczki());

			// Logika zapisu do pliku JSON
			nlohmann::json new_package_json;
			new_package_json["numerPaczki"] = paczka.getNumerPaczki();
			new_package_json["nadawca"] = { {"imie", paczka.getNadawca().imie}, {"nazwisko", paczka.getNadawca().nazwisko}, {"adres", {{"miasto", paczka.getNadawca().miasto}}} };
			new_package_json["odbiorca"] = { {"imie", paczka.getOdbiorca().imie}, {"nazwisko", paczka.getOdbiorca().nazwisko}, {"adres", {{"miasto", paczka.getOdbiorca().miasto}}} };

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

				MessageBox::Show("Paczka została pomyślnie zarejestrowana!\nNumer: " + this->numerWygenerowanejPaczki, "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
				SystemSounds::Asterisk->Play();

				// Pokaż animację i zmień przycisk na "Zamknij"
				this->labelTytulKodu->Visible = true;
				this->panelKodKreskowy->Visible = true;
				this->labelNumerPaczki->Text = this->numerWygenerowanejPaczki;
				this->labelNumerPaczki->Visible = true;
				this->panelKodKreskowy->Refresh(); // Wymuś odrysowanie panelu

				this->buttonUtworz->Text = "Zamknij";
				this->buttonUtworz->Click -= gcnew System::EventHandler(this, &Formularz_paczki::buttonUtworz_Click);
				this->buttonUtworz->Click += gcnew System::EventHandler(this, &Formularz_paczki::buttonZamknij_Click);
			}
			else {
				MessageBox::Show("Błąd: Nie można zapisać pliku paczka_data.json", "Błąd Zapisu", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			paczka.paczkaPrzyjeta();
		}

		System::Void buttonZamknij_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}