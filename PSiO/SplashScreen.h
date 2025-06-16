#pragma once

namespace PSiO {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class SplashScreen : public Form {
    public:
        SplashScreen(void) {
            InitializeComponent();
            this->timer->Start();
        }

    protected:
        ~SplashScreen() {
            if (components) {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Timer^ timer;
        System::Windows::Forms::ProgressBar^ progressBar;
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::Label^ labelLoading;

        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            this->timer = (gcnew System::Windows::Forms::Timer(this->components));
            this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
            this->labelTitle = (gcnew System::Windows::Forms::Label());
            this->labelLoading = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();

            this->timer->Interval = 30;
            this->timer->Tick += gcnew System::EventHandler(this, &SplashScreen::timer_Tick);

            this->progressBar->Location = System::Drawing::Point(37, 160);
            this->progressBar->Name = L"progressBar";
            this->progressBar->Size = System::Drawing::Size(426, 15);
            this->progressBar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;

            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->labelTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->labelTitle->Location = System::Drawing::Point(85, 60);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = System::Drawing::Size(349, 50);
            this->labelTitle->TabIndex = 1;
            this->labelTitle->Text = L"SYSTEM KURIERSKI";

            this->labelLoading->AutoSize = true;
            this->labelLoading->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->labelLoading->ForeColor = System::Drawing::Color::White;
            this->labelLoading->Location = System::Drawing::Point(34, 137);
            this->labelLoading->Name = L"labelLoading";
            this->labelLoading->Size = System::Drawing::Size(91, 17);
            this->labelLoading->TabIndex = 2;
            this->labelLoading->Text = L"£adowanie...";

            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->ClientSize = System::Drawing::Size(500, 220);
            this->Controls->Add(this->labelLoading);
            this->Controls->Add(this->labelTitle);
            this->Controls->Add(this->progressBar);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"SplashScreen";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"SplashScreen";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
            if (this->progressBar->Value < 100) {
                this->progressBar->Value += 2;
            }
            else {
                this->timer->Stop();
                this->Close();
            }
        }
    };
}