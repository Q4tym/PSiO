#pragma once
#include "logowanie.h"
#include "Formularz_paczki.h"

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonLogin;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Button^ buttonNewPackage;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->buttonLogin = (gcnew System::Windows::Forms::Button());
			   this->buttonExit = (gcnew System::Windows::Forms::Button());
			   this->buttonNewPackage = (gcnew System::Windows::Forms::Button());
			   this->labelTitle = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // buttonLogin
			   // 
			   this->buttonLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			   this->buttonLogin->FlatAppearance->BorderSize = 0;
			   this->buttonLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			   this->buttonLogin->ForeColor = System::Drawing::Color::White;
			   this->buttonLogin->Location = System::Drawing::Point(93, 170);
			   this->buttonLogin->Name = L"buttonLogin";
			   this->buttonLogin->Size = System::Drawing::Size(250, 50);
			   this->buttonLogin->TabIndex = 1;
			   this->buttonLogin->Text = L"PANEL KURIERA";
			   this->buttonLogin->UseVisualStyleBackColor = false;
			   this->buttonLogin->Click += gcnew System::EventHandler(this, &MyForm::buttonLogin_Click);
			   this->buttonLogin->MouseEnter += gcnew System::EventHandler(this, &MyForm::button_MouseEnter);
			   this->buttonLogin->MouseLeave += gcnew System::EventHandler(this, &MyForm::button_MouseLeave);
			   // 
			   // buttonExit
			   // 
			   this->buttonExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			   this->buttonExit->FlatAppearance->BorderSize = 0;
			   this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonExit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			   this->buttonExit->ForeColor = System::Drawing::Color::White;
			   this->buttonExit->Location = System::Drawing::Point(93, 230);
			   this->buttonExit->Name = L"buttonExit";
			   this->buttonExit->Size = System::Drawing::Size(250, 35);
			   this->buttonExit->TabIndex = 2;
			   this->buttonExit->Text = L"Zakoñcz";
			   this->buttonExit->UseVisualStyleBackColor = false;
			   this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Click);
			   this->buttonExit->MouseEnter += gcnew System::EventHandler(this, &MyForm::button_MouseEnter_Gray);
			   this->buttonExit->MouseLeave += gcnew System::EventHandler(this, &MyForm::button_MouseLeave_Gray);
			   // 
			   // buttonNewPackage
			   // 
			   this->buttonNewPackage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			   this->buttonNewPackage->FlatAppearance->BorderSize = 0;
			   this->buttonNewPackage->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonNewPackage->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			   this->buttonNewPackage->ForeColor = System::Drawing::Color::White;
			   this->buttonNewPackage->Location = System::Drawing::Point(93, 110);
			   this->buttonNewPackage->Name = L"buttonNewPackage";
			   this->buttonNewPackage->Size = System::Drawing::Size(250, 50);
			   this->buttonNewPackage->TabIndex = 0;
			   this->buttonNewPackage->Text = L"NADAJ PACZKÊ";
			   this->buttonNewPackage->UseVisualStyleBackColor = false;
			   this->buttonNewPackage->Click += gcnew System::EventHandler(this, &MyForm::buttonNewPackage_Click);
			   this->buttonNewPackage->MouseEnter += gcnew System::EventHandler(this, &MyForm::button_MouseEnter);
			   this->buttonNewPackage->MouseLeave += gcnew System::EventHandler(this, &MyForm::button_MouseLeave);
			   // 
			   // labelTitle
			   // 
			   this->labelTitle->AutoSize = true;
			   this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			   this->labelTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			   this->labelTitle->Location = System::Drawing::Point(40, 30);
			   this->labelTitle->Name = L"labelTitle";
			   this->labelTitle->Size = System::Drawing::Size(356, 45);
			   this->labelTitle->TabIndex = 3;
			   this->labelTitle->Text = L"SYSTEM KURIERSKI";
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->ClientSize = System::Drawing::Size(434, 311);
			   this->Controls->Add(this->labelTitle);
			   this->Controls->Add(this->buttonNewPackage);
			   this->Controls->Add(this->buttonExit);
			   this->Controls->Add(this->buttonLogin);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->MaximizeBox = false;
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"System Kurierski";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ loginForm = gcnew MyForm1();
		loginForm->ShowDialog(this);
	}
	private: System::Void buttonNewPackage_Click(System::Object^ sender, System::EventArgs^ e) {
		Formularz_paczki^ formularz = gcnew Formularz_paczki();
		formularz->ShowDialog(this);
	}
	private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Czy na pewno chcesz zamkn¹æ aplikacjê?", "Potwierdzenie Wyjœcia", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			Application::Exit();
		}
	}

	private: System::Void button_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast<Button^>(sender);
		button->BackColor = Color::FromArgb(0, 142, 224);
	}
	private: System::Void button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast<Button^>(sender);
		button->BackColor = Color::FromArgb(0, 122, 204);
	}
	private: System::Void button_MouseEnter_Gray(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast<Button^>(sender);
		button->BackColor = Color::FromArgb(80, 80, 80);
	}
	private: System::Void button_MouseLeave_Gray(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast<Button^>(sender);
		button->BackColor = Color::FromArgb(50, 50, 50);
	}
	};
}