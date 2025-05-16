#include "MyForm.h"
#include "Klasy.h"
#include "Formularz_paczki.h"

[System::STAThread]
int Main()
{
	// Inicjalizacja aplikacji
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	// Tworzenie i uruchamianie g³ównego formularza
	PSiO::MyForm ^ form = gcnew PSiO::MyForm();
	System::Windows::Forms::Application::Run(form);
	

	//Sortownia sortownia;

	return 0;
}