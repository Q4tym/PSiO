#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <iomanip>
#include "json.hpp" // Potrzebne do wczytywania danych w Sortowni

class Sortownia
{
public:
    // Enum class do wyboru kryterium sortowania - spe�nia wymaganie projektowe
    enum class KryteriumSortowania {
        WG_MIASTA,
        WG_KODU_POCZTOWEGO
    };

    void wczytajPaczkiZPliku(const std::string& nazwaPliku);
    void sortujPaczki(KryteriumSortowania kryterium);

    // Zwraca sta�� referencj� do wektora paczek
    const std::vector<class Paczka>& getPaczki() const;

private:
    std::vector<class Paczka> paczki; // Wektor do przechowywania paczek
};

class Adres
{
public:
    std::string ulica;
    std::string miasto;
    std::string wojewodztwo;
    std::string kodPocztowy;
    std::string kraj;
    virtual ~Adres() = default;
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
    virtual ~Osoba() = default;
private:
    virtual void klasaWirtualnaOsoba() = 0;
};

class Nadawca : public Osoba, public Adres
{
private:
    void klasaWirtualnaOsoba() override {};
    void klasaWirtualnaAdres() override {};
public:
    Nadawca() = default;
};

class Odbiorca : public Osoba, public Adres
{
private:
    void klasaWirtualnaOsoba() override {};
    void klasaWirtualnaAdres() override {};
public:
    Odbiorca() = default;
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
        std::uniform_int_distribution<> distrib(100000, 999999);
        return "PKZ" + std::to_string(distrib(gen));
    }

public:
    // Konstruktor do tworzenia NOWEJ paczki (generuje nowy numer)
    Paczka(const Nadawca& n, const Odbiorca& o)
        : numerPaczki(generateRandomPackageNumber()), nadawca(n), odbiorca(o) {
    }

    // Konstruktor do wczytywania paczki Z PLIKU (u�ywa istniej�cego numeru)
    Paczka(std::string num, const Nadawca& n, const Odbiorca& o)
        : numerPaczki(std::move(num)), nadawca(n), odbiorca(o) {
    }

    const Nadawca& getNadawca() const { return nadawca; }
    const Odbiorca& getOdbiorca() const { return odbiorca; }
    std::string getNumerPaczki() const { return numerPaczki; }

    void paczkaPrzyjeta();
};