#include "SplashScreen.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace PSiO;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    //--[IMPROVEMENT: Splash Screen]--
    // Poka¿ formularz ekranu startowego (splash screen)
    SplashScreen^ splash = gcnew SplashScreen();
    splash->ShowDialog(); // U¿yj ShowDialog, aby zablokowaæ dalsze wykonanie do zamkniêcia

    // Po zamkniêciu splash screen, poka¿ g³ówny formularz
    MyForm^ mainForm = gcnew MyForm();
    Application::Run(mainForm);

    return 0;
}