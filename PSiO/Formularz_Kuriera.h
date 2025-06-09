#pragma once

#include "Klasy.h"
#include <map>
#include <string>
#include <algorithm>
#include <msclr/marshal_cppstd.h>

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//
	// --- POPRAWKA: Dodanie słowa kluczowego 'inline' ---
	// Słowo 'inline' rozwiązuje błąd wielokrotnej definicji symbolu (LNK2005),
	// informując linker, że ma scalić wszystkie kopie tej funkcji w jedną.
	//
	inline bool compareMapPairValues(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second < b.second;
	}


	public ref class Formularz_Kuriera : public System::Windows::Forms::Form
	{
	public:
		Formularz_Kuriera(void)
		{
			InitializeComponent();
			sortownia = new Sortownia();
			odswiezListePaczek(false);
		}

	protected:
		~Formularz_Kuriera()
		{
			if (components)
			{
				delete components;
			}
			delete sortownia;
		}

	private:
		Sortownia* sortownia;
		System::Windows::Forms::ListView^ listViewPaczki;
		System::Windows::Forms::Button^ buttonSortujMiasto;
		System::Windows::Forms::Button^ buttonSortujKod;
		System::Windows::Forms::Button^ buttonOdswiez;
		System::Windows::Forms::Label^ labelInfo;
		System::Windows::Forms::GroupBox^ groupBoxStatystyki;
		System::Windows::Forms::Label^ labelStatLiczbaPaczek;
		System::Windows::Forms::Label^ labelStatMiasto;
		System::Windows::Forms::Label^ labelLiczbaPaczekVal;
		System::Windows::Forms::Label^ labelMiastoVal;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->listViewPaczki = (gcnew System::Windows::Forms::ListView());
			this->buttonSortujMiasto = (gcnew System::Windows::Forms::Button());
			this->buttonSortujKod = (gcnew System::Windows::Forms::Button());
			this->buttonOdswiez = (gcnew System::Windows::Forms::Button());
			this->labelInfo = (gcnew System::Windows::Forms::Label());
			this->groupBoxStatystyki = (gcnew System::Windows::Forms::GroupBox());
			this->labelMiastoVal = (gcnew System::Windows::Forms::Label());
			this->labelLiczbaPaczekVal = (gcnew System::Windows::Forms::Label());
			this->labelStatMiasto = (gcnew System::Windows::Forms::Label());
			this->labelStatLiczbaPaczek = (gcnew System::Windows::Forms::Label());
			this->groupBoxStatystyki->SuspendLayout();
			this->SuspendLayout();
			//
			// listViewPaczki
			//
			this->listViewPaczki->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listViewPaczki->BackColor = System::Drawing::Color::FromArgb(45, 45, 48);
			this->listViewPaczki->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listViewPaczki->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->listViewPaczki->ForeColor = System::Drawing::Color::White;
			this->listViewPaczki->FullRowSelect = true;
			this->listViewPaczki->GridLines = true;
			this->listViewPaczki->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listViewPaczki->Location = System::Drawing::Point(12, 50);
			this->listViewPaczki->Name = L"listViewPaczki";
			this->listViewPaczki->Size = System::Drawing::Size(760, 320);
			this->listViewPaczki->UseCompatibleStateImageBehavior = false;
			this->listViewPaczki->View = System::Windows::Forms::View::Details;
			this->listViewPaczki->Columns->Add("Numer Paczki", 150);
			this->listViewPaczki->Columns->Add("Miasto Odbiorcy", 150);
			this->listViewPaczki->Columns->Add("Kod Pocztowy", 120);
			this->listViewPaczki->Columns->Add("Status", 100);
			//
			// buttonOdswiez
			//
			this->buttonOdswiez->BackColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->buttonOdswiez->FlatAppearance->BorderSize = 0;
			this->buttonOdswiez->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonOdswiez->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->buttonOdswiez->ForeColor = System::Drawing::Color::White;
			this->buttonOdswiez->Location = System::Drawing::Point(12, 12);
			this->buttonOdswiez->Name = L"buttonOdswiez";
			this->buttonOdswiez->Size = System::Drawing::Size(130, 32);
			this->buttonOdswiez->Text = L"Odśwież Listę";
			this->buttonOdswiez->UseVisualStyleBackColor = false;
			this->buttonOdswiez->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonOdswiez_Click);
			//
			// buttonSortujMiasto
			//
			this->buttonSortujMiasto->BackColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->buttonSortujMiasto->FlatAppearance->BorderSize = 0;
			this->buttonSortujMiasto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSortujMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->buttonSortujMiasto->ForeColor = System::Drawing::Color::White;
			this->buttonSortujMiasto->Location = System::Drawing::Point(148, 12);
			this->buttonSortujMiasto->Name = L"buttonSortujMiasto";
			this->buttonSortujMiasto->Size = System::Drawing::Size(130, 32);
			this->buttonSortujMiasto->Text = L"Sortuj wg Miasta";
			this->buttonSortujMiasto->UseVisualStyleBackColor = false;
			this->buttonSortujMiasto->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonSortujMiasto_Click);
			//
			// buttonSortujKod
			//
			this->buttonSortujKod->BackColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->buttonSortujKod->FlatAppearance->BorderSize = 0;
			this->buttonSortujKod->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSortujKod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->buttonSortujKod->ForeColor = System::Drawing::Color::White;
			this->buttonSortujKod->Location = System::Drawing::Point(284, 12);
			this->buttonSortujKod->Name = L"buttonSortujKod";
			this->buttonSortujKod->Size = System::Drawing::Size(140, 32);
			this->buttonSortujKod->Text = L"Sortuj wg Kodu Pocz.";
			this->buttonSortujKod->UseVisualStyleBackColor = false;
			this->buttonSortujKod->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonSortujKod_Click);
			//
			// labelInfo
			//
			this->labelInfo->AutoSize = true;
			this->labelInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelInfo->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelInfo->Location = System::Drawing::Point(450, 20);
			this->labelInfo->Name = L"labelInfo";
			this->labelInfo->Text = L"Panel kuriera - lista paczek w systemie.";
			//
			// groupBoxStatystyki
			//
			this->groupBoxStatystyki->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxStatystyki->Controls->Add(this->labelMiastoVal);
			this->groupBoxStatystyki->Controls->Add(this->labelLiczbaPaczekVal);
			this->groupBoxStatystyki->Controls->Add(this->labelStatMiasto);
			this->groupBoxStatystyki->Controls->Add(this->labelStatLiczbaPaczek);
			this->groupBoxStatystyki->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->groupBoxStatystyki->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->groupBoxStatystyki->Location = System::Drawing::Point(12, 376);
			this->groupBoxStatystyki->Name = L"groupBoxStatystyki";
			this->groupBoxStatystyki->Size = System::Drawing::Size(760, 73);
			this->groupBoxStatystyki->TabStop = false;
			this->groupBoxStatystyki->Text = L"Panel Statystyk";
			//
			// labelMiastoVal
			//
			this->labelMiastoVal->AutoSize = true;
			this->labelMiastoVal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->labelMiastoVal->ForeColor = System::Drawing::Color::White;
			this->labelMiastoVal->Location = System::Drawing::Point(549, 30);
			this->labelMiastoVal->Name = L"labelMiastoVal";
			this->labelMiastoVal->Size = System::Drawing::Size(36, 17);
			this->labelMiastoVal->Text = L"Brak";
			//
			// labelLiczbaPaczekVal
			//
			this->labelLiczbaPaczekVal->AutoSize = true;
			this->labelLiczbaPaczekVal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->labelLiczbaPaczekVal->ForeColor = System::Drawing::Color::White;
			this->labelLiczbaPaczekVal->Location = System::Drawing::Point(177, 30);
			this->labelLiczbaPaczekVal->Name = L"labelLiczbaPaczekVal";
			this->labelLiczbaPaczekVal->Size = System::Drawing::Size(15, 17);
			this->labelLiczbaPaczekVal->Text = L"0";
			//
			// labelStatMiasto
			//
			this->labelStatMiasto->AutoSize = true;
			this->labelStatMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelStatMiasto->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelStatMiasto->Location = System::Drawing::Point(350, 30);
			this->labelStatMiasto->Name = L"labelStatMiasto";
			this->labelStatMiasto->Size = System::Drawing::Size(183, 17);
			this->labelStatMiasto->Text = L"Najpopularniejsze miasto celu:";
			//
			// labelStatLiczbaPaczek
			//
			this->labelStatLiczbaPaczek->AutoSize = true;
			this->labelStatLiczbaPaczek->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelStatLiczbaPaczek->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelStatLiczbaPaczek->Location = System::Drawing::Point(16, 30);
			this->labelStatLiczbaPaczek->Name = L"labelStatLiczbaPaczek";
			this->labelStatLiczbaPaczek->Size = System::Drawing::Size(147, 17);
			this->labelStatLiczbaPaczek->Text = L"Całkowita liczba paczek:";
			//
			// Formularz_Kuriera
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->ClientSize = System::Drawing::Size(784, 461);
			this->Controls->Add(this->groupBoxStatystyki);
			this->Controls->Add(this->labelInfo);
			this->Controls->Add(this->buttonOdswiez);
			this->Controls->Add(this->buttonSortujKod);
			this->Controls->Add(this->buttonSortujMiasto);
			this->Controls->Add(this->listViewPaczki);
			this->MinimumSize = System::Drawing::Size(800, 500);
			this->Name = L"Formularz_Kuriera";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Panel Kuriera";
			this->groupBoxStatystyki->ResumeLayout(false);
			this->groupBoxStatystyki->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void buttonOdswiez_Click(System::Object^ sender, System::EventArgs^ e) {
			odswiezListePaczek(false);
		}

		System::Void buttonSortujMiasto_Click(System::Object^ sender, System::EventArgs^ e) {
			sortownia->sortujPaczki(Sortownia::KryteriumSortowania::WG_MIASTA);
			odswiezListePaczek(true);
		}

		System::Void buttonSortujKod_Click(System::Object^ sender, System::EventArgs^ e) {
			sortownia->sortujPaczki(Sortownia::KryteriumSortowania::WG_KODU_POCZTOWEGO);
			odswiezListePaczek(true);
		}

		void odswiezListePaczek(bool posortowane) {
			try {
				listViewPaczki->Items->Clear();
				if (!posortowane) {
					sortownia->wczytajPaczkiZPliku("paczka_data.json");
				}
				const auto& paczki = sortownia->getPaczki();
				for (const auto& paczka : paczki) {
					String^ numerPaczki = msclr::interop::marshal_as<String^>(paczka.getNumerPaczki());
					String^ miasto = msclr::interop::marshal_as<String^>(paczka.getOdbiorca().miasto);
					String^ kod = msclr::interop::marshal_as<String^>(paczka.getOdbiorca().kodPocztowy);
					String^ status = "W sortowni";
					ListViewItem^ item = gcnew ListViewItem(numerPaczki);
					item->SubItems->Add(miasto);
					item->SubItems->Add(kod);
					item->SubItems->Add(status);
					listViewPaczki->Items->Add(item);
				}
				this->labelInfo->Text = String::Format("Wczytano {0} paczek.", paczki.size());
				aktualizujStatystyki();
			}
			catch (const std::exception& e) {
				System::String^ errorMessage = msclr::interop::marshal_as<System::String^>(e.what());
				MessageBox::Show("Wystąpił błąd podczas wczytywania paczek: " + errorMessage, "Błąd Pliku", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void aktualizujStatystyki() {
			const auto& paczki = sortownia->getPaczki();
			labelLiczbaPaczekVal->Text = paczki.size().ToString();

			if (paczki.empty()) {
				labelMiastoVal->Text = "Brak";
				return;
			}
			std::map<std::string, int> licznikiMiast;
			for (const auto& paczka : paczki) {
				if (!paczka.getOdbiorca().miasto.empty()) {
					licznikiMiast[paczka.getOdbiorca().miasto]++;
				}
			}

			auto maxElement = std::max_element(
				licznikiMiast.begin(), licznikiMiast.end(),
				compareMapPairValues);

			if (maxElement != licznikiMiast.end()) {
				labelMiastoVal->Text = gcnew String(maxElement->first.c_str());
			}
			else {
				labelMiastoVal->Text = "Brak";
			}
		}
	};
}