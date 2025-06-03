#pragma once
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "Klasy.h" //
#include <fstream>
#include "json.hpp"
#include <iomanip>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

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
            // Inicjalizacja placeholderów (jak w poprzednich odpowiedziach)
            // Nadawca
            this->textBox1->Text = "Wpisz imie"; //
            this->textBox1->ForeColor = System::Drawing::Color::Gray; //
            this->textBox2->Text = "Wpisz nazwisko"; //
            this->textBox2->ForeColor = System::Drawing::Color::Gray; //
            this->textBox3->Text = "Wpisz telefon"; //
            this->textBox3->ForeColor = System::Drawing::Color::Gray; //
            this->textBox4->Text = "Wpisz email"; //
            this->textBox4->ForeColor = System::Drawing::Color::Gray; //
            this->textBox5->Text = "Wpisz ulice"; //
            this->textBox5->ForeColor = System::Drawing::Color::Gray; //
            this->textBox6->Text = "Wpisz miasto"; //
            this->textBox6->ForeColor = System::Drawing::Color::Gray; //
            this->textBox7->Text = "Wpisz wojewodztwo"; //
            this->textBox7->ForeColor = System::Drawing::Color::Gray; //
            this->textBox8->Text = "Wpisz kodPocztowy"; //
            this->textBox8->ForeColor = System::Drawing::Color::Gray; //
            this->textBox9->Text = "Wpisz kraj"; //
            this->textBox9->ForeColor = System::Drawing::Color::Gray; //

            // Odbiorca
            this->textBox10->Text = "Wpisz kraj"; //
            this->textBox10->ForeColor = System::Drawing::Color::Gray; //
            this->textBox11->Text = "Wpisz kodPocztowy"; //
            this->textBox11->ForeColor = System::Drawing::Color::Gray; //
            this->textBox12->Text = "Wpisz wojewodztwo"; //
            this->textBox12->ForeColor = System::Drawing::Color::Gray; //
            this->textBox13->Text = "Wpisz miasto"; //
            this->textBox13->ForeColor = System::Drawing::Color::Gray; //
            this->textBox14->Text = "Wpisz ulice"; //
            this->textBox14->ForeColor = System::Drawing::Color::Gray; //
            this->textBox15->Text = "Wpisz email"; //
            this->textBox15->ForeColor = System::Drawing::Color::Gray; //
            this->textBox16->Text = "Wpisz telefon"; //
            this->textBox16->ForeColor = System::Drawing::Color::Gray; //
            this->textBox17->Text = "Wpisz nazwisko"; //
            this->textBox17->ForeColor = System::Drawing::Color::Gray; //
            this->textBox18->Text = "Wpisz imie"; //
            this->textBox18->ForeColor = System::Drawing::Color::Gray; //
        }

    protected:
        ~Formularz_paczki()
        {
            if (components)
            {
                delete components;
            }
        }

        // Deklaracje kontrolek (pól klasy) - upewnij siê, ¿e s¹ tutaj
    private: System::Windows::Forms::Label^ label1;
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
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Button^ button1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            // Ca³a Twoja oryginalna metoda InitializeComponent powinna byæ tutaj.
            // To ona zawiera np. this->textBox8->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox8_Leave);
            // Upewnij siê, ¿e jest kompletna i poprawna.
            // Poni¿ej jest tylko przyk³ad struktury, skopiuj swoj¹ metodê.
            // (Jeœli u¿ywasz projektanta, ten kod jest zarz¹dzany przez niego,
            // ale metody obs³ugi zdarzeñ musz¹ byæ zdefiniowane w klasie)

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
            this->label1->Click += gcnew System::EventHandler(this, &Formularz_paczki::label1_Click); // Metoda label1_Click musi istnieæ
            //
            // textBox1
            //
            this->textBox1->Location = System::Drawing::Point(27, 96);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(100, 20);
            this->textBox1->TabIndex = 1;
            this->textBox1->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox1_Enter); // Metoda textBox1_Enter musi istnieæ
            this->textBox1->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox1_Leave); // Metoda textBox1_Leave musi istnieæ
            //
            // textBox2
            //
            this->textBox2->Location = System::Drawing::Point(27, 122);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(100, 20);
            this->textBox2->TabIndex = 2;
            this->textBox2->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox2_Enter); // ... i tak dalej dla wszystkich
            this->textBox2->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox2_Leave); //
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(496, 647);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 20; // Upewnij siê, ¿e TabIndex jest unikalny i poprawny
            this->button1->Text = L"Zakoñcz";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Formularz_paczki::button1_Click); // Metoda button1_Click musi istnieæ
            //
            // textBox3
            //
            this->textBox3->Location = System::Drawing::Point(27, 148);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(100, 20);
            this->textBox3->TabIndex = 3;
            this->textBox3->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox3_Enter);
            this->textBox3->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox3_Leave);
            //
            // textBox4
            //
            this->textBox4->Location = System::Drawing::Point(27, 174);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(100, 20);
            this->textBox4->TabIndex = 4;
            this->textBox4->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_Enter);
            this->textBox4->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_Leave);
            //
            // textBox5
            //
            this->textBox5->Location = System::Drawing::Point(27, 200);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(100, 20);
            this->textBox5->TabIndex = 5;
            this->textBox5->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox5_Enter);
            this->textBox5->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox5_Leave);
            //
            // textBox6
            //
            this->textBox6->Location = System::Drawing::Point(27, 226);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(100, 20);
            this->textBox6->TabIndex = 6;
            this->textBox6->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox6_Enter);
            this->textBox6->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox6_Leave);
            //
            // textBox7
            //
            this->textBox7->Location = System::Drawing::Point(27, 252);
            this->textBox7->Name = L"textBox7";
            this->textBox7->Size = System::Drawing::Size(100, 20);
            this->textBox7->TabIndex = 7;
            this->textBox7->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox7_Enter);
            this->textBox7->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox7_Leave);
            //
            // textBox8
            //
            this->textBox8->Location = System::Drawing::Point(27, 278);
            this->textBox8->Name = L"textBox8";
            this->textBox8->Size = System::Drawing::Size(100, 20);
            this->textBox8->TabIndex = 8;
            this->textBox8->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox8_Enter);
            this->textBox8->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox8_Leave); // B³¹d dotyczy³ tej metody
            //
            // textBox9
            //
            this->textBox9->Location = System::Drawing::Point(27, 304);
            this->textBox9->Name = L"textBox9";
            this->textBox9->Size = System::Drawing::Size(100, 20);
            this->textBox9->TabIndex = 9;
            this->textBox9->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox9_Enter);
            this->textBox9->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox9_Leave);
            //
            // textBox10
            //
            this->textBox10->Location = System::Drawing::Point(414, 304);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(100, 20);
            this->textBox10->TabIndex = 19;
            this->textBox10->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox10_Enter);
            this->textBox10->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox10_Leave);
            //
            // textBox11
            //
            this->textBox11->Location = System::Drawing::Point(414, 278);
            this->textBox11->Name = L"textBox11";
            this->textBox11->Size = System::Drawing::Size(100, 20);
            this->textBox11->TabIndex = 18;
            this->textBox11->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox11_Enter);
            this->textBox11->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox11_Leave);
            //
            // textBox12
            //
            this->textBox12->Location = System::Drawing::Point(414, 252);
            this->textBox12->Name = L"textBox12";
            this->textBox12->Size = System::Drawing::Size(100, 20);
            this->textBox12->TabIndex = 17;
            this->textBox12->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox12_Enter);
            this->textBox12->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox12_Leave);
            //
            // textBox13
            //
            this->textBox13->Location = System::Drawing::Point(414, 226);
            this->textBox13->Name = L"textBox13";
            this->textBox13->Size = System::Drawing::Size(100, 20);
            this->textBox13->TabIndex = 16;
            this->textBox13->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox13_Enter);
            this->textBox13->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox13_Leave);
            //
            // textBox14
            //
            this->textBox14->Location = System::Drawing::Point(414, 200);
            this->textBox14->Name = L"textBox14";
            this->textBox14->Size = System::Drawing::Size(100, 20);
            this->textBox14->TabIndex = 15;
            this->textBox14->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox14_Enter);
            this->textBox14->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox14_Leave);
            //
            // textBox15
            //
            this->textBox15->Location = System::Drawing::Point(414, 174);
            this->textBox15->Name = L"textBox15";
            this->textBox15->Size = System::Drawing::Size(100, 20);
            this->textBox15->TabIndex = 14;
            this->textBox15->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox15_Enter);
            this->textBox15->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox15_Leave);
            //
            // textBox16
            //
            this->textBox16->Location = System::Drawing::Point(414, 148);
            this->textBox16->Name = L"textBox16";
            this->textBox16->Size = System::Drawing::Size(100, 20);
            this->textBox16->TabIndex = 13;
            this->textBox16->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox16_Enter);
            this->textBox16->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox16_Leave);
            //
            // textBox17
            //
            this->textBox17->Location = System::Drawing::Point(414, 122);
            this->textBox17->Name = L"textBox17";
            this->textBox17->Size = System::Drawing::Size(100, 20);
            this->textBox17->TabIndex = 12;
            this->textBox17->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox17_Enter);
            this->textBox17->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox17_Leave);
            //
            // textBox18
            //
            this->textBox18->Location = System::Drawing::Point(414, 96);
            this->textBox18->Name = L"textBox18";
            this->textBox18->Size = System::Drawing::Size(100, 20);
            this->textBox18->TabIndex = 11;
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
            this->label2->Click += gcnew System::EventHandler(this, &Formularz_paczki::label2_Click); // Metoda label2_Click musi istnieæ
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
            this->Load += gcnew System::EventHandler(this, &Formularz_paczki::Formularz_paczki_Load); // Metoda Formularz_paczki_Load musi istnieæ
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

        // --- POCZ¥TEK DEFINICJI METOD OBS£UGI ZDARZEÑ ---
        // Upewnij siê, ¿e wszystkie te metody s¹ tutaj, WEWN¥TRZ klasy Formularz_paczki

    private: System::Void Formularz_paczki_Load(System::Object^ sender, System::EventArgs^ e) {
        this->label1->Focus();
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Pusta, jeœli nie ma logiki
    }
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
        // Pusta, jeœli nie ma logiki
    }

           // Metody Enter/Leave dla textBox1
    private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox1->Text == "Wpisz imie") {
            this->textBox1->Text = "";
            this->textBox1->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox1->Text)) {
            this->textBox1->Text = "Wpisz imie";
            this->textBox1->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox2
    private: System::Void textBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox2->Text == "Wpisz nazwisko") {
            this->textBox2->Text = "";
            this->textBox2->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox2_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox2->Text)) {
            this->textBox2->Text = "Wpisz nazwisko";
            this->textBox2->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox3
    private: System::Void textBox3_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox3->Text == "Wpisz telefon") {
            this->textBox3->Text = "";
            this->textBox3->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox3_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox3->Text)) {
            this->textBox3->Text = "Wpisz telefon";
            this->textBox3->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox4
    private: System::Void textBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox4->Text == "Wpisz email") {
            this->textBox4->Text = "";
            this->textBox4->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox4_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox4->Text)) {
            this->textBox4->Text = "Wpisz email";
            this->textBox4->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox5
    private: System::Void textBox5_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox5->Text == "Wpisz ulice") {
            this->textBox5->Text = "";
            this->textBox5->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox5_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox5->Text)) {
            this->textBox5->Text = "Wpisz ulice";
            this->textBox5->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox6
    private: System::Void textBox6_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox6->Text == "Wpisz miasto") {
            this->textBox6->Text = "";
            this->textBox6->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox6_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox6->Text)) {
            this->textBox6->Text = "Wpisz miasto";
            this->textBox6->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox7
    private: System::Void textBox7_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox7->Text == "Wpisz wojewodztwo") {
            this->textBox7->Text = "";
            this->textBox7->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox7_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox7->Text)) {
            this->textBox7->Text = "Wpisz wojewodztwo";
            this->textBox7->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox8 (Twój b³¹d dotyczy³ textBox8_Leave)
    private: System::Void textBox8_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox8->Text == "Wpisz kodPocztowy") {
            this->textBox8->Text = "";
            this->textBox8->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox8_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox8->Text)) {
            this->textBox8->Text = "Wpisz kodPocztowy";
            this->textBox8->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox9
    private: System::Void textBox9_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox9->Text == "Wpisz kraj") {
            this->textBox9->Text = "";
            this->textBox9->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox9_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox9->Text)) {
            this->textBox9->Text = "Wpisz kraj";
            this->textBox9->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox10 (Odbiorca)
    private: System::Void textBox10_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox10->Text == "Wpisz kraj") {
            this->textBox10->Text = "";
            this->textBox10->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox10_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox10->Text)) {
            this->textBox10->Text = "Wpisz kraj";
            this->textBox10->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox11
    private: System::Void textBox11_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox11->Text == "Wpisz kodPocztowy") {
            this->textBox11->Text = "";
            this->textBox11->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox11_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox11->Text)) {
            this->textBox11->Text = "Wpisz kodPocztowy";
            this->textBox11->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox12
    private: System::Void textBox12_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox12->Text == "Wpisz wojewodztwo") {
            this->textBox12->Text = "";
            this->textBox12->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox12_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox12->Text)) {
            this->textBox12->Text = "Wpisz wojewodztwo";
            this->textBox12->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox13
    private: System::Void textBox13_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox13->Text == "Wpisz miasto") {
            this->textBox13->Text = "";
            this->textBox13->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox13_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox13->Text)) {
            this->textBox13->Text = "Wpisz miasto";
            this->textBox13->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox14
    private: System::Void textBox14_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox14->Text == "Wpisz ulice") {
            this->textBox14->Text = "";
            this->textBox14->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox14_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox14->Text)) {
            this->textBox14->Text = "Wpisz ulice";
            this->textBox14->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox15
    private: System::Void textBox15_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox15->Text == "Wpisz email") {
            this->textBox15->Text = "";
            this->textBox15->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox15_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox15->Text)) {
            this->textBox15->Text = "Wpisz email";
            this->textBox15->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox16
    private: System::Void textBox16_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox16->Text == "Wpisz telefon") {
            this->textBox16->Text = "";
            this->textBox16->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox16_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox16->Text)) {
            this->textBox16->Text = "Wpisz telefon";
            this->textBox16->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox17
    private: System::Void textBox17_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox17->Text == "Wpisz nazwisko") {
            this->textBox17->Text = "";
            this->textBox17->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox17_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox17->Text)) {
            this->textBox17->Text = "Wpisz nazwisko";
            this->textBox17->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metody Enter/Leave dla textBox18
    private: System::Void textBox18_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->textBox18->Text == "Wpisz imie") {
            this->textBox18->Text = "";
            this->textBox18->ForeColor = System::Drawing::Color::Black;
        }
    }
    private: System::Void textBox18_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(this->textBox18->Text)) {
            this->textBox18->Text = "Wpisz imie";
            this->textBox18->ForeColor = System::Drawing::Color::Gray;
        }
    }

           // Metoda button1_Click (z poprzedniej odpowiedzi, z logik¹ JSON)
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Konwersja System::String na std::string
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
        odbiorca.ulica = ulicaOdbiorcy;
        odbiorca.miasto = miastoOdbiorcy;
        odbiorca.wojewodztwo = wojewodztwoOdbiorcy;
        odbiorca.kodPocztowy = kodPocztowyOdbiorcy;
        odbiorca.kraj = krajOdbiorcy;

<<<<<<<<< Temporary merge branch 1
		// Typ Paczki
		TypPaczki typPaczki;
		if (comboBox1->SelectedIndex == 0) {
			typPaczki = TypPaczki::List;
		}
		else if (comboBox1->SelectedIndex == 1) {
			typPaczki = TypPaczki::Paczka;
		}
		else if (comboBox1->SelectedIndex == 2) {
			typPaczki = TypPaczki::Paleta;
		}

		// Tworzenie obiektu Paczka z referencjami do nadawcy i odbiorcy
		Paczka paczka(nadawca, odbiorca, typPaczki);
=========
        // Tworzenie obiektu Paczka z referencjami do nadawcy i odbiorcy
        Paczka paczka(nadawca, odbiorca);
>>>>>>>>> Temporary merge branch 2
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

        Paczka paczka(nadawcaObj, odbiorcaObj); //

        nlohmann::json new_package_json;
        new_package_json["numerPaczki"] = paczka.getNumerPaczki(); //
        new_package_json["nadawca"] = { //
            {"imie", paczka.getNadawca().imie}, //
            {"nazwisko", paczka.getNadawca().nazwisko}, //
            {"telefon", paczka.getNadawca().telefon}, //
            {"email", paczka.getNadawca().email}, //
            {"adres", { //
                {"ulica", paczka.getNadawca().ulica}, //
                {"miasto", paczka.getNadawca().miasto}, //
                {"wojewodztwo", paczka.getNadawca().wojewodztwo}, //
                {"kodPocztowy", paczka.getNadawca().kodPocztowy}, //
                {"kraj", paczka.getNadawca().kraj} //
            }}
        };
        new_package_json["odbiorca"] = { //
            {"imie", paczka.getOdbiorca().imie}, //
            {"nazwisko", paczka.getOdbiorca().nazwisko}, //
            {"telefon", paczka.getOdbiorca().telefon}, //
            {"email", paczka.getOdbiorca().email}, //
            {"adres", { //
                {"ulica", paczka.getOdbiorca().ulica}, //
                {"miasto", paczka.getOdbiorca().miasto}, //
                {"wojewodztwo", paczka.getOdbiorca().wojewodztwo}, //
                {"kodPocztowy", paczka.getOdbiorca().kodPocztowy}, //
                {"kraj", paczka.getOdbiorca().kraj} //
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
        // *** END JSON Serialization and File Save ***

        this->Close();
        paczka.paczkaPrzyjeta();
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
           // Removed all these TextChanged methods as they are not used and cause compilation errors.
           // If you intended to have TextChanged logic for these textboxes, you would need to implement them.
           /*
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
           */
>>>>>>>>> Temporary merge branch 2
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
           /*
           private: System::Void textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e) {
           }
           private: System::Void textBox12_TextChanged(System::Object^ sender, System::EventArgs^ e) {
           }
           private: System::Void textBox13_TextChanged(System::Object^ sender, System::EventArgs^ e) {
           }
           private: System::Void textBox14_TextChanged(System::Object^ sender, System::EventArgs^ e) {
           }
           private: System::Void textBox15_TextChanged(System::Object^ sender, System::EventArgs^ e) {
           }
           private: System::Void textBox16_TextChanged(System::Object^ sender, System::EventArgs^ e) {
           }
           private: System::Void textBox17_TextChanged(System::Object^ sender, System::EventArgs^ e) {
           }
           private: System::Void textBox18_TextChanged(System::Object^ sender, System::EventArgs^ e) {
           }
           */
    };
<<<<<<<<< Temporary merge branch 1
}
>>>>>>>>> Temporary merge branch 2
=========
}
>>>>>>>>> Temporary merge branch 2
