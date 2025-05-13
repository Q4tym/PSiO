#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <Windows.h>



class Sortownia
{
public:

	bool przyjmijPaczke()
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
};

