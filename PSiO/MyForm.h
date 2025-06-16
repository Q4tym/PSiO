#pragma once
#include "logowanie.h"
#include "Formularz_paczki.h"

namespace PSiO {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm(void) {
			InitializeComponent();
		}
	protected:
		~MyForm() {
			if (components) {
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
			   this->buttonLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			   this->buttonLogin->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			   this->buttonLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			   this->buttonLogin->ForeColor = System::Drawing::Color::White;
			   this->buttonLogin->Location = System::Drawing::Point(72, 149);
			   this->buttonLogin->Name = L"buttonLogin";
			   this->buttonLogin->Size = System::Drawing::Size(290, 45);
			   this->buttonLogin->TabIndex = 1;
			   this->buttonLogin->Text = L"🚚 Panel kuriera";
			   this->buttonLogin->UseVisualStyleBackColor = false;
			   this->buttonLogin->Click += gcnew System::EventHandler(this, &MyForm::buttonLogin_Click);
			   // 
			   // buttonExit
			   // 
			   this->buttonExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			   this->buttonExit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			   this->buttonExit->FlatAppearance->BorderColor = System::Drawing::Color::Gray;
			   this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonExit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			   this->buttonExit->ForeColor = System::Drawing::Color::White;
			   this->buttonExit->Location = System::Drawing::Point(72, 210);
			   this->buttonExit->Name = L"buttonExit";
			   this->buttonExit->Size = System::Drawing::Size(290, 35);
			   this->buttonExit->TabIndex = 2;
			   this->buttonExit->Text = L"🚪 Wyjdź";
			   this->buttonExit->UseVisualStyleBackColor = false;
			   this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Click);
			   // 
			   // buttonNewPackage
			   // 
			   this->buttonNewPackage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			   this->buttonNewPackage->FlatAppearance->BorderSize = 0;
			   this->buttonNewPackage->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonNewPackage->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			   this->buttonNewPackage->ForeColor = System::Drawing::Color::White;
			   this->buttonNewPackage->Location = System::Drawing::Point(72, 88);
			   this->buttonNewPackage->Name = L"buttonNewPackage";
			   this->buttonNewPackage->Size = System::Drawing::Size(290, 45);
			   this->buttonNewPackage->TabIndex = 0;
			   this->buttonNewPackage->Text = L"✉️ Nadaj nową paczkę";
			   this->buttonNewPackage->UseVisualStyleBackColor = false;
			   this->buttonNewPackage->Click += gcnew System::EventHandler(this, &MyForm::buttonNewPackage_Click);
			   // 
			   // labelTitle
			   // 
			   this->labelTitle->AutoSize = true;
			   this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			   this->labelTitle->ForeColor = System::Drawing::Color::White;
			   this->labelTitle->Location = System::Drawing::Point(90, 25);
			   this->labelTitle->Name = L"labelTitle";
			   this->labelTitle->Size = System::Drawing::Size(258, 37);
			   this->labelTitle->TabIndex = 4;
			   this->labelTitle->Text = L"SYSTEM KURIERSKI";
			   // 
			   // MyForm
			   // 
			   this->AcceptButton = this->buttonNewPackage;
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->CancelButton = this->buttonExit;
			   this->ClientSize = System::Drawing::Size(434, 281);
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
	private:
		System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
			MyForm1^ loginForm = gcnew MyForm1();
			if (loginForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) {
				Formularz_Kuriera^ courierForm = gcnew Formularz_Kuriera();
				courierForm->Show();
			}
		}
		System::Void buttonNewPackage_Click(System::Object^ sender, System::EventArgs^ e) {
			Formularz_paczki^ formularz = gcnew Formularz_paczki();
			formularz->ShowDialog(this);
		}
		System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}