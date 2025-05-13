#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


class Sortwonia
{
private:
	std::string idSortowni;
	std::string adres;
public:
	bool przyjmijPaczke();
	void sortujPaczki();
};

class Adres
{
public:
	std::string ulica;
	std::string miasto;
	std::string wojewodztwo;
	int kodPocztowy;
	std::string kraj;
private:
	virtual void klasaWirtualnaAdres() = 0;
};

class Osoba  
{  
public:  
   std::string imie;  
   std::string nazwisko;  
   int telefon;  
   std::string email;  
private:
   virtual void klasaWirtualnaOsoba() = 0; 
};

class Nadawca : public Osoba, public Adres
{
private:
	std::string idNadawcy;
	std::string nazwaNadawcy;
public:
	Nadawca(std::string id, std::string nazwa, std::string imie, std::string nazwisko, int telefon,
		std::string email, std::string ulica, std::string miasto, std::string wojewodztwo, int kodPocztowy, std::string kraj)
	{
		idNadawcy = id;
		nazwaNadawcy = nazwa;
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->telefon = telefon;
		this->email = email;
		this->ulica = ulica;
		this->miasto = miasto;
		this->wojewodztwo = wojewodztwo;
		this->kodPocztowy = kodPocztowy;
		this->kraj = kraj;
	};
};

class Odbiorca : public Osoba, public Adres
{
private:
	std::string idOdbiorcy;
	std::string nazwaOdbiorcy;
public:
	Odbiorca(std::string id, std::string nazwa, std::string imie, std::string nazwisko, int telefon,
		std::string email, std::string ulica, std::string miasto, std::string wojewodztwo, int kodPocztowy, std::string kraj)
	{
		idOdbiorcy = id;
		nazwaOdbiorcy = nazwa;
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->telefon = telefon;
		this->email = email;
		this->ulica = ulica;
		this->miasto = miasto;
		this->wojewodztwo = wojewodztwo;
		this->kodPocztowy = kodPocztowy;
		this->kraj = kraj;
	};
};

class Paczka
{
private:
	std::string numerPaczki;
	
};

class Magazyn
{
private:
	std::string regal;
	std::string sekcja;
public:
	void przechowajPaczke(Paczka);
};