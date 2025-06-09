#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <streambuf>

#include "json.hpp"
#include "Utils.h" // Używamy centralnej funkcji toStdString
#include "Formularz_Kuriera.h"

// Removed #include <Microsoft.VisualBasic.dll> - replaced by custom input dialog

namespace PSiO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Custom InputDialog for password input instead of Microsoft.VisualBasic::Interaction::InputBox
	public ref class InputDialog : public Form {
	public:
		InputDialog(String^ prompt) {
			this->Text = L"Wymagana Autoryzacja";
			this->Size = System::Drawing::Size(320, 150);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->StartPosition = FormStartPosition::CenterParent;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->ShowInTaskbar = false;

			Label^ label = gcnew Label();
			label->Text = prompt;
			label->Location = System::Drawing::Point(10, 10);
			label->Size = System::Drawing::Size(300, 30);
			this->Controls->Add(label);

			textBox = gcnew TextBox();
			textBox->Location = System::Drawing::Point(10, 40);
			textBox->Size = System::Drawing::Size(280, 25);
			textBox->UseSystemPasswordChar = true;
			this->Controls->Add(textBox);

			Button^ buttonOk = gcnew Button();
			buttonOk->Text = "OK";
			buttonOk->DialogResult = System::Windows::Forms::DialogResult::OK;
			buttonOk->Location = System::Drawing::Point(10, 75);
			this->Controls->Add(buttonOk);

			this->AcceptButton = buttonOk;

			Button^ buttonCancel = gcnew Button();
			buttonCancel->Text = "Anuluj";
			buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			buttonCancel->Location = System::Drawing::Point(100, 75);
			this->Controls->Add(buttonCancel);

			this->CancelButton = buttonCancel;
		}

		String^ GetInput() {
			return textBox->Text;
		}

	private:
		TextBox^ textBox;
	};

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			this->textBoxPassword->PasswordChar = '*';
			this->couriersFilename = "kurierzy.json";
			this->adminPassword = "admin"; // Hasło administratora
			this->labelStatus->Text = "";
		}

	protected:
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::String^ couriersFilename;
		System::String^ adminPassword;
		System::Windows::Forms::Label^ labelUsername;
		System::Windows::Forms::TextBox^ textBoxUsername;
		System::Windows::Forms::Label^ labelPassword;
		System::Windows::Forms::TextBox^ textBoxPassword;
		System::Windows::Forms::Button^ buttonLoginCourier;
		System::Windows::Forms::Button^ buttonRegisterCourier;
		System::Windows::Forms::Label^ labelStatus;
		System::Windows::Forms::Panel^ panelUsername;
		System::Windows::Forms::Panel^ panelPassword;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonLoginCourier = (gcnew System::Windows::Forms::Button());
			this->buttonRegisterCourier = (gcnew System::Windows::Forms::Button());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->panelUsername = (gcnew System::Windows::Forms::Panel());
			this->panelPassword = (gcnew System::Windows::Forms::Panel());
			this->panelUsername->SuspendLayout();
			this->panelPassword->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelUsername
			// 
			this->labelUsername->AutoSize = true;
			this->labelUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelUsername->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelUsername->Location = System::Drawing::Point(30, 30);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(124, 17);
			this->labelUsername->TabIndex = 0;
			this->labelUsername->Text = L"Nazwa użytkownika:";
			// 
			// panelUsername
			// 
			this->panelUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->panelUsername->Controls->Add(this->textBoxUsername);
			this->panelUsername->Location = System::Drawing::Point(33, 53);
			this->panelUsername->Name = L"panelUsername";
			this->panelUsername->Padding = System::Windows::Forms::Padding(1);
			this->panelUsername->Size = System::Drawing::Size(254, 28);
			this->panelUsername->TabIndex = 1;
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textBoxUsername->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxUsername->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textBoxUsername->ForeColor = System::Drawing::Color::White;
			this->textBoxUsername->Location = System::Drawing::Point(1, 1);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(252, 20);
			this->textBoxUsername->TabIndex = 1;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->labelPassword->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelPassword->Location = System::Drawing::Point(30, 95);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(44, 17);
			this->labelPassword->TabIndex = 2;
			this->labelPassword->Text = L"Hasło:";
			// 
			// panelPassword
			// 
			this->panelPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->panelPassword->Controls->Add(this->textBoxPassword);
			this->panelPassword->Location = System::Drawing::Point(33, 118);
			this->panelPassword->Name = L"panelPassword";
			this->panelPassword->Padding = System::Windows::Forms::Padding(1);
			this->panelPassword->Size = System::Drawing::Size(254, 28);
			this->panelPassword->TabIndex = 2;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxPassword->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F));
			this->textBoxPassword->ForeColor = System::Drawing::Color::White;
			this->textBoxPassword->Location = System::Drawing::Point(1, 1);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(252, 20);
			this->textBoxPassword->TabIndex = 2;
			// 
			// buttonLoginCourier
			// 
			this->buttonLoginCourier->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->buttonLoginCourier->FlatAppearance->BorderSize = 0;
			this->buttonLoginCourier->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLoginCourier->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			this->buttonLoginCourier->ForeColor = System::Drawing::Color::White;
			this->buttonLoginCourier->Location = System::Drawing::Point(33, 165);
			this->buttonLoginCourier->Name = L"buttonLoginCourier";
			this->buttonLoginCourier->Size = System::Drawing::Size(120, 35);
			this->buttonLoginCourier->TabIndex = 3;
			this->buttonLoginCourier->Text = L"Zaloguj";
			this->buttonLoginCourier->UseVisualStyleBackColor = false;
			this->buttonLoginCourier->Click += gcnew System::EventHandler(this, &MyForm1::buttonLoginCourier_Click);
			// 
			// buttonRegisterCourier
			// 
			this->buttonRegisterCourier->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->buttonRegisterCourier->FlatAppearance->BorderSize = 0;
			this->buttonRegisterCourier->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonRegisterCourier->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
			this->buttonRegisterCourier->ForeColor = System::Drawing::Color::White;
			this->buttonRegisterCourier->Location = System::Drawing::Point(167, 165);
			this->buttonRegisterCourier->Name = L"buttonRegisterCourier";
			this->buttonRegisterCourier->Size = System::Drawing::Size(120, 35);
			this->buttonRegisterCourier->TabIndex = 4;
			this->buttonRegisterCourier->Text = L"Rejestruj";
			this->buttonRegisterCourier->UseVisualStyleBackColor = false;
			this->buttonRegisterCourier->Click += gcnew System::EventHandler(this, &MyForm1::buttonRegisterCourier_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelStatus->ForeColor = System::Drawing::Color::White;
			this->labelStatus->Location = System::Drawing::Point(30, 215);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 15);
			this->labelStatus->MinimumSize = System::Drawing::Size(260, 0);
			this->labelStatus->TabIndex = 5;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(320, 250);
			this->Controls->Add(this->panelPassword);
			this->Controls->Add(this->panelUsername);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->buttonRegisterCourier);
			this->Controls->Add(this->buttonLoginCourier);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->labelUsername);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Logowanie / Rejestracja Kuriera";
			this->panelUsername->ResumeLayout(false);
			this->panelUsername->PerformLayout();
			this->panelPassword->ResumeLayout(false);
			this->panelPassword->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		nlohmann::json readCouriersFile() {
			std::string fileNameStd = toStdString(this->couriersFilename);
			std::ifstream ifs(fileNameStd);
			if (!ifs.is_open()) {
				return nlohmann::json::array();
			}
			std::string content((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
			ifs.close();
			if (content.empty()) {
				return nlohmann::json::array();
			}
			try {
				nlohmann::json data = nlohmann::json::parse(content);
				return data.is_array() ? data : nlohmann::json::array();
			}
			catch (nlohmann::json::parse_error&) {
				return nlohmann::json::array();
			}
		}

		bool writeCouriersFile(const nlohmann::json& couriers_json_array) {
			std::string fileNameStd = toStdString(this->couriersFilename);
			std::ofstream ofs(fileNameStd);
			if (ofs.is_open()) {
				ofs << std::setw(4) << couriers_json_array << std::endl;
				ofs.close();
				return true;
			}
			return false;
		}

		System::Void buttonRegisterCourier_Click(System::Object^ sender, System::EventArgs^ e) {
			InputDialog^ inputDialog = gcnew InputDialog("Podaj hasło administratora, aby zarejestrować nowego kuriera:");
			if (inputDialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
				return; // User cancelled
			}
			String^ inputPassword = inputDialog->GetInput();
			if (inputPassword != this->adminPassword) {
				MessageBox::Show("Błędne hasło administratora. Rejestracja anulowana.", "Błąd", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			std::string username = toStdString(this->textBoxUsername->Text);
			std::string password = toStdString(this->textBoxPassword->Text);

			if (username.empty() || password.empty()) {
				this->labelStatus->Text = "Nazwa i hasło nie mogą być puste.";
				this->labelStatus->ForeColor = Color::Red;
				return;
			}

			nlohmann::json couriers = readCouriersFile();
			for (const auto& courier : couriers) {
				if (courier.is_object() && courier.contains("username") && courier["username"] == username) {
					this->labelStatus->Text = "Ta nazwa użytkownika już istnieje.";
					this->labelStatus->ForeColor = Color::Red;
					return;
				}
			}

			couriers.push_back({ {"username", username}, {"password", password} });

			if (writeCouriersFile(couriers)) {
				this->labelStatus->Text = "Rejestracja zakończona pomyślnie.";
				this->labelStatus->ForeColor = Color::Green;
				this->textBoxUsername->Text = "";
				this->textBoxPassword->Text = "";
			}
			else {
				this->labelStatus->Text = "Błąd zapisu do pliku kurierów.";
				this->labelStatus->ForeColor = Color::Red;
			}
		}

		System::Void buttonLoginCourier_Click(System::Object^ sender, System::EventArgs^ e) {
			std::string username = toStdString(this->textBoxUsername->Text);
			std::string password = toStdString(this->textBoxPassword->Text);

			if (username.empty() || password.empty()) {
				this->labelStatus->Text = "Wprowadź nazwę użytkownika i hasło.";
				this->labelStatus->ForeColor = Color::Red;
				return;
			}

			nlohmann::json couriers = readCouriersFile();
			bool loggedIn = false;
			for (const auto& courier : couriers) {
				if (courier.is_object() && courier.contains("username") && courier.contains("password") &&
					courier["username"] == username && courier["password"] == password) {
					loggedIn = true;
					break;
				}
			}

			if (loggedIn) {
				this->labelStatus->Text = "Logowanie pomyślne!";
				this->labelStatus->ForeColor = Color::Green;
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Hide();
				Formularz_Kuriera^ kurierForm = gcnew Formularz_Kuriera();
				kurierForm->ShowDialog();
				this->Close();
			}
			else {
				this->labelStatus->Text = "Nieprawidłowa nazwa lub hasło.";
				this->labelStatus->ForeColor = Color::Red;
			}
		}
	};
}
