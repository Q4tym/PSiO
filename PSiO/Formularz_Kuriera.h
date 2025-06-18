#pragma once

#include "Klasy.h"
#include <map>
#include <string>
#include <algorithm>
#include <vector> // Potrzebne do sortowania mapy
#include <msclr/marshal_cppstd.h>

//--[IMPROVEMENT: Charting]--
// Należy dodać referencję do System.Windows.Forms.DataVisualization w ustawieniach projektu
#using <System.Windows.Forms.DataVisualization.dll>

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;


	inline bool compareMapPairValues(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second > b.second; // Sortowanie malejąco
	}


	public ref class Formularz_Kuriera : public System::Windows::Forms::Form
	{
	public:
		Formularz_Kuriera(void) {
			InitializeComponent();
			//--[REQUIREMENT: Dynamic memory allocation]--
			sortownia = new Sortownia();
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

	private: // DEKLARACJE ZMIENNYCH CZŁONKOWSKICH
		Sortownia* sortownia;
<<<<<<<<< Temporary merge branch 1
		ListView^ listViewPaczki;
		Button^ buttonSortujMiasto;
		Button^ buttonSortujKod;
		Button^ buttonSortujAdres;
		Button^ buttonOdswiez;
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
			// 
			// buttonSortujAdres
			// 
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
			// 
			// listViewPaczki
			// 
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
			// 
			// imageListPaczki
			// 
			this->imageListPaczki->ColorDepth = System::Windows::Forms::ColorDepth::Depth32Bit;
			this->imageListPaczki->ImageSize = System::Drawing::Size(16, 16);
			this->imageListPaczki->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// contextMenuPaczka
			// 
			this->contextMenuPaczka->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) { this->statusWSortowni, this->statusWDoreczeniu, this->statusDostarczono });
			this->contextMenuPaczka->Name = L"contextMenuPaczka";
			this->contextMenuPaczka->Size = System::Drawing::Size(225, 70);
			// 
			// statusWSortowni
			// 
			this->statusWSortowni->Name = L"statusWSortowni";
			this->statusWSortowni->Size = System::Drawing::Size(224, 22);
			this->statusWSortowni->Text = L"Zmień status na \'W sortowni\'";
			this->statusWSortowni->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::statusWSortowni_Click);
			// 
			// statusWDoreczeniu
			// 
			this->statusWDoreczeniu->Name = L"statusWDoreczeniu";
			this->statusWDoreczeniu->Size = System::Drawing::Size(224, 22);
			this->statusWDoreczeniu->Text = L"Zmień status na \'W doręczeniu\'";
			this->statusWDoreczeniu->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::statusWDoreczeniu_Click);
			// 
			// statusDostarczono
			// 
			this->statusDostarczono->Name = L"statusDostarczono";
			this->statusDostarczono->Size = System::Drawing::Size(224, 22);
			this->statusDostarczono->Text = L"Zmień status na \'Dostarczono\'";
			this->statusDostarczono->Click += gcnew System::EventHandler(this, &Formularz_Kuriera::statusDostarczono_Click);
			// 
			// buttonSortujMiasto
			// 
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
			// 
			// buttonSortujKod
			// 
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
			// 
			// buttonOdswiez
			// 
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
			// 
<<<<<<<<< Temporary merge branch 1
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
			this->labelInfo->TabIndex = 4;
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
<<<<<<<<< Temporary merge branch 1
			this->groupBoxStatystyki->ForeColor = System::Drawing::Color::FromArgb(0, 122, 204);
			this->groupBoxStatystyki->Location = System::Drawing::Point(12, 416);
			this->groupBoxStatystyki->Name = L"groupBoxStatystyki";
			this->groupBoxStatystyki->Size = System::Drawing::Size(860, 66);
			this->groupBoxStatystyki->TabIndex = 7;
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
			this->labelStatLiczbaPaczek->TabIndex = 0;
			this->labelStatLiczbaPaczek->Text = L"Całkowita liczba paczek:";
			// 
			// chartStatystyki
			// 
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
			// 
			// textSzukaj
			// 
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
			// 
			// labelSzukaj
			// 
			this->labelSzukaj->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->labelSzukaj->AutoSize = true;
			this->labelSzukaj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelSzukaj->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelSzukaj->Location = System::Drawing::Point(9, 372);
			this->labelSzukaj->Name = L"labelSzukaj";
			this->labelSzukaj->Size = System::Drawing::Size(180, 17);
			this->labelSzukaj->TabIndex = 8;
			this->labelSzukaj->Text = L"🔎 Wyszukaj (Nr, Miasto, Kod):";
			// 
			// Formularz_Kuriera
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
<<<<<<<<< Temporary merge branch 1
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
			this->Load += gcnew System::EventHandler(this, &Formularz_Kuriera::Formularz_Kuriera_Load);
			this->contextMenuPaczka->ResumeLayout(false);
			this->groupBoxStatystyki->ResumeLayout(false);
			this->groupBoxStatystyki->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStatystyki))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

<<<<<<<<< Temporary merge branch 1
	private:
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
<<<<<<<<< Temporary merge branch 1

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

			//--[REQUIREMENT: STL Algorithm]--
			// Znajdź miasto z największą liczbą paczek
			auto maxElement = std::max_element(licznikiMiast.begin(), licznikiMiast.end(), compareMapPairValues);
			labelMiastoVal->Text = gcnew String(maxElement->first.c_str());

			// Konwertuj mapę do wektora, aby ją posortować i wziąć TOP 5
			std::vector<std::pair<std::string, int>> sortedCities(licznikiMiast.begin(), licznikiMiast.end());
			std::sort(sortedCities.begin(), sortedCities.end(), compareMapPairValues);

			// Wypełnij wykres danymi
			int count = 0;
			for (const auto& pair : sortedCities) {
				if (count >= 5) break;
				String^ miasto = gcnew String(pair.first.c_str());
				chartStatystyki->Series["Miasta"]->Points->AddXY(miasto, pair.second);
				count++;
			}
		}
=========
>>>>>>>>> Temporary merge branch 2
	};
}