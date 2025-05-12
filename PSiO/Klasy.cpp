#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <Windows.h>



class Sortwonia
{
	bool przyjmijPaczke();
	{
		bool przyjmijPaczke = false;
		System::WindowsForms::Forms::MessageBox("Czy chcesz przyjac paczke?");
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
	}
	void sortujPaczki();
	{

	}
};

