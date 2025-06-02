#pragma once
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "Klasy.h"
#include <fstream> // Required for file operations
#include "json.hpp" // Include the nlohmann/json header (assuming it's in your project)
#include <iomanip> // For std::setw

namespace PSiO {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Podsumowanie informacji o Formularz_paczki
    /// </summary>
    public ref class Formularz_paczki : public System::Windows::Forms::Form
    {
    public:
        Formularz_paczki(void)
        {
            InitializeComponent();

            // Nadawca
            this->textBox1->Text = "Wpisz imie";
            this->textBox1->ForeColor = System::Drawing::Color::Gray;
            this->textBox2->Text = "Wpisz nazwisko";
            this->textBox2->ForeColor = System::Drawing::Color::Gray;
            this->textBox3->Text = "Wpisz telefon";
            this->textBox3->ForeColor = System::Drawing::Color::Gray;
            this->textBox4->Text = "Wpisz email";
            this->textBox4->ForeColor = System::Drawing::Color::Gray;
            this->textBox5->Text = "Wpisz ulice";
            this->textBox5->ForeColor = System::Drawing::Color::Gray;
            this->textBox6->Text = "Wpisz miasto";
            this->textBox6->ForeColor = System::Drawing::Color::Gray;
            this->textBox7->Text = "Wpisz wojewodztwo";
            this->textBox7->ForeColor = System::Drawing::Color::Gray;
            this->textBox8->Text = "Wpisz kodPocztowy";
            this->textBox8->ForeColor = System::Drawing::Color::Gray;
            this->textBox9->Text = "Wpisz kraj";
            this->textBox9->ForeColor = System::Drawing::Color::Gray;

            // Odbiorca
            this->textBox10->Text = "Wpisz kraj";
            this->textBox10->ForeColor = System::Drawing::Color::Gray;
            this->textBox11->Text = "Wpisz kodPocztowy";
            this->textBox11->ForeColor = System::Drawing::Color::Gray;
            this->textBox12->Text = "Wpisz wojewodztwo";
            this->textBox12->ForeColor = System::Drawing::Color::Gray;
            this->textBox13->Text = "Wpisz miasto";
            this->textBox13->ForeColor = System::Drawing::Color::Gray;
            this->textBox14->Text = "Wpisz ulice";
            this->textBox14->ForeColor = System::Drawing::Color::Gray;
            this->textBox15->Text = "Wpisz email";
            this->textBox15->ForeColor = System::Drawing::Color::Gray;
            this->textBox16->Text = "Wpisz telefon";
            this->textBox16->ForeColor = System::Drawing::Color::Gray;
            this->textBox17->Text = "Wpisz nazwisko";
            this->textBox17->ForeColor = System::Drawing::Color::Gray;
            this->textBox18->Text = "Wpisz imie";
            this->textBox18->ForeColor = System::Drawing::Color::Gray;
        }

    protected:
        /// <summary>
        /// Wyczyœæ wszystkie u¿ywane zasoby.
        /// </summary>
        ~Formularz_paczki()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::Button^ button1;
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
    private: System::Windows::Forms::Label^ label2;
    protected:

    private:
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
<<<<<<<<< Temporary merge branch 1
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Formularz_paczki::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(36, 79);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"NADAWCA";
			this->label1->Click += gcnew System::EventHandler(this, &Formularz_paczki::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->AccessibleName = L"";
			this->textBox1->Location = System::Drawing::Point(36, 118);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox1_Enter);
			this->textBox1->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox1_Leave);
			// 
			// textBox2
			// 
			this->textBox2->AccessibleName = L"";
			this->textBox2->Location = System::Drawing::Point(36, 150);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 22);
			this->textBox2->TabIndex = 2;
			this->textBox2->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox2_Enter);
			this->textBox2->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox2_Leave);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(661, 796);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Zakoñcz";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Formularz_paczki::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->AccessibleName = L"";
			this->textBox3->Location = System::Drawing::Point(36, 182);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(132, 22);
			this->textBox3->TabIndex = 3;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox3_TextChanged);
			this->textBox3->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox3_Enter);
			this->textBox3->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox3_Leave);
			// 
			// textBox4
			// 
			this->textBox4->AccessibleName = L"";
			this->textBox4->Location = System::Drawing::Point(36, 214);
			this->textBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(132, 22);
			this->textBox4->TabIndex = 4;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_TextChanged);
			this->textBox4->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_Enter);
			this->textBox4->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_Leave);
			// 
			// textBox5
			// 
			this->textBox5->AccessibleName = L"";
			this->textBox5->Location = System::Drawing::Point(36, 246);
			this->textBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(132, 22);
			this->textBox5->TabIndex = 5;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox5_TextChanged);
			this->textBox5->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox5_Enter);
			this->textBox5->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox5_Leave);
			// 
			// textBox6
			// 
			this->textBox6->AccessibleName = L"";
			this->textBox6->Location = System::Drawing::Point(36, 278);
			this->textBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(132, 22);
			this->textBox6->TabIndex = 6;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox6_TextChanged);
			this->textBox6->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox6_Enter);
			this->textBox6->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox6_Leave);
			// 
			// textBox7
			// 
			this->textBox7->AccessibleName = L"";
			this->textBox7->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox7.AutoCompleteCustomSource") });
			this->textBox7->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->textBox7->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->textBox7->Location = System::Drawing::Point(36, 310);
			this->textBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(132, 22);
			this->textBox7->TabIndex = 7;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox7_TextChanged);
			this->textBox7->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox7_Enter);
			this->textBox7->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox7_Leave);
			// 
			// textBox8
			// 
			this->textBox8->AccessibleName = L"";
			this->textBox8->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox8.AutoCompleteCustomSource") });
			this->textBox8->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->textBox8->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->textBox8->Location = System::Drawing::Point(36, 342);
			this->textBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(132, 22);
			this->textBox8->TabIndex = 8;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox8_TextChanged);
			this->textBox8->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox8_Enter);
			this->textBox8->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox8_Leave);
			// 
			// textBox9
			// 
			this->textBox9->AccessibleName = L"";
			this->textBox9->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox9.AutoCompleteCustomSource") });
			this->textBox9->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->textBox9->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->textBox9->Location = System::Drawing::Point(36, 374);
			this->textBox9->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(132, 22);
			this->textBox9->TabIndex = 9;
			this->textBox9->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox9_Enter);
			this->textBox9->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox9_Leave);
			// 
			// textBox10
			// 
			this->textBox10->AccessibleName = L"";
			this->textBox10->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox10.AutoCompleteCustomSource") });
			this->textBox10->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->textBox10->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->textBox10->Location = System::Drawing::Point(552, 374);
			this->textBox10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(132, 22);
			this->textBox10->TabIndex = 19;
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox10_TextChanged);
			this->textBox10->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox10_Enter);
			this->textBox10->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox10_Leave);
			// 
			// textBox11
			// 
			this->textBox11->AccessibleName = L"";
			this->textBox11->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox11.AutoCompleteCustomSource") });
			this->textBox11->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->textBox11->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->textBox11->Location = System::Drawing::Point(552, 342);
			this->textBox11->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(132, 22);
			this->textBox11->TabIndex = 18;
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox11_TextChanged);
			this->textBox11->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox11_Enter);
			this->textBox11->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox11_Leave);
			// 
			// textBox12
			// 
			this->textBox12->AccessibleName = L"";
			this->textBox12->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox12.AutoCompleteCustomSource") });
			this->textBox12->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->textBox12->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->textBox12->Location = System::Drawing::Point(552, 310);
			this->textBox12->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(132, 22);
			this->textBox12->TabIndex = 17;
			this->textBox12->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox12_TextChanged);
			this->textBox12->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox12_Enter);
			this->textBox12->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox12_Leave);
			// 
			// textBox13
			// 
			this->textBox13->AccessibleName = L"";
			this->textBox13->Location = System::Drawing::Point(552, 278);
			this->textBox13->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(132, 22);
			this->textBox13->TabIndex = 16;
			this->textBox13->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox13_TextChanged);
			this->textBox13->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox13_Enter);
			this->textBox13->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox13_Leave);
			// 
			// textBox14
			// 
			this->textBox14->AccessibleName = L"";
			this->textBox14->Location = System::Drawing::Point(552, 246);
			this->textBox14->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(132, 22);
			this->textBox14->TabIndex = 15;
			this->textBox14->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox14_TextChanged);
			this->textBox14->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox14_Enter);
			this->textBox14->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox14_Leave);
			// 
			// textBox15
			// 
			this->textBox15->AccessibleName = L"";
			this->textBox15->Location = System::Drawing::Point(552, 214);
			this->textBox15->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(132, 22);
			this->textBox15->TabIndex = 14;
			this->textBox15->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox15_TextChanged);
			this->textBox15->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox15_Enter);
			this->textBox15->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox15_Leave);
			// 
			// textBox16
			// 
			this->textBox16->AccessibleName = L"";
			this->textBox16->Location = System::Drawing::Point(552, 182);
			this->textBox16->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(132, 22);
			this->textBox16->TabIndex = 13;
			this->textBox16->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox16_TextChanged);
			this->textBox16->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox16_Enter);
			this->textBox16->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox16_Leave);
			// 
			// textBox17
			// 
			this->textBox17->AccessibleName = L"";
			this->textBox17->Location = System::Drawing::Point(552, 150);
			this->textBox17->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(132, 22);
			this->textBox17->TabIndex = 12;
			this->textBox17->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox17_TextChanged);
			this->textBox17->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox17_Enter);
			this->textBox17->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox17_Leave);
			// 
			// textBox18
			// 
			this->textBox18->AccessibleName = L"";
			this->textBox18->Location = System::Drawing::Point(552, 118);
			this->textBox18->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(132, 22);
			this->textBox18->TabIndex = 11;
			this->textBox18->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox18_TextChanged);
			this->textBox18->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox18_Enter);
			this->textBox18->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox18_Leave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Location = System::Drawing::Point(552, 79);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 18);
			this->label2->TabIndex = 10;
			this->label2->Text = L"ODBIORCA";
			this->label2->Click += gcnew System::EventHandler(this, &Formularz_paczki::label2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"List", L"Paczka", L"Paleta" });
			this->comboBox1->Location = System::Drawing::Point(313, 198);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 20;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Formularz_paczki::comboBox1_SelectedIndexChanged);
			// 
			// Formularz_paczki
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(777, 839);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->textBox17);
			this->Controls->Add(this->textBox18);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Formularz_paczki";
			this->Text = L"Formularz_paczki";
			this->Load += gcnew System::EventHandler(this, &Formularz_paczki::Formularz_paczki_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
=========
        /// <summary>
        /// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
        /// jej zawartoœci w edytorze kodu.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Formularz_paczki::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->textBox5 = (gcnew System::Windows::Forms::TextBox());
            this->textBox6 = (gcnew System::Windows::Forms::TextBox());
            this->textBox7 = (gcnew System::Windows::Forms::TextBox());
            this->textBox8 = (gcnew System::Windows::Forms::TextBox());
            this->textBox9 = (gcnew System::Windows::Forms::TextBox());
            this->textBox10 = (gcnew System::Windows::Forms::TextBox());
            this->textBox11 = (gcnew System::Windows::Forms::TextBox());
            this->textBox12 = (gcnew System::Windows::Forms::TextBox());
            this->textBox13 = (gcnew System::Windows::Forms::TextBox());
            this->textBox14 = (gcnew System::Windows::Forms::TextBox());
            this->textBox15 = (gcnew System::Windows::Forms::TextBox());
            this->textBox16 = (gcnew System::Windows::Forms::TextBox());
            this->textBox17 = (gcnew System::Windows::Forms::TextBox());
            this->textBox18 = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->label1->Location = System::Drawing::Point(27, 64);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(64, 15);
            this->label1->TabIndex = 0;
            this->label1->Text = L"NADAWCA";
            this->label1->Click += gcnew System::EventHandler(this, &Formularz_paczki::label1_Click);
            //
            // textBox1
            //
            this->textBox1->AccessibleName = L"";
            this->textBox1->Location = System::Drawing::Point(27, 96);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(100, 20);
            this->textBox1->TabIndex = 1;
            this->textBox1->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox1_Enter);
            this->textBox1->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox1_Leave);
            //
            // textBox2
            //
            this->textBox2->AccessibleName = L"";
            this->textBox2->Location = System::Drawing::Point(27, 122);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(100, 20);
            this->textBox2->TabIndex = 2;
            this->textBox2->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox2_Enter);
            this->textBox2->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox2_Leave);
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(496, 647);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Zakoñcz";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Formularz_paczki::button1_Click);
            //
            // textBox3
            //
            this->textBox3->AccessibleName = L"";
            this->textBox3->Location = System::Drawing::Point(27, 148);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(100, 20);
            this->textBox3->TabIndex = 3;
            // Removed TextChanged handler
            this->textBox3->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox3_Enter);
            this->textBox3->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox3_Leave);
            //
            // textBox4
            //
            this->textBox4->AccessibleName = L"";
            this->textBox4->Location = System::Drawing::Point(27, 174);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(100, 20);
            this->textBox4->TabIndex = 4;
            // Removed TextChanged handler
            this->textBox4->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_Enter);
            this->textBox4->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_Leave);
            //
            // textBox5
            //
            this->textBox5->AccessibleName = L"";
            this->textBox5->Location = System::Drawing::Point(27, 200);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(100, 20);
            this->textBox5->TabIndex = 5;
            // Removed TextChanged handler
            this->textBox5->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox5_Enter);
            this->textBox5->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox5_Leave);
            //
            // textBox6
            //
            this->textBox6->AccessibleName = L"";
            this->textBox6->Location = System::Drawing::Point(27, 226);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(100, 20);
            this->textBox6->TabIndex = 6;
            // Removed TextChanged handler
            this->textBox6->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox6_Enter);
            this->textBox6->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox6_Leave);
            //
            // textBox7
            //
            this->textBox7->AccessibleName = L"";
            this->textBox7->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox7.AutoCompleteCustomSource") });
            this->textBox7->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->textBox7->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->textBox7->Location = System::Drawing::Point(27, 252);
            this->textBox7->Name = L"textBox7";
            this->textBox7->Size = System::Drawing::Size(100, 20);
            this->textBox7->TabIndex = 7;
            // Removed TextChanged handler
            this->textBox7->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox7_Enter);
            this->textBox7->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox7_Leave);
            //
            // textBox8
            //
            this->textBox8->AccessibleName = L"";
            this->textBox8->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox8.AutoCompleteCustomSource") });
            this->textBox8->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->textBox8->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->textBox8->Location = System::Drawing::Point(27, 278);
            this->textBox8->Name = L"textBox8";
            this->textBox8->Size = System::Drawing::Size(100, 20);
            this->textBox8->TabIndex = 8;
            // Removed TextChanged handler
            this->textBox8->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox8_Enter);
            this->textBox8->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox8_Leave);
            //
            // textBox9
            //
            this->textBox9->AccessibleName = L"";
            this->textBox9->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox9.AutoCompleteCustomSource") });
            this->textBox9->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->textBox9->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->textBox9->Location = System::Drawing::Point(27, 304);
            this->textBox9->Name = L"textBox9";
            this->textBox9->Size = System::Drawing::Size(100, 20);
            this->textBox9->TabIndex = 9;
            this->textBox9->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox9_Enter);
            this->textBox9->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox9_Leave);
            //
            // textBox10
            //
            this->textBox10->AccessibleName = L"";
            this->textBox10->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox10.AutoCompleteCustomSource") });
            this->textBox10->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->textBox10->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->textBox10->Location = System::Drawing::Point(414, 304);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(100, 20);
            this->textBox10->TabIndex = 19;
            // Removed TextChanged handler
            this->textBox10->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox10_Enter);
            this->textBox10->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox10_Leave);
            //
            // textBox11
            //
            this->textBox11->AccessibleName = L"";
            this->textBox11->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox11.AutoCompleteCustomSource") });
            this->textBox11->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->textBox11->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->textBox11->Location = System::Drawing::Point(414, 278);
            this->textBox11->Name = L"textBox11";
            this->textBox11->Size = System::Drawing::Size(100, 20);
            this->textBox11->TabIndex = 18;
            // Removed TextChanged handler
            this->textBox11->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox11_Enter);
            this->textBox11->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox11_Leave);
            //
            // textBox12
            //
            this->textBox12->AccessibleName = L"";
            this->textBox12->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { resources->GetString(L"textBox12.AutoCompleteCustomSource") });
            this->textBox12->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->textBox12->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->textBox12->Location = System::Drawing::Point(414, 252);
            this->textBox12->Name = L"textBox12";
            this->textBox12->Size = System::Drawing::Size(100, 20);
            this->textBox12->TabIndex = 17;
            // Removed TextChanged handler
            this->textBox12->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox12_Enter);
            this->textBox12->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox12_Leave);
            //
            // textBox13
            //
            this->textBox13->AccessibleName = L"";
            this->textBox13->Location = System::Drawing::Point(414, 226);
            this->textBox13->Name = L"textBox13";
            this->textBox13->Size = System::Drawing::Size(100, 20);
            this->textBox13->TabIndex = 16;
            // Removed TextChanged handler
            this->textBox13->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox13_Enter);
            this->textBox13->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox13_Leave);
            //
            // textBox14
            //
            this->textBox14->AccessibleName = L"";
            this->textBox14->Location = System::Drawing::Point(414, 200);
            this->textBox14->Name = L"textBox14";
            this->textBox14->Size = System::Drawing::Size(100, 20);
            this->textBox14->TabIndex = 15;
            // Removed TextChanged handler
            this->textBox14->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox14_Enter);
            this->textBox14->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox14_Leave);
            //
            // textBox15
            //
            this->textBox15->AccessibleName = L"";
            this->textBox15->Location = System::Drawing::Point(414, 174);
            this->textBox15->Name = L"textBox15";
            this->textBox15->Size = System::Drawing::Size(100, 20);
            this->textBox15->TabIndex = 14;
            // Removed TextChanged handler
            this->textBox15->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox15_Enter);
            this->textBox15->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox15_Leave);
            //
            // textBox16
            //
            this->textBox16->AccessibleName = L"";
            this->textBox16->Location = System::Drawing::Point(414, 148);
            this->textBox16->Name = L"textBox16";
            this->textBox16->Size = System::Drawing::Size(100, 20);
            this->textBox16->TabIndex = 13;
            // Removed TextChanged handler
            this->textBox16->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox16_Enter);
            this->textBox16->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox16_Leave);
            //
            // textBox17
            //
            this->textBox17->AccessibleName = L"";
            this->textBox17->Location = System::Drawing::Point(414, 122);
            this->textBox17->Name = L"textBox17";
            this->textBox17->Size = System::Drawing::Size(100, 20);
            this->textBox17->TabIndex = 12;
            // Removed TextChanged handler
            this->textBox17->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox17_Enter);
            this->textBox17->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox17_Leave);
            //
            // textBox18
            //
            this->textBox18->AccessibleName = L"";
            this->textBox18->Location = System::Drawing::Point(414, 96);
            this->textBox18->Name = L"textBox18";
            this->textBox18->Size = System::Drawing::Size(100, 20);
            this->textBox18->TabIndex = 11;
            // Removed TextChanged handler
            this->textBox18->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox18_Enter);
            this->textBox18->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox18_Leave);
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->label2->Location = System::Drawing::Point(414, 64);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(65, 15);
            this->label2->TabIndex = 10;
            this->label2->Text = L"ODBIORCA";
            this->label2->Click += gcnew System::EventHandler(this, &Formularz_paczki::label2_Click);
            //
            // Formularz_paczki
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(583, 682);
            this->Controls->Add(this->textBox10);
            this->Controls->Add(this->textBox11);
            this->Controls->Add(this->textBox12);
            this->Controls->Add(this->textBox13);
            this->Controls->Add(this->textBox14);
            this->Controls->Add(this->textBox15);
            this->Controls->Add(this->textBox16);
            this->Controls->Add(this->textBox17);
            this->Controls->Add(this->textBox18);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->textBox9);
            this->Controls->Add(this->textBox8);
            this->Controls->Add(this->textBox7);
            this->Controls->Add(this->textBox6);
            this->Controls->Add(this->textBox5);
            this->Controls->Add(this->textBox4);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label1);
            this->Name = L"Formularz_paczki";
            this->Text = L"Formularz_paczki";
            this->Load += gcnew System::EventHandler(this, &Formularz_paczki::Formularz_paczki_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
<<<<<<<<< Temporary merge branch 1
			this->Controls->Add(this->label1);
			this->Name = L"Formularz_paczki";
			this->Text = L"Formularz_paczki";
			this->Load += gcnew System::EventHandler(this, &Formularz_paczki::Formularz_paczki_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
=========
>>>>>>>>> Temporary merge branch 2

        }
#pragma endregion
    private: System::Void Formularz_paczki_Load(System::Object^ sender, System::EventArgs^ e) {
        this->label1->Focus();
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
           // Dane nadawcy
    private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox1->Text == "Wpisz imie") {
            textBox1->Text = "";
            textBox1->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox1->Text)) {
            textBox1->Text = "Wpisz imie";
            textBox1->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox2->Text == "Wpisz nazwisko") {
            textBox2->Text = "";
            textBox2->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox2_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox2->Text)) {
            textBox2->Text = "Wpisz nazwisko";
            textBox2->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox3_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox3->Text == "Wpisz telefon") {
            textBox3->Text = "";
            textBox3->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox3_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox3->Text)) {
            textBox3->Text = "Wpisz telefon";
            textBox3->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox4->Text == "Wpisz email") {
            textBox4->Text = "";
            textBox4->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox4_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox4->Text)) {
            textBox4->Text = "Wpisz email";
            textBox4->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox5_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox5->Text == "Wpisz ulice") {
            textBox5->Text = "";
            textBox5->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox5_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox5->Text)) {
            textBox5->Text = "Wpisz ulice";
            textBox5->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox6_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox6->Text == "Wpisz miasto") {
            textBox6->Text = "";
            textBox6->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox6_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox6->Text)) {
            textBox6->Text = "Wpisz miasto";
            textBox6->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox7_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox7->Text == "Wpisz wojewodztwo") {
            textBox7->Text = "";
            textBox7->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox7_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox7->Text)) {
            textBox7->Text = "Wpisz wojewodztwo";
            textBox7->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox8_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox8->Text == "Wpisz kodPocztowy") {
            textBox8->Text = "";
            textBox8->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox8_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox8->Text)) {
            textBox8->Text = "Wpisz kodPocztowy";
            textBox8->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox9_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox9->Text == "Wpisz kraj") {
            textBox9->Text = "";
            textBox9->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox9_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox9->Text)) {
            textBox9->Text = "Wpisz kraj";
            textBox9->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Dane odbiorcy
    private: System::Void textBox10_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox10->Text == "Wpisz kraj") {
            textBox10->Text = "";
            textBox10->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox10_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox10->Text)) {
            textBox10->Text = "Wpisz kraj";
            textBox10->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox11_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox11->Text == "Wpisz kodPocztowy") {
            textBox11->Text = "";
            textBox11->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox11_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox11->Text)) {
            textBox11->Text = "Wpisz kodPocztowy";
            textBox11->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox12_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox12->Text == "Wpisz wojewodztwo") {
            textBox12->Text = "";
            textBox12->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox12_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox12->Text)) {
            textBox12->Text = "Wpisz wojewodztwo";
            textBox12->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox13_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox13->Text == "Wpisz miasto") {
            textBox13->Text = "";
            textBox13->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox13_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox13->Text)) {
            textBox13->Text = "Wpisz miasto";
            textBox13->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox14_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox14->Text == "Wpisz ulice") {
            textBox14->Text = "";
            textBox14->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox14_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox14->Text)) {
            textBox14->Text = "Wpisz ulice";
            textBox14->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox15_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox15->Text == "Wpisz email") {
            textBox15->Text = "";
            textBox15->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox15_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox15->Text)) {
            textBox15->Text = "Wpisz email";
            textBox15->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox16_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox16->Text == "Wpisz telefon") {
            textBox16->Text = "";
            textBox16->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox16_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox16->Text)) {
            textBox16->Text = "Wpisz telefon";
            textBox16->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox17_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox17->Text == "Wpisz nazwisko") {
            textBox17->Text = "";
            textBox17->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox17_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox17->Text)) {
            textBox17->Text = "Wpisz nazwisko";
            textBox17->ForeColor = System::Drawing::Color::Gray;
        }
    }
    private: System::Void textBox18_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (textBox18->Text == "Wpisz imie") {
            textBox18->Text = "";
            textBox18->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox18_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(textBox18->Text)) {
            textBox18->Text = "Wpisz imie";
            textBox18->ForeColor = System::Drawing::Color::Gray;
        }
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Convert System::String to std::string
        std::string nadawcaImie = msclr::interop::marshal_as<std::string>(textBox1->Text);
        std::string nadawcaNazwisko = msclr::interop::marshal_as<std::string>(textBox2->Text);
        std::string nadawcaTelefon = msclr::interop::marshal_as<std::string>(textBox3->Text);
        std::string nadawcaEmail = msclr::interop::marshal_as<std::string>(textBox4->Text);
        std::string nadawcaUlica = msclr::interop::marshal_as<std::string>(textBox5->Text);
        std::string nadawcaMiasto = msclr::interop::marshal_as<std::string>(textBox6->Text);
        std::string nadawcaWojewodztwo = msclr::interop::marshal_as<std::string>(textBox7->Text);
        std::string nadawcaKodPocztowy = msclr::interop::marshal_as<std::string>(textBox8->Text);
        std::string nadawcaKraj = msclr::interop::marshal_as<std::string>(textBox9->Text);

        std::string odbiorcaImie = msclr::interop::marshal_as<std::string>(textBox18->Text);
        std::string odbiorcaNazwisko = msclr::interop::marshal_as<std::string>(textBox17->Text);
        std::string odbiorcaTelefon = msclr::interop::marshal_as<std::string>(textBox16->Text);
        std::string odbiorcaEmail = msclr::interop::marshal_as<std::string>(textBox15->Text);
        std::string odbiorcaUlica = msclr::interop::marshal_as<std::string>(textBox14->Text);
        std::string odbiorcaMiasto = msclr::interop::marshal_as<std::string>(textBox13->Text);
        std::string odbiorcaWojewodztwo = msclr::interop::marshal_as<std::string>(textBox12->Text);
        std::string odbiorcaKodPocztowy = msclr::interop::marshal_as<std::string>(textBox11->Text);
        std::string odbiorcaKraj = msclr::interop::marshal_as<std::string>(textBox10->Text);

<<<<<<<<< Temporary merge branch 1
        // Tworzenie obiektu Odbiorca
        Odbiorca odbiorca;
        odbiorca.imie = imieOdbiorcy;
        odbiorca.nazwisko = nazwiskoOdbiorcy;
        odbiorca.telefon = telefonOdbiorcy;
        odbiorca.email = emailOdbiorcy;
        // Tworzenie obiektu Paczka z referencjami do nadawcy i odbiorcy
        Paczka paczka(nadawca, odbiorca);
        odbiorca.wojewodztwo = wojewodztwoOdbiorcy;
        odbiorca.kodPocztowy = kodPocztowyOdbiorcy;
        odbiorca.kraj = krajOdbiorcy;

		// Tworzenie obiektu Paczka z referencjami do nadawcy i odbiorcy
		Paczka paczka(nadawca, odbiorca);
=========
        // Create Nadawca object
        Nadawca nadawcaObj;
        nadawcaObj.imie = nadawcaImie;
        nadawcaObj.nazwisko = nadawcaNazwisko;
        nadawcaObj.telefon = nadawcaTelefon;
        nadawcaObj.email = nadawcaEmail;
        nadawcaObj.ulica = nadawcaUlica;
        nadawcaObj.miasto = nadawcaMiasto;
        nadawcaObj.wojewodztwo = nadawcaWojewodztwo;
        nadawcaObj.kodPocztowy = nadawcaKodPocztowy;
        nadawcaObj.kraj = nadawcaKraj;

        // Create Odbiorca object
        Odbiorca odbiorcaObj;
        odbiorcaObj.imie = odbiorcaImie;
        odbiorcaObj.nazwisko = odbiorcaNazwisko;
        odbiorcaObj.telefon = odbiorcaTelefon;
        odbiorcaObj.email = odbiorcaEmail;
        odbiorcaObj.ulica = odbiorcaUlica;
        odbiorcaObj.miasto = odbiorcaMiasto;
        odbiorcaObj.wojewodztwo = odbiorcaWojewodztwo;
        odbiorcaObj.kodPocztowy = odbiorcaKodPocztowy;
        odbiorcaObj.kraj = odbiorcaKraj;

        // Tworzenie obiektu Paczka z przekazaniem obiektów Nadawca i Odbiorca
        Paczka paczka(nadawcaObj, odbiorcaObj); // This line now calls the correct constructor
>>>>>>>>> Temporary merge branch 2

        // *** JSON Serialization and File Save ***
        nlohmann::json j;
        j["numerPaczki"] = paczka.getNumerPaczki();
        j["nadawca"] = {
            {"imie", paczka.getNadawca().imie}, // Accessing Nadawca data via getter
            {"nazwisko", paczka.getNadawca().nazwisko},
            {"telefon", paczka.getNadawca().telefon},
            {"email", paczka.getNadawca().email},
            {"adres", {
                {"ulica", paczka.getNadawca().ulica},
                {"miasto", paczka.getNadawca().miasto},
                {"wojewodztwo", paczka.getNadawca().wojewodztwo},
                {"kodPocztowy", paczka.getNadawca().kodPocztowy},
                {"kraj", paczka.getNadawca().kraj}
            }}
        };
        j["odbiorca"] = {
            {"imie", paczka.getOdbiorca().imie}, // Accessing Odbiorca data via getter
            {"nazwisko", paczka.getOdbiorca().nazwisko},
            {"telefon", paczka.getOdbiorca().telefon},
            {"email", paczka.getOdbiorca().email},
            {"adres", {
                {"ulica", paczka.getOdbiorca().ulica},
                {"miasto", paczka.getOdbiorca().miasto},
                {"wojewodztwo", paczka.getOdbiorca().wojewodztwo},
                {"kodPocztowy", paczka.getOdbiorca().kodPocztowy},
                {"kraj", paczka.getOdbiorca().kraj}
            }}
        };

        std::ofstream o("paczka_data.json");
        if (o.is_open()) {
            o << std::setw(4) << j << std::endl; // Pretty print with 4 space indent
            o.close();
            System::Windows::Forms::MessageBox::Show("Dane paczki zosta³y zapisane do paczka_data.json");
        }
        else {
            System::Windows::Forms::MessageBox::Show("B³¹d: Nie mo¿na zapisaæ pliku paczka_data.json");
        }
<<<<<<<<< Temporary merge branch 1
    private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
=========
        // *** END JSON Serialization and File Save ***

        this->Close();
        paczka.paczkaPrzyjeta();
    }

           // Keeping only label2_Click as it was the only one explicitly defined previously and not removed by me.
           // All the other TextChanged methods (textBox3_TextChanged to textBox18_TextChanged) were commented out
           // or removed because they were not explicitly defined with functionality and caused errors.
>>>>>>>>> Temporary merge branch 2
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
           // Removed all the previously problematic textBoxX_TextChanged methods to prevent further errors.
    };
<<<<<<<<< Temporary merge branch 1
}private: System::Void textBox18_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox10_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
=========
}
>>>>>>>>> Temporary merge branch 2
