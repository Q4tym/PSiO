#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <Windows.h> // Keep if used for MessageBox, otherwise consider removing
#include "Klasy.h"
#include <msclr/marshal.h>         // Dodane
#include <msclr/marshal_cppstd.h>
// #include "Formularz_paczki.h" // Removed, as Klasy.cpp doesn't directly need Formularz_paczki's internals for Paczka methods.
                               // Formularz_paczki.h includes Klasy.h.

bool Sortownia::przyjmijPaczke()
{
    bool przyjmijPaczke = false;
    // System::Windows::Forms::MessageBox::Show("Czy chcesz przyjac paczke ? "); // This is C++/CLI, not pure C++
    std::cout << "Czy chcesz przyjac paczke ? (1-tak, 0-nie): ";
    int wybor;
    std::cin >> wybor;
    if (wybor == 1)
    {
        przyjmijPaczke = true;
        std::cout << "Paczka przyjeta." << std::endl;
    }
    else
    {
        przyjmijPaczke = false;
        std::cout << "Paczka nie zostala przyjeta." << std::endl;
    }
    return przyjmijPaczke;
}

void Sortownia::sortujPaczki() // Corrected to be a member of Sortownia
{
    // System::Windows::Forms::MessageBox::Show("Sortuje paczki..."); // C++/CLI
    std::cout << "Sortuje paczki..." << std::endl;
}

void Paczka::paczkaPrzyjeta()
{
    std::stringstream ss;
    ss << "Numer paczki: " << getNumerPaczki() << "\n";
    // Access members through the stored objects (not pointers anymore)
    ss << "Nadawca: " << nadawca.imie << " " << nadawca.nazwisko
        << ", tel: " << nadawca.telefon << ", email: " << nadawca.email << "\n";
    ss << "Adres nadawcy: " << nadawca.ulica << ", " << nadawca.miasto
        << ", " << nadawca.wojewodztwo << ", " << nadawca.kodPocztowy
        << ", " << nadawca.kraj << "\n";

    ss << "Odbiorca: " << odbiorca.imie << " " << odbiorca.nazwisko
        << ", tel: " << odbiorca.telefon << ", email: " << odbiorca.email << "\n";
    ss << "Adres odbiorcy: " << odbiorca.ulica << ", " << odbiorca.miasto
        << ", " << odbiorca.wojewodztwo << ", " << odbiorca.kodPocztowy
        << ", " << odbiorca.kraj << "\n";

    // System::Windows::Forms::MessageBox::Show(msclr::interop::marshal_as<System::String^>(ss.str())); // C++/CLI
    std::cout << ss.str() << std::endl; // Pure C++ console output
}