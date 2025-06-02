#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random> // Added for random number generation
#include <iomanip> // Added for std::setw (good practice for JSON output)
#include <msclr/marshal.h>         // Dodane
#include <msclr/marshal_cppstd.h>

// Forward declarations to avoid circular includes if Klasy.h and Formularz_paczki.h were strictly dependent
// Though not strictly necessary here, it's good practice.
// class Formularz_paczki; // Not needed as Formularz_paczki includes Klasy.h

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
    Nadawca() {}; // Default constructor
    Nadawca(const Osoba& osoba, const Adres& adres, const std::string& idNadawcy, const std::string& nazwaNadawcy)
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
    // Added copy constructor for completeness, though default one would probably be sufficient here.
    Nadawca(const Nadawca& other)
        : Osoba(other), Adres(other), idNadawcy(other.idNadawcy), nazwaNadawcy(other.nazwaNadawcy)
    {
        // Copy members from Osoba and Adres base classes
        this->imie = other.imie;
        this->nazwisko = other.nazwisko;
        this->telefon = other.telefon;
        this->email = other.email;
        this->ulica = other.ulica;
        this->miasto = other.miasto;
        this->wojewodztwo = other.wojewodztwo;
        this->kodPocztowy = other.kodPocztowy;
        this->kraj = other.kraj;
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
    Odbiorca() {}; // Default constructor
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
    // Added copy constructor for completeness
    Odbiorca(const Odbiorca& other)
        : Osoba(other), Adres(other), idOdbiorcy(other.idOdbiorcy), nazwaOdbiorcy(other.nazwaOdbiorcy)
    {
        // Copy members from Osoba and Adres base classes
        this->imie = other.imie;
        this->nazwisko = other.nazwisko;
        this->telefon = other.telefon;
        this->email = other.email;
        this->ulica = other.ulica;
        this->miasto = other.miasto;
        this->wojewodztwo = other.wojewodztwo;
        this->kodPocztowy = other.kodPocztowy;
        this->kraj = other.kraj;
    }
};

class Paczka
{
private:
    std::string numerPaczki;
    Nadawca nadawca;    // Changed from pointer to actual object
    Odbiorca odbiorca;  // Changed from pointer to actual object
    // ... other members like status, etc.

    // Helper to generate a random package number
    std::string generateRandomPackageNumber() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(100000, 999999); // 6-digit number
        return "PKZ" + std::to_string(distrib(gen));
    }

public:
    // Default constructor (if needed, initializes with default Nadawca/Odbiorca)
    Paczka() : numerPaczki(generateRandomPackageNumber()) {}

    // REQUIRED CONSTRUCTOR for Paczka:
    // Takes Nadawca and Odbiorca by const reference and copies them into member variables.
    Paczka(const Nadawca& n, const Odbiorca& o)
        : numerPaczki(generateRandomPackageNumber()), nadawca(n), odbiorca(o)
    {
        // No additional work needed here, as members are initialized via member initializer list.
    }

    // Accessors for nadawca and odbiorca
    // Returning const reference to prevent accidental modification of internal objects
    const Nadawca& getNadawca() const { return nadawca; }
    const Odbiorca& getOdbiorca() const { return odbiorca; }
    std::string getNumerPaczki() const { return numerPaczki; } // Added const

    void paczkaPrzyjeta(); // This is defined in Klasy.cpp
};