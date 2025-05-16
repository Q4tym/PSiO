#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


class Sortownia
{
private:
	//std::string idSortowni;
	//std::string adres;
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
	std::string kodPocztowy;
	std::string kraj;
private:
	virtual void klasaWirtualnaAdres() = 0;
};

class Osoba  
{  
public:  
   std::string imie;  
   std::string nazwisko;  
   std::string telefon;  
   std::string email;  
private:
   virtual void klasaWirtualnaOsoba() = 0; 
};

class Nadawca : public Osoba, public Adres
{
private:
	std::string idNadawcy;
	std::string nazwaNadawcy;
	void klasaWirtualnaOsoba() override {};
	void klasaWirtualnaAdres() override {};
public:
	Nadawca () {};
	Nadawca (const Osoba& osoba, const Adres& adres, const std::string& idNadawcy, const std::string& nazwaNadawcy)
	{
		this->idNadawcy = idNadawcy;
		this->nazwaNadawcy = nazwaNadawcy;
		this->imie = osoba.imie;
		this->nazwisko = osoba.nazwisko;
		this->telefon = osoba.telefon;
		this->email = osoba.email;
		this->ulica = adres.ulica;
		this->miasto = adres.miasto;
		this->wojewodztwo = adres.wojewodztwo;
		this->kodPocztowy = adres.kodPocztowy;
		this->kraj = adres.kraj;
	}
};

class Odbiorca : public Osoba, public Adres
{
private:
	std::string idOdbiorcy;
	std::string nazwaOdbiorcy;
	void klasaWirtualnaOsoba() override {};
	void klasaWirtualnaAdres() override {};
public:
	Odbiorca() {};
	Odbiorca(const Osoba& osoba, const Adres& adres, const std::string& idOdbiorcy, const std::string& nazwaOdbiorcy)
	{
		this->idOdbiorcy = idOdbiorcy;
		this->nazwaOdbiorcy = nazwaOdbiorcy;
		this->imie = osoba.imie;
		this->nazwisko = osoba.nazwisko;
		this->telefon = osoba.telefon;
		this->email = osoba.email;
		this->ulica = adres.ulica;
		this->miasto = adres.miasto;
		this->wojewodztwo = adres.wojewodztwo;
		this->kodPocztowy = adres.kodPocztowy;
		this->kraj = adres.kraj;
	}
};
enum class TypPaczki
{
	List = 0,
	Paczka,
	Paleta
};

class Paczka
{
private:
	std::string numerPaczki;
	Nadawca* nadawca;
	Odbiorca* odbiorca;
public:
	// Konstruktor z parametrami
	Paczka(Nadawca& nadawca, Odbiorca& odbiorca)
		: nadawca(&nadawca), odbiorca(&odbiorca)
	{
		numerPaczki = "123456789";
	}

	std::string getNumerPaczki() const
	{
		return numerPaczki;
	}

	void paczkaPrzyjeta();
};



class Magazyn
{
private:
	std::string regal;
	std::string sekcja;
public:
	void przechowajPaczke(Paczka);
};