#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <Windows.h>
#include "Klasy.h"
#include "Formularz_paczki.h"


bool Sortownia::przyjmijPaczke()
{
	bool przyjmijPaczke = false;
	System::Windows::Forms::MessageBox::Show("Czy chcesz przyjac paczke ? ");
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
};
void sortujPaczki()
{
	System::Windows::Forms::MessageBox::Show("Sortuje paczki...");
};


void Paczka::paczkaPrzyjeta()
{
	std::stringstream ss;
	ss << "Numer paczki: " << getNumerPaczki() << "\n";
	ss << "Nadawca: " << nadawca->imie << " " << nadawca->nazwisko << ", tel: " << nadawca->telefon << ", email: " << nadawca->email << "\n";
	ss << "Adres nadawcy: " << nadawca->ulica << ", " << nadawca->miasto << ", " << nadawca->wojewodztwo << ", " << nadawca->kodPocztowy << ", " << nadawca->kraj << "\n";
	ss << "Odbiorca: " << odbiorca->imie << " " << odbiorca->nazwisko << ", tel: " << odbiorca->telefon << ", email: " << odbiorca->email << "\n";
	ss << "Adres odbiorcy: " << odbiorca->ulica << ", " << odbiorca->miasto << ", " << odbiorca->wojewodztwo << ", " << odbiorca->kodPocztowy << ", " << odbiorca->kraj << "\n";
	System::Windows::Forms::MessageBox::Show(gcnew System::String(ss.str().c_str()));
}


