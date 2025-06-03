#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <iomanip> // Dla std::setw, u¿ywane w Klasy.cpp i Formularz_paczki.h
// Poni¿sze nag³ówki s¹ bardziej typowe dla plików .cpp lub nag³ówków C++/CLI,
// ale jeœli Klasy.h ma byæ u¿ywane w kontekœcie C++/CLI, mog¹ byæ potrzebne.
// Zwykle klasy logiki biznesowej (jak te tutaj) s¹ w czystym C++.
// #include <msclr/marshal.h>
// #include <msclr/marshal_cppstd.h>


class Sortownia
{
private:
    // std::string idSortowni;
    // std::string adres;
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

    // Domyœlny wirtualny destruktor jest dobr¹ praktyk¹ dla klas bazowych z funkcjami wirtualnymi
    virtual ~Adres() = default;
private:
    // Czysto wirtualna funkcja czyni klasê abstrakcyjn¹
    virtual void klasaWirtualnaAdres() = 0;
};

class Osoba
{
public:
    std::string imie;
    std::string nazwisko;
    std::string telefon;
    std::string email;

    virtual ~Osoba() = default;
private:
    virtual void klasaWirtualnaOsoba() = 0;
};

class Nadawca : public Osoba, public Adres
{
private:
    std::string idNadawcy;    // Te pola nie s¹ obecnie inicjalizowane ani u¿ywane
    std::string nazwaNadawcy; // w konstruktorze domyœlnym ani w Formularz_paczki

    void klasaWirtualnaOsoba() override {};
    void klasaWirtualnaAdres() override {};
public:
    Nadawca() = default; // Jawnie zadeklarowany konstruktor domyœlny

    // Konstruktor, który by³by u¿ywany, gdyby idNadawcy i nazwaNadawcy by³y przekazywane
    Nadawca(const std::string& i, const std::string& n, const std::string& tel, const std::string& mail,
        const std::string& ul, const std::string& mia, const std::string& woj, const std::string& kod, const std::string& kr,
        const std::string& id, const std::string& nazwaN)
        : idNadawcy(id), nazwaNadawcy(nazwaN)
    {
        imie = i; nazwisko = n; telefon = tel; email = mail;
        ulica = ul; miasto = mia; wojewodztwo = woj; kodPocztowy = kod; kraj = kr;
    }
    // Nie ma potrzeby definiowania jawnego konstruktora kopiuj¹cego, jeœli domyœlny jest wystarczaj¹cy.
};

class Odbiorca : public Osoba, public Adres
{
private:
    std::string idOdbiorcy;   // Te pola nie s¹ obecnie inicjalizowane ani u¿ywane
    std::string nazwaOdbiorcy; // w konstruktorze domyœlnym ani w Formularz_paczki

    void klasaWirtualnaOsoba() override {};
    void klasaWirtualnaAdres() override {};
public:
    Odbiorca() = default; // Jawnie zadeklarowany konstruktor domyœlny

    Odbiorca(const std::string& i, const std::string& n, const std::string& tel, const std::string& mail,
        const std::string& ul, const std::string& mia, const std::string& woj, const std::string& kod, const std::string& kr,
        const std::string& id, const std::string& nazwaO)
        : idOdbiorcy(id), nazwaOdbiorcy(nazwaO)
    {
        imie = i; nazwisko = n; telefon = tel; email = mail;
        ulica = ul; miasto = mia; wojewodztwo = woj; kodPocztowy = kod; kraj = kr;
    }
    // Nie ma potrzeby definiowania jawnego konstruktora kopiuj¹cego, jeœli domyœlny jest wystarczaj¹cy.
};

class Paczka
{
private:
    std::string numerPaczki;
    Nadawca nadawca;
    Odbiorca odbiorca;

    std::string generateRandomPackageNumber() {
        std::random_device rd;
        std::mt19937 gen(rd());
        // Generuje 6-cyfrowy numer, np. od 100000 do 999999
        std::uniform_int_distribution<> distrib(100000, 999999);
        return "PKZ" + std::to_string(distrib(gen));
    }

public:
    Paczka() : numerPaczki(generateRandomPackageNumber()) {} // Domyœlny konstruktor

    Paczka(const Nadawca& n, const Odbiorca& o)
        : numerPaczki(generateRandomPackageNumber()), nadawca(n), odbiorca(o)
    {
    }

    const Nadawca& getNadawca() const { return nadawca; }
    const Odbiorca& getOdbiorca() const { return odbiorca; }
    std::string getNumerPaczki() const { return numerPaczki; }

    void paczkaPrzyjeta(); // Deklaracja metody, definicja w Klasy.cpp
};