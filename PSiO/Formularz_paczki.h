#pragma once
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "Klasy.h"

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
			this->textBox1->Text = "Wpisz imie";
			this->textBox1->ForeColor = System::Drawing::Color::Gray;
			this->textBox2->Text = "Wpisz nazwisko";
			this->textBox2->ForeColor = System::Drawing::Color::Gray;
			this->textBox3->Text = "Wpisz telefon";
			this->textBox3->ForeColor = System::Drawing::Color::Gray;
			this->textBox4->Text = "Wpisz email";
			this->textBox4->ForeColor = System::Drawing::Color::Gray;
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
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
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
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox3_TextChanged);
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
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_TextChanged);
			this->textBox4->Enter += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_Enter);
			this->textBox4->Leave += gcnew System::EventHandler(this, &Formularz_paczki::textBox4_Leave);
			// 
			// Formularz_paczki
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(583, 682);
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

		}
#pragma endregion
	private: System::Void Formularz_paczki_Load(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Focus();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
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

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string imie = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string nazwisko = msclr::interop::marshal_as<std::string>(textBox2->Text);
		std::string telefon = msclr::interop::marshal_as<std::string>(textBox3->Text);
		std::string email = msclr::interop::marshal_as<std::string>(textBox4->Text);

		// Tworzenie obiektu Nadawca i ustawianie imienia
		Nadawca nadawca;
		nadawca.imie = imie;
		nadawca.nazwisko = nazwisko;
		nadawca.telefon = telefon;
		nadawca.email = email;

		// Tworzenie obiektu Odbiorca
		Odbiorca odbiorca;

		// Tworzenie obiektu Paczka z referencjami do nadawcy i odbiorcy
		Paczka paczka(nadawca, odbiorca);

		this->Close();
		paczka.paczkaPrzyjeta();
	}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
