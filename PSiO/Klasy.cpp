#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
// #include <Windows.h> // Usuniêto, jeœli MessageBox nie jest tu u¿ywany; System::String jest z .NET
#include "Klasy.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

// Definicja metody przyjmijPaczke dla klasy Sortownia
bool Sortownia::przyjmijPaczke()
{
    bool przyjmijPaczkeFlag = false; // Zmieniono nazwê zmiennej, aby unikn¹æ konfliktu z nazw¹ metody
    // Poni¿szy kod jest zakomentowany, bo interfejs u¿ytkownika powinien byæ w klasach Form
    // std::cout << "Czy chcesz przyjac paczke ? (1-tak, 0-nie): ";
    // int wybor;
    // std::cin >> wybor;
    // if (wybor == 1)
    // {
    //     przyjmijPaczkeFlag = true;
    //     std::cout << "Paczka przyjeta." << std::endl;
    // }
    // else
    // {
    //     przyjmijPaczkeFlag = false;
    //     std::cout << "Paczka nie zostala przyjeta." << std::endl;
    // }
    // Ta metoda w obecnej formie nie ma sensu bez interakcji,
    // mo¿na j¹ zostawiæ pust¹ lub z prostym logowaniem, jeœli jest wywo³ywana.
    std::cout << "Logika Sortownia::przyjmijPaczke() wymaga implementacji lub usuniêcia, jeœli nie jest u¿ywana." << std::endl;
    return przyjmijPaczkeFlag;
}

// Definicja metody sortujPaczki dla klasy Sortownia
void Sortownia::sortujPaczki()
{
    // Poni¿szy kod jest zakomentowany, bo interfejs u¿ytkownika powinien byæ w klasach Form
    // std::cout << "Sortuje paczki..." << std::endl;
    // Ta metoda w obecnej formie nie ma sensu bez interakcji,
    // mo¿na j¹ zostawiæ pust¹ lub z prostym logowaniem, jeœli jest wywo³ywana.
    std::cout << "Logika Sortownia::sortujPaczki() zosta³a wywo³ana." << std::endl;
}


// Definicja metody paczkaPrzyjeta dla klasy Paczka
void Paczka::paczkaPrzyjeta()
{
    std::stringstream ss;
    ss << "--- Potwierdzenie Nadania Paczki ---\n";
    ss << "Numer paczki: " << getNumerPaczki() << "\n\n";

    ss << "Nadawca:\n";
    ss << "  Imiê: " << nadawca.imie << "\n";
    ss << "  Nazwisko: " << nadawca.nazwisko << "\n";
    ss << "  Telefon: " << nadawca.telefon << "\n";
    ss << "  Email: " << nadawca.email << "\n";
    ss << "  Adres: " << nadawca.ulica << ", " << nadawca.kodPocztowy << " " << nadawca.miasto
        << ", " << nadawca.wojewodztwo << ", " << nadawca.kraj << "\n\n";

    ss << "Odbiorca:\n";
    ss << "  Imiê: " << odbiorca.imie << "\n";
    ss << "  Nazwisko: " << odbiorca.nazwisko << "\n";
    ss << "  Telefon: " << odbiorca.telefon << "\n";
    ss << "  Email: " << odbiorca.email << "\n";
    ss << "  Adres: " << odbiorca.ulica << ", " << odbiorca.kodPocztowy << " " << odbiorca.miasto
        << ", " << odbiorca.wojewodztwo << ", " << odbiorca.kraj << "\n";
    ss << "-------------------------------------\n";

    // Wypisanie na konsolê standardow¹ (mo¿na te¿ zapisaæ do pliku logu)
    std::cout << ss.str() << std::endl;

    // Jeœli chcesz wyœwietliæ to w oknie dialogowym (MessageBox), musisz to zrobiæ
    // z poziomu kodu formularza (C++/CLI), poniewa¿ Klasy.cpp jest standardowym C++.
    // Bezpoœrednie wywo³anie System::Windows::Forms::MessageBox z tego miejsca
    // bez odpowiedniej konfiguracji projektu dla C++/CLI mo¿e byæ problematyczne.
    // Przekazanie stringstream do formularza lub u¿ycie delegatów by³oby czystszym rozwi¹zaniem.

    // Przyk³ad, jak mo¿na by to zrobiæ, gdyby ta metoda by³a czêœci¹ formularza
    // lub mia³a dostêp do System::String i MessageBox:
    // System::String^ message = msclr::interop::marshal_as<System::String^>(ss.str());
    // System::Windows::Forms::MessageBox::Show(message, "Paczka Przyjêta", System::Windows::Forms::MessageBoxButtons::OK);
}