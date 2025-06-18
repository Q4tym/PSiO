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
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	inline bool compareMapPairValues(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second > b.second;
	}

	public ref class Formularz_Kuriera : public System::Windows::Forms::Form
	{
	public:
		Formularz_Kuriera(void) {
			InitializeComponent();
			sortownia = new Sortownia();
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Formularz_Kuriera::Formularz_Kuriera_FormClosing);
		}
	protected:
		~Formularz_Kuriera() {
			if (components) { delete components; }
			delete sortownia;
		}

	private:
		Sortownia* sortownia;
		System::Windows::Forms::ListView^ listViewPaczki;
		System::Windows::Forms::Button^ buttonSortujMiasto, ^ buttonSortujKod, ^ buttonSortujAdres, ^ buttonOdswiez, ^ buttonGenerujEtykiete;
		System::Windows::Forms::Label^ labelInfo, ^ labelStatLiczbaPaczek, ^ labelStatMiasto, ^ labelLiczbaPaczekVal, ^ labelMiastoVal, ^ labelSzukaj;
		System::Windows::Forms::GroupBox^ groupBoxStatystyki;
		System::Windows::Forms::ImageList^ imageListPaczki;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartStatystyki;
		System::Windows::Forms::TextBox^ textSzukaj;
		System::Windows::Forms::ContextMenuStrip^ contextMenuPaczka;
		System::Windows::Forms::ToolStripMenuItem^ statusWDoreczeniu, ^ statusDostarczono, ^ statusWSortowni;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->buttonSortujAdres = (gcnew System::Windows::Forms::Button());
			this->listViewPaczki = (gcnew System::Windows::Forms::ListView());
			this->imageListPaczki = (gcnew System::Windows::Forms::ImageList(this->components));
			this->contextMenuPaczka = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->statusWSortowni = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusWDoreczeniu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusDostarczono = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonSortujMiasto = (gcnew System::Windows::Forms::Button());
			this->buttonSortujKod = (gcnew System::Windows::Forms::Button());
			this->buttonOdswiez = (gcnew System::Windows::Forms::Button());
			this->buttonGenerujEtykiete = (gcnew System::Windows::Forms::Button());
			this->labelInfo = (gcnew System::Windows::Forms::Label());
			this->groupBoxStatystyki = (gcnew System::Windows::Forms::GroupBox());
			this->labelMiastoVal = (gcnew System::Windows::Forms::Label());
			this->labelLiczbaPaczekVal = (gcnew System::Windows::Forms::Label());
			this->labelStatMiasto = (gcnew System::Windows::Forms::Label());
			this->labelStatLiczbaPaczek = (gcnew System::Windows::Forms::Label());
			this->chartStatystyki = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->labelSzukaj = (gcnew System::Windows::Forms::Label());
			this->contextMenuPaczka->SuspendLayout();
			this->groupBoxStatystyki->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStatystyki))->BeginInit();
			this->SuspendLayout();

			this->buttonSortujAdres->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(167)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->buttonSortujAdres->FlatAppearance->BorderSize = 0;
			this->buttonSortujAdres->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSortujAdres->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->buttonSortujAdres->ForeColor = System::Drawing::Color::White;
			this->buttonSortujAdres->Location = System::Drawing::Point(400, 12);
			this->buttonSortujAdres->Name = L"buttonSortujAdres";
			this->buttonSortujAdres->Size = System::Drawing::Size(192, 32);
			this->buttonSortujAdres->TabIndex = 4;
			this->buttonSortujAdres->Text = L"Sortowanie Zaawansowane";
			this->buttonSortujAdres->UseVisualStyleBackColor = false;
			this->buttonSortujAdres->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonSortujAdres_Click);

			this->listViewPaczki->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->listViewPaczki->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->listViewPaczki->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listViewPaczki->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->listViewPaczki->ForeColor = System::Drawing::Color::White;
			this->listViewPaczki->FullRowSelect = true;
			this->listViewPaczki->GridLines = true;
			this->listViewPaczki->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listViewPaczki->Location = System::Drawing::Point(12, 50);
			this->listViewPaczki->Name = L"listViewPaczki";
			this->listViewPaczki->Size = System::Drawing::Size(580, 315);
			this->listViewPaczki->SmallImageList = this->imageListPaczki;
			this->listViewPaczki->TabIndex = 0;
			this->listViewPaczki->UseCompatibleStateImageBehavior = false;
			this->listViewPaczki->View = System::Windows::Forms::View::Details;
			this->listViewPaczki->ContextMenuStrip = this->contextMenuPaczka;

			this->imageListPaczki->ColorDepth = System::Windows::Forms::ColorDepth::Depth32Bit;
			this->imageListPaczki->ImageSize = System::Drawing::Size(16, 16);
			this->imageListPaczki->TransparentColor = System::Drawing::Color::Transparent;

			this->contextMenuPaczka->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) { this->statusWSortowni, this->statusWDoreczeniu, this->statusDostarczono });
			this->contextMenuPaczka->Name = L"contextMenuPaczka";
			this->contextMenuPaczka->Size = System::Drawing::Size(225, 70);

			this->statusWSortowni->Name = L"statusWSortowni";
			this->statusWSortowni->Size = System::Drawing::Size(224, 22);
			this->statusWSortowni->Text = L"Zmień status na \'W sortowni\'";
			this->statusWSortowni->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::statusWSortowni_Click);

			this->statusWDoreczeniu->Name = L"statusWDoreczeniu";
			this->statusWDoreczeniu->Size = System::Drawing::Size(224, 22);
			this->statusWDoreczeniu->Text = L"Zmień status na \'W doręczeniu\'";
			this->statusWDoreczeniu->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::statusWDoreczeniu_Click);

			this->statusDostarczono->Name = L"statusDostarczono";
			this->statusDostarczono->Size = System::Drawing::Size(224, 22);
			this->statusDostarczono->Text = L"Zmień status na \'Dostarczono\'";
			this->statusDostarczono->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::statusDostarczono_Click);

			this->buttonSortujMiasto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->buttonSortujMiasto->FlatAppearance->BorderColor = System::Drawing::Color::Gray;
			this->buttonSortujMiasto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSortujMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->buttonSortujMiasto->ForeColor = System::Drawing::Color::White;
			this->buttonSortujMiasto->Location = System::Drawing::Point(118, 12);
			this->buttonSortujMiasto->Name = L"buttonSortujMiasto";
			this->buttonSortujMiasto->Size = System::Drawing::Size(130, 32);
			this->buttonSortujMiasto->TabIndex = 2;
			this->buttonSortujMiasto->Text = L"Sortuj wg Miasta";
			this->buttonSortujMiasto->UseVisualStyleBackColor = false;
			this->buttonSortujMiasto->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonSortujMiasto_Click);

			this->buttonSortujKod->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->buttonSortujKod->FlatAppearance->BorderColor = System::Drawing::Color::Gray;
			this->buttonSortujKod->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSortujKod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->buttonSortujKod->ForeColor = System::Drawing::Color::White;
			this->buttonSortujKod->Location = System::Drawing::Point(254, 12);
			this->buttonSortujKod->Name = L"buttonSortujKod";
			this->buttonSortujKod->Size = System::Drawing::Size(140, 32);
			this->buttonSortujKod->TabIndex = 3;
			this->buttonSortujKod->Text = L"Sortuj wg Kodu";
			this->buttonSortujKod->UseVisualStyleBackColor = false;
			this->buttonSortujKod->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonSortujKod_Click);

			this->buttonOdswiez->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->buttonOdswiez->FlatAppearance->BorderSize = 0;
			this->buttonOdswiez->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonOdswiez->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->buttonOdswiez->ForeColor = System::Drawing::Color::White;
			this->buttonOdswiez->Location = System::Drawing::Point(12, 12);
			this->buttonOdswiez->Name = L"buttonOdswiez";
			this->buttonOdswiez->Size = System::Drawing::Size(100, 32);
			this->buttonOdswiez->TabIndex = 1;
			this->buttonOdswiez->Text = L"Odśwież";
			this->buttonOdswiez->UseVisualStyleBackColor = false;
			this->buttonOdswiez->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonOdswiez_Click);

			this->buttonGenerujEtykiete->BackColor = System::Drawing::Color::FromArgb(210, 210, 210);
			this->buttonGenerujEtykiete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonGenerujEtykiete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->buttonGenerujEtykiete->ForeColor = System::Drawing::Color::Black;
			this->buttonGenerujEtykiete->Location = System::Drawing::Point(600, 12);
			this->buttonGenerujEtykiete->Name = L"buttonGenerujEtykiete";
			this->buttonGenerujEtykiete->Size = System::Drawing::Size(140, 32);
			this->buttonGenerujEtykiete->Text = L"Generuj etykietę";
			this->buttonGenerujEtykiete->UseVisualStyleBackColor = false;
			this->buttonGenerujEtykiete->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::buttonGenerujEtykiete_Click);

			this->labelInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelInfo->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelInfo->Location = System::Drawing::Point(608, 20);
			this->labelInfo->Name = L"labelInfo";
			this->labelInfo->Size = System::Drawing::Size(264, 17);
			this->labelInfo->TabIndex = 4;
			this->labelInfo->Text = L"Panel kuriera";
			this->labelInfo->TextAlign = System::Drawing::ContentAlignment::MiddleRight;

			this->groupBoxStatystyki->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxStatystyki->Controls->Add(this->labelMiastoVal);
			this->groupBoxStatystyki->Controls->Add(this->labelLiczbaPaczekVal);
			this->groupBoxStatystyki->Controls->Add(this->labelStatMiasto);
			this->groupBoxStatystyki->Controls->Add(this->labelStatLiczbaPaczek);
			this->groupBoxStatystyki->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->groupBoxStatystyki->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->groupBoxStatystyki->Location = System::Drawing::Point(12, 423);
			this->groupBoxStatystyki->Name = L"groupBoxStatystyki";
			this->groupBoxStatystyki->Size = System::Drawing::Size(860, 66);
			this->groupBoxStatystyki->TabIndex = 7;
			this->groupBoxStatystyki->TabStop = false;
			this->groupBoxStatystyki->Text = L"Podstawowe Statystyki";

			this->labelMiastoVal->AutoSize = true;
			this->labelMiastoVal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->labelMiastoVal->ForeColor = System::Drawing::Color::White;
			this->labelMiastoVal->Location = System::Drawing::Point(549, 30);
			this->labelMiastoVal->Name = L"labelMiastoVal";
			this->labelMiastoVal->Size = System::Drawing::Size(36, 17);
			this->labelMiastoVal->TabIndex = 3;
			this->labelMiastoVal->Text = L"Brak";

			this->labelLiczbaPaczekVal->AutoSize = true;
			this->labelLiczbaPaczekVal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->labelLiczbaPaczekVal->ForeColor = System::Drawing::Color::White;
			this->labelLiczbaPaczekVal->Location = System::Drawing::Point(177, 30);
			this->labelLiczbaPaczekVal->Name = L"labelLiczbaPaczekVal";
			this->labelLiczbaPaczekVal->Size = System::Drawing::Size(15, 17);
			this->labelLiczbaPaczekVal->TabIndex = 2;
			this->labelLiczbaPaczekVal->Text = L"0";

			this->labelStatMiasto->AutoSize = true;
			this->labelStatMiasto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelStatMiasto->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelStatMiasto->Location = System::Drawing::Point(350, 30);
			this->labelStatMiasto->Name = L"labelStatMiasto";
			this->labelStatMiasto->Size = System::Drawing::Size(193, 17);
			this->labelStatMiasto->TabIndex = 1;
			this->labelStatMiasto->Text = L"Miasto z największą l. paczek:";

			this->labelStatLiczbaPaczek->AutoSize = true;
			this->labelStatLiczbaPaczek->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelStatLiczbaPaczek->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelStatLiczbaPaczek->Location = System::Drawing::Point(16, 30);
			this->labelStatLiczbaPaczek->Name = L"labelStatLiczbaPaczek";
			this->labelStatLiczbaPaczek->Size = System::Drawing::Size(147, 17);
			this->labelStatLiczbaPaczek->TabIndex = 0;
			this->labelStatLiczbaPaczek->Text = L"Całkowita liczba paczek:";

			this->chartStatystyki->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->chartStatystyki->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->chartStatystyki->BorderlineColor = System::Drawing::Color::Gray;
			this->chartStatystyki->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->AxisX->LabelStyle->ForeColor = System::Drawing::Color::White;
			chartArea1->AxisX->LineColor = System::Drawing::Color::Gray;
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			chartArea1->AxisY->LabelStyle->ForeColor = System::Drawing::Color::White;
			chartArea1->AxisY->LineColor = System::Drawing::Color::Gray;
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			chartArea1->Name = L"ChartArea1";
			this->chartStatystyki->ChartAreas->Add(chartArea1);
			legend1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			legend1->Enabled = false;
			legend1->ForeColor = System::Drawing::Color::White;
			legend1->Name = L"Legend1";
			this->chartStatystyki->Legends->Add(legend1);
			this->chartStatystyki->Location = System::Drawing::Point(608, 50);
			this->chartStatystyki->Name = L"chartStatystyki";
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			series1->Legend = L"Legend1";
			series1->Name = L"Miasta";
			this->chartStatystyki->Series->Add(series1);
			this->chartStatystyki->Size = System::Drawing::Size(264, 367);
			this->chartStatystyki->TabIndex = 5;
			title1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			title1->ForeColor = System::Drawing::Color::White;
			title1->Name = L"Title1";
			title1->Text = L"TOP 5 Miast docelowych";
			this->chartStatystyki->Titles->Add(title1);

			this->textSzukaj->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textSzukaj->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->textSzukaj->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textSzukaj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->textSzukaj->ForeColor = System::Drawing::Color::White;
			this->textSzukaj->Location = System::Drawing::Point(12, 392);
			this->textSzukaj->Name = L"textSzukaj";
			this->textSzukaj->Size = System::Drawing::Size(580, 25);
			this->textSzukaj->TabIndex = 6;
			this->textSzukaj->TextChanged += gcnew System::EventHandler(this, &Formularz_Kuriera::textSzukaj_TextChanged);

			this->labelSzukaj->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->labelSzukaj->AutoSize = true;
			this->labelSzukaj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelSzukaj->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelSzukaj->Location = System::Drawing::Point(9, 372);
			this->labelSzukaj->Name = L"labelSzukaj";
			this->labelSzukaj->Size = System::Drawing::Size(180, 17);
			this->labelSzukaj->TabIndex = 8;
			this->labelSzukaj->Text = L"🔎 Wyszukaj (Nr, Miasto, Kod):";

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(884, 501);
			this->Controls->Add(this->buttonGenerujEtykiete);
			this->Controls->Add(this->labelSzukaj);
			this->Controls->Add(this->textSzukaj);
			this->Controls->Add(this->chartStatystyki);
			this->Controls->Add(this->groupBoxStatystyki);
			this->Controls->Add(this->labelInfo);
			this->Controls->Add(this->buttonOdswiez);
			this->Controls->Add(this->buttonSortujKod);
			this->Controls->Add(this->buttonSortujMiasto);
			this->Controls->Add(this->buttonSortujAdres);
			this->Controls->Add(this->listViewPaczki);
			this->MinimumSize = System::Drawing::Size(900, 540);
			this->Name = L"Formularz_Kuriera";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Panel Kuriera";
			this->Load += gcnew System::EventHandler(this, &Formularz_Kuriera::Formularz_Kuriera_Load);
			this->contextMenuPaczka->ResumeLayout(false);
			this->groupBoxStatystyki->ResumeLayout(false);
			this->groupBoxStatystyki->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStatystyki))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void Formularz_Kuriera_Load(System::Object^ sender, System::EventArgs^ e) {
			utworzIkony();
			listViewPaczki->Columns->Add("Rozm.", 50);
			listViewPaczki->Columns->Add("Numer Paczki", 140);
			listViewPaczki->Columns->Add("Miasto Odbiorcy", 120);
			listViewPaczki->Columns->Add("Kod Pocztowy", 90);
			listViewPaczki->Columns->Add("Status", 110);
			odswiezListePaczek();
		}

		System::Void textSzukaj_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			wypelnijListePaczek(true);
		}

		System::Void statusWSortowni_Click(System::Object^ sender, System::EventArgs^ e) { zmienStatusPaczki(Paczka::StatusPaczki::W_SORTOWNI); }
		System::Void statusWDoreczeniu_Click(System::Object^ sender, System::EventArgs^ e) { zmienStatusPaczki(Paczka::StatusPaczki::W_DORECZENIU); }
		System::Void statusDostarczono_Click(System::Object^ sender, System::EventArgs^ e) { zmienStatusPaczki(Paczka::StatusPaczki::DOSTARCZONO); }

		void zmienStatusPaczki(Paczka::StatusPaczki nowyStatus) {
			if (listViewPaczki->SelectedItems->Count > 0) {
				ListViewItem^ selectedItem = listViewPaczki->SelectedItems[0];
				String^ numerPaczki = selectedItem->SubItems[1]->Text;
				std::string stdNumerPaczki = msclr::interop::marshal_as<std::string>(numerPaczki);

				auto& paczki = sortownia->getPaczki();
				for (auto it = paczki.begin(); it != paczki.end(); ++it) {
					if (it->getNumerPaczki() == stdNumerPaczki) {
						it->setStatus(nowyStatus);
						sortownia->zapiszPaczkiDoPliku("paczka_data.json");
						int scrollPosition = listViewPaczki->TopItem ? listViewPaczki->TopItem->Index : 0;
						wypelnijListePaczek(true);
						if (scrollPosition < listViewPaczki->Items->Count) {
							listViewPaczki->TopItem = listViewPaczki->Items[scrollPosition];
						}
						break;
					}
				}
			}
		}

		System::Void buttonOdswiez_Click(System::Object^ sender, System::EventArgs^ e) { odswiezListePaczek(); }
		System::Void buttonSortujMiasto_Click(System::Object^ sender, System::EventArgs^ e) { sortownia->sortujPaczki(Sortownia::KryteriumSortowania::WG_MIASTA); wypelnijListePaczek(true); }
		System::Void buttonSortujKod_Click(System::Object^ sender, System::EventArgs^ e) { sortownia->sortujPaczki(Sortownia::KryteriumSortowania::WG_KODU_POCZTOWEGO); wypelnijListePaczek(true); }
		System::Void buttonSortujAdres_Click(System::Object^ sender, System::EventArgs^ e) { sortownia->sortujPaczki(Sortownia::KryteriumSortowania::WG_ADRESU_DORECZENIA); wypelnijListePaczek(true); }

		System::Void buttonGenerujEtykiete_Click(System::Object^ sender, System::EventArgs^ e) {
			if (listViewPaczki->SelectedItems->Count == 0) {
				MessageBox::Show("Wybierz paczkę z listy.", "Brak wyboru", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			String^ numerPaczki = listViewPaczki->SelectedItems[0]->SubItems[1]->Text;
			std::string stdNumerPaczki = msclr::interop::marshal_as<std::string>(numerPaczki);
			for (const auto& paczka : sortownia->getPaczki()) {
				if (paczka.getNumerPaczki() == stdNumerPaczki) {
					PSiO::EtykietaForm^ etykieta = gcnew PSiO::EtykietaForm(paczka);
					etykieta->ShowDialog();
					break;
				}
			}
		}

		System::Void Formularz_Kuriera_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		}

		void odswiezListePaczek() {
			try {
				textSzukaj->Clear();
				sortownia->wczytajPaczkiZPliku("paczka_data.json");
				wypelnijListePaczek(false);
			}
			catch (const std::exception& e) {
				System::String^ errorMessage = msclr::interop::marshal_as<System::String^>(e.what());
				MessageBox::Show("Błąd podczas wczytywania paczek: " + errorMessage, "Błąd Pliku", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void wypelnijListePaczek(bool uzyjFiltru) {
			listViewPaczki->BeginUpdate();
			listViewPaczki->Items->Clear();

			String^ filtr = textSzukaj->Text->ToLower();
			const auto& paczki = sortownia->getPaczki();

			for (const auto& paczka : paczki) {
				String^ numer = msclr::interop::marshal_as<String^>(paczka.getNumerPaczki());
				String^ miasto = msclr::interop::marshal_as<String^>(paczka.getOdbiorca().miasto);
				String^ kod = msclr::interop::marshal_as<String^>(paczka.getOdbiorca().kodPocztowy);

				if (uzyjFiltru && !String::IsNullOrEmpty(filtr)) {
					if (!numer->ToLower()->Contains(filtr) &&
						!miasto->ToLower()->Contains(filtr) &&
						!kod->ToLower()->Contains(filtr)) {
						continue;
					}
				}

				String^ statusStr = msclr::interop::marshal_as<String^>(statusToString(paczka.getStatus()));
				ListViewItem^ item = gcnew ListViewItem("");
				item->SubItems->Add(numer);
				item->SubItems->Add(miasto);
				item->SubItems->Add(kod);
				item->SubItems->Add(statusStr);

				switch (paczka.getRozmiar()) {
				case Paczka::RozmiarPaczki::MALA: item->ImageIndex = 0; break;
				case Paczka::RozmiarPaczki::SREDNIA: item->ImageIndex = 1; break;
				case Paczka::RozmiarPaczki::DUZA: item->ImageIndex = 2; break;
				}
				listViewPaczki->Items->Add(item);
			}
			aktualizujStatystyki();
			listViewPaczki->EndUpdate();
		}

		void aktualizujStatystyki() {
			labelLiczbaPaczekVal->Text = sortownia->getPaczki().size().ToString();
			chartStatystyki->Series["Miasta"]->Points->Clear();
			if (sortownia->getPaczki().empty()) {
				labelMiastoVal->Text = "Brak";
				return;
			}
			std::map<std::string, int> licznikiMiast;
			for (const auto& paczka : sortownia->getPaczki()) {
				if (!paczka.getOdbiorca().miasto.empty()) {
					licznikiMiast[paczka.getOdbiorca().miasto]++;
				}
			}
			if (licznikiMiast.empty()) {
				labelMiastoVal->Text = "Brak";
				return;
			}

			std::pair<std::string, int> maxPair = *licznikiMiast.begin();
			for (const auto& pair : licznikiMiast) {
				if (pair.second > maxPair.second) {
					maxPair = pair;
				}
			}
			labelMiastoVal->Text = gcnew String(maxPair.first.c_str());

			std::vector<std::pair<std::string, int>> sortedCities(licznikiMiast.begin(), licznikiMiast.end());
			std::sort(sortedCities.begin(), sortedCities.end(), compareMapPairValues);
			int count = 0;
			for (const auto& pair : sortedCities) {
				if (count >= 5) break;
				chartStatystyki->Series["Miasta"]->Points->AddXY(gcnew String(pair.first.c_str()), pair.second);
				count++;
			}
		}
		void utworzIkony() {
			Bitmap^ bmpMala = gcnew Bitmap(16, 16);
			Graphics^ g = Graphics::FromImage(bmpMala);
			g->FillRectangle(Brushes::LightBlue, 0, 0, 16, 16);
			g->DrawString("S", gcnew System::Drawing::Font("Arial", 8, FontStyle::Bold), Brushes::Black, 3, 2);
			imageListPaczki->Images->Add(bmpMala);

			Bitmap^ bmpSrednia = gcnew Bitmap(16, 16);
			g = Graphics::FromImage(bmpSrednia);
			g->FillRectangle(Brushes::LightGreen, 0, 0, 16, 16);
			g->DrawString("M", gcnew System::Drawing::Font("Arial", 8, FontStyle::Bold), Brushes::Black, 2, 2);
			imageListPaczki->Images->Add(bmpSrednia);

			Bitmap^ bmpDuza = gcnew Bitmap(16, 16);
			g = Graphics::FromImage(bmpDuza);
			g->FillRectangle(Brushes::LightCoral, 0, 0, 16, 16);
			g->DrawString("L", gcnew System::Drawing::Font("Arial", 8, FontStyle::Bold), Brushes::Black, 3, 2);
			imageListPaczki->Images->Add(bmpDuza);
			delete g;
		}
	};
}
