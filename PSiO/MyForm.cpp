#include "MyForm.h" // Główny formularz aplikacji
// #include "Klasy.h" // Jeśli Klasy.h są potrzebne bezpośrednio w Main(), np. do inicjalizacji
// #include "Formularz_paczki.h" // Jeśli Formularz_paczki jest tworzony bezpośrednio w Main()
// Poniższe nagłówki marshal są często potrzebne w plikach .cpp z Main() w projektach C++/CLI,
// ale nie są bezpośrednio używane w tej minimalnej funkcji Main().
// #include <msclr/marshal.h>
// #include <msclr/marshal_cppstd.h>

// Główna funkcja aplikacji
[System::STAThreadAttribute] // Atrybut wymagany dla aplikacji Windows Forms
int Main(array<System::String^>^ args) // Standardowa sygnatura Main dla aplikacji .NET
{
    // Włączenie stylów wizualnych Windows
    System::Windows::Forms::Application::EnableVisualStyles();
    // Ustawienie domyślnego renderowania tekstu kompatybilnego z GDI+
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    // Tworzenie i uruchamianie głównego formularza aplikacji
    // MyForm jest zdefiniowany w MyForm.h i należy do przestrzeni nazw PSiO
    PSiO::MyForm^ form = gcnew PSiO::MyForm();
    System::Windows::Forms::Application::Run(form);

    // Zakomentowana linia, Sortownia nie jest tu używana
    // Sortownia sortownia; 

    return 0; // Zakończenie aplikacji
}