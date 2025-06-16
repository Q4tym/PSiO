#include "SplashScreen.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace PSiO;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SplashScreen^ splash = gcnew SplashScreen();
    splash->ShowDialog();

    MyForm^ mainForm = gcnew MyForm();
    Application::Run(mainForm);

    return 0;
}