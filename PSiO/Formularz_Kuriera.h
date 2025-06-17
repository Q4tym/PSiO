#pragma once

#include "Klasy.h"
#include "EtykietaForm.h"
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <msclr/marshal_cppstd.h>

#using <System.Windows.Forms.DataVisualization.dll>

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	inline bool compareMapPairValues(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second > b.second;
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
		ListView^ listViewPaczki;
		Button^ buttonSortujMiasto;
		Button^ buttonSortujKod;
		Button^ buttonSortujAdres;
		Button^ buttonOdswiez;
		Button^ buttonPodgladEtykiety;
		Label^ labelInfo;
		GroupBox^ groupBoxStatystyki;
		Label^ labelStatLiczbaPaczek;
		Label^ labelStatMiasto;
		Label^ labelLiczbaPaczekVal;
		Label^ labelMiastoVal;
		ImageList^ imageListPaczki;
		Chart^ chartStatystyki;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->buttonSortujAdres = (gcnew System::Windows::Forms::Button());
			this->listViewPaczki = (gcnew System::Windows::Forms::ListView());
			this->buttonSortujMiasto = (gcnew System::Windows::Forms::Button());
			this->buttonSortujKod = (gcnew System::Windows::Forms::Button());
			this->buttonOdswiez = (gcnew System::Windows::Forms::Button());
			this->buttonPodgladEtykiety = (gcnew System::Windows::Forms::Button());
			this->labelInfo = (gcnew System::Windows::Forms::Label());
			this->groupBoxStatystyki = (gcnew System::Windows::Forms::GroupBox());
			this->labelMiastoVal = (gcnew System::Windows::Forms::Label());
			this->labelLiczbaPaczekVal = (gcnew System::Windows::Forms::Label());
			this->labelStatMiasto = (gcnew System::Windows::Forms::Label());
			this->labelStatLiczbaPaczek = (gcnew System::Windows::Forms::Label());
			this->imageListPaczki = (gcnew System::Windows::Forms::ImageList(this->components));
			this->chartStatystyki = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBoxStatystyki->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStatystyki))->BeginInit();
			this->SuspendLayout();
			// 
			// imageListPaczki
			// 
			this->imageListPaczki->ColorDepth = System::Windows::Forms::ColorDepth::Depth32Bit;
			this->imageListPaczki->ImageSize = System::Drawing::Size(16, 16);
			this->imageListPaczki->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// listViewPaczki
			// 
			this->listViewPaczki->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->listViewPaczki->BackColor = System::Drawing::Color::FromArgb(45, 45, 48);
			this->listViewPaczki->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listViewPaczki->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->listViewPaczki->ForeColor = System::Drawing::Color::White;
			this->listViewPaczki->FullRowSelect = true;
			this->listViewPaczki->GridLines = true;
			this->listViewPaczki->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listViewPaczki->Location = System::Drawing::Point(12, 50);
			this->listViewPaczki->Name = L"listViewPaczki";
			this->listViewPaczki->Size = System::Drawing::Size(580, 320);
			this->listViewPaczki->SmallImageList = this->imageListPaczki;
			this->listViewPaczki->UseCompatibleStateImageBehavior = false;
			this->listViewPaczki->View = System::Windows::Forms::View::Details;
			this->listViewPaczki->Columns->Add("Rozm.", 40);
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
			this->buttonOdswiez->Size = System::Drawing::Size(100, 32);
			this->buttonOdswiez->Text = L"Odśwież";
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
			this->buttonSortujMiasto->Location = System::Drawing::Point(118, 12);
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
			this->buttonSortujKod->Location = System::Drawing::Point(254, 12);
			this->buttonSortujKod->Name = L"buttonSortujKod";
			this->buttonSortujKod->Size = System::Drawing::Size(140, 32);
			this->buttonSortujKod->Text = L"Sortuj wg Kodu";
			this->buttonSortujKod->UseVisualStyleBackColor = false;
			this->buttonSortujKod->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonSortujKod_Click);
			//
			// buttonSortujAdres
			//
			this->buttonSortujAdres->BackColor = System::Drawing::Color::FromArgb(40, 167, 69);
			this->buttonSortujAdres->FlatAppearance->BorderSize = 0;
			this->buttonSortujAdres->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSortujAdres->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->buttonSortujAdres->ForeColor = System::Drawing::Color::White;
			this->buttonSortujAdres->Location = System::Drawing::Point(400, 12);
			this->buttonSortujAdres->Name = L"buttonSortujAdres";
			this->buttonSortujAdres->Size = System::Drawing::Size(192, 32);
			this->buttonSortujAdres->Text = L"Sortowanie Zaawansowane";
			this->buttonSortujAdres->UseVisualStyleBackColor = false;
			this->buttonSortujAdres->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonSortujAdres_Click);
			// 
			// buttonPodgladEtykiety
			// 
			this->buttonPodgladEtykiety->BackColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->buttonPodgladEtykiety->FlatAppearance->BorderSize = 0;
			this->buttonPodgladEtykiety->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPodgladEtykiety->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->buttonPodgladEtykiety->ForeColor = System::Drawing::Color::White;
			this->buttonPodgladEtykiety->Location = System::Drawing::Point(12, 380);
			this->buttonPodgladEtykiety->Name = L"buttonPodgladEtykiety";
			this->buttonPodgladEtykiety->Size = System::Drawing::Size(580, 32);
			this->buttonPodgladEtykiety->Text = L"Podgląd etykiety";
			this->buttonPodgladEtykiety->UseVisualStyleBackColor = false;
			this->buttonPodgladEtykiety->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonPodgladEtykiety_Click);
			// 
			// labelInfo
			// 
			this->labelInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelInfo->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelInfo->Location = System::Drawing::Point(608, 20);
			this->labelInfo->Name = L"labelInfo";
			this->labelInfo->Size = System::Drawing::Size(264, 17);
			this->labelInfo->Text = L"Panel kuriera";
			this->labelInfo->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// groupBoxStatystyki
			// 
			this->groupBoxStatystyki->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxStatystyki->Controls->Add(this->labelMiastoVal);
			this->groupBoxStatystyki->Controls->Add(this->labelLiczbaPaczekVal);
			this->groupBoxStatystyki->Controls->Add(this->labelStatMiasto);
			this->groupBoxStatystyki->Controls->Add(this->labelStatLiczbaPaczek);
			this->groupBoxStatystyki->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->groupBoxStatystyki->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->groupBoxStatystyki->Location = System::Drawing::Point(12, 416);
			this->groupBoxStatystyki->Name = L"groupBoxStatystyki";
			this->groupBoxStatystyki->Size = System::Drawing::Size(860, 73);
			this->groupBoxStatystyki->TabIndex = 4;
			this->groupBoxStatystyki->TabStop = false;
			this->groupBoxStatystyki->Text = L"Podstawowe Statystyki";
			// 
			// labelMiastoVal
			// 
			this->labelMiastoVal->AutoSize = true;
			this->labelMiastoVal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->labelMiastoVal->ForeColor = System::Drawing::Color::White;
			this->labelMiastoVal->Location = System::Drawing::Point(549, 30);
			this->labelMiastoVal->Name = L"labelMiastoVal";
			this->labelMiastoVal->Size = System::Drawing::Size(36, 17);
			this->labelMiastoVal->TabIndex = 3;
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
			this->labelLiczbaPaczekVal->TabIndex = 2;
			this->labelLiczbaPaczekVal->Text = L"0";
			// 
			// labelStatMiasto
			// 
			this->labelStatMiasto->AutoSize = true;
			this->labelStatMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelStatMiasto->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelStatMiasto->Location = System::Drawing::Point(350, 30);
			this->labelStatMiasto->Name = L"labelStatMiasto";
			this->labelStatMiasto->Size = System::Drawing::Size(193, 17);
			this->labelStatMiasto->TabIndex = 1;
			this->labelStatMiasto->Text = L"Miasto z największą l. paczek:";
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
			// chartStatystyki
			// 
			this->chartStatystyki->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->chartStatystyki->BackColor = System::Drawing::Color::FromArgb(45, 45, 48);
			this->chartStatystyki->BorderlineColor = System::Drawing::Color::Gray;
			this->chartStatystyki->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			chartArea1->Name = L"ChartArea1";
			chartArea1->BackColor = System::Drawing::Color::FromArgb(45, 45, 48);
			chartArea1->AxisX->LabelStyle->ForeColor = System::Drawing::Color::White;
			chartArea1->AxisY->LabelStyle->ForeColor = System::Drawing::Color::White;
			chartArea1->AxisX->LineColor = System::Drawing::Color::Gray;
			chartArea1->AxisY->LineColor = System::Drawing::Color::Gray;
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::FromArgb(60, 60, 60);
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::FromArgb(60, 60, 60);
			this->chartStatystyki->ChartAreas->Add(chartArea1);
			Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			legend1->Name = L"Legend1";
			legend1->BackColor = System::Drawing::Color::FromArgb(45, 45, 48);
			legend1->ForeColor = System::Drawing::Color::White;
			this->chartStatystyki->Legends->Add(legend1);
			this->chartStatystyki->Location = System::Drawing::Point(608, 50);
			this->chartStatystyki->Name = L"chartStatystyki";
			Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			series1->Name = L"Miasta";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Color = System::Drawing::Color::FromArgb(0, 122, 204);
			this->chartStatystyki->Series->Add(series1);
			this->chartStatystyki->Size = System::Drawing::Size(264, 320);
			this->chartStatystyki->TabIndex = 5;
			Title^ title1 = gcnew Title("TOP 5 Miast docelowych", Docking::Top, gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold), Color::White);
			this->chartStatystyki->Titles->Add(title1);
			// 
			// Formularz_Kuriera
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->ClientSize = System::Drawing::Size(884, 511);
			this->Controls->Add(this->buttonPodgladEtykiety);
			this->Controls->Add(this->chartStatystyki);
			this->Controls->Add(this->groupBoxStatystyki);
			this->Controls->Add(this->labelInfo);
			this->Controls->Add(this->buttonOdswiez);
			this->Controls->Add(this->buttonSortujKod);
			this->Controls->Add(this->buttonSortujMiasto);
			this->Controls->Add(this->buttonSortujAdres);
			this->Controls->Add(this->listViewPaczki);
			this->MinimumSize = System::Drawing::Size(900, 550);
			this->Name = L"Formularz_Kuriera";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Panel Kuriera";
			this->groupBoxStatystyki->ResumeLayout(false);
			this->groupBoxStatystyki->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStatystyki))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		void utworzIkony() {
			Bitmap^ bmpMala = gcnew Bitmap(16, 16);
			Graphics^ g = Graphics::FromImage(bmpMala);
			g->FillRectangle(Brushes::LightBlue, 0, 0, 16, 16);
			g->DrawString("S", gcnew System::Drawing::Font("Arial", 8, FontStyle::Bold), Brushes::Black, 3, 2);
			imageListPaczki->Images->Add(bmpMala);
			delete g;

			Bitmap^ bmpSrednia = gcnew Bitmap(16, 16);
			g = Graphics::FromImage(bmpSrednia);
			g->FillRectangle(Brushes::LightGreen, 0, 0, 16, 16);
			g->DrawString("M", gcnew System::Drawing::Font("Arial", 8, FontStyle::Bold), Brushes::Black, 2, 2);
			imageListPaczki->Images->Add(bmpSrednia);
			delete g;

			Bitmap^ bmpDuza = gcnew Bitmap(16, 16);
			g = Graphics::FromImage(bmpDuza);
			g->FillRectangle(Brushes::LightCoral, 0, 0, 16, 16);
			g->DrawString("L", gcnew System::Drawing::Font("Arial", 8, FontStyle::Bold), Brushes::Black, 3, 2);
			imageListPaczki->Images->Add(bmpDuza);
			delete g;
		}

		System::Void buttonSortujAdres_Click(System::Object^ sender, System::EventArgs^ e) {
			sortownia->sortujPaczki(Sortownia::KryteriumSortowania::WG_ADRESU_DORECZENIA);
			odswiezListePaczek(true);
		}
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
				if (imageListPaczki->Images->Count == 0) {
					utworzIkony();
				}

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

					ListViewItem^ item = gcnew ListViewItem(""); // Pusty tekst dla pierwszej kolumny z ikoną
					item->SubItems->Add(numerPaczki);
					item->SubItems->Add(miasto);
					item->SubItems->Add(kod);
					item->SubItems->Add(status);

					switch (paczka.getRozmiar()) {
					case Paczka::RozmiarPaczki::MALA: item->ImageIndex = 0; break;
					case Paczka::RozmiarPaczki::SREDNIA: item->ImageIndex = 1; break;
					case Paczka::RozmiarPaczki::DUZA: item->ImageIndex = 2; break;
					}
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

			chartStatystyki->Series["Miasta"]->Points->Clear();

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

			if (licznikiMiast.empty()) {
				labelMiastoVal->Text = "Brak";
				return;
			}

			auto maxElement = std::max_element(licznikiMiast.begin(), licznikiMiast.end(), compareMapPairValues);
			labelMiastoVal->Text = gcnew String(maxElement->first.c_str());

			std::vector<std::pair<std::string, int>> sortedCities(licznikiMiast.begin(), licznikiMiast.end());
			std::sort(sortedCities.begin(), sortedCities.end(), compareMapPairValues);

			int count = 0;
			for (const auto& pair : sortedCities) {
				if (count >= 5) break;
				String^ miasto = gcnew String(pair.first.c_str());
				chartStatystyki->Series["Miasta"]->Points->AddXY(miasto, pair.second);
				count++;
			}
		}

		System::Void buttonPodgladEtykiety_Click(System::Object^ sender, System::EventArgs^ e) {
			int idx = -1;
			if (listViewPaczki->SelectedItems->Count > 0)
				idx = listViewPaczki->SelectedItems[0]->Index;
			const auto& paczki = sortownia->getPaczki();
			if (idx < 0 || idx >= static_cast<int>(paczki.size())) {
				MessageBox::Show("Wybierz paczkę z listy!", "Brak wyboru", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			const Paczka& paczka = paczki[idx];
			PSiO::EtykietaForm^ etykieta = gcnew PSiO::EtykietaForm(paczka);
			etykieta->ShowDialog();
		}
	};
}
