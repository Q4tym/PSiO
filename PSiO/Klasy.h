#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream> // Potrzebne do przeciążenia operatora <<
#include "json.hpp"

// --- Deklaracje klas ---
class Paczka;

// --- Klasa Sortownia ---
class Sortownia {
public:
    //--[REQUIREMENT: Enumeration]--
    enum class KryteriumSortowania {
        WG_MIASTA,
        WG_KODU_POCZTOWEGO,
        WG_ADRESU_DORECZENIA // NOWE, ulepszone sortowanie
    };

    void wczytajPaczkiZPliku(const std::string& nazwaPliku);
    void sortujPaczki(KryteriumSortowania kryterium);
    const std::vector<Paczka>& getPaczki() const;

private:
    std::vector<Paczka> paczki;
};


//--[REQUIREMENT: Inheritance & Virtual Method]--
// Klasy abstrakcyjne Adres i Osoba z czysto wirtualnymi metodami.
class Adres {
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

class Osoba {
public:
    std::string imie;
    std::string nazwisko;
    std::string telefon;
    std::string email;
    virtual ~Osoba() = default;
private:
    virtual void klasaWirtualnaOsoba() = 0;
};

// --- Klasy konkretne ---
//--[REQUIREMENT: Polymorphism]--
// Klasy Nadawca i Odbiorca dziedziczą po klasach bazowych i implementują
// ich wirtualne metody, co jest podstawą polimorfizmu.
class Nadawca : public Osoba, public Adres {
private:
    void klasaWirtualnaOsoba() override {}
    void klasaWirtualnaAdres() override {}
public:
    Nadawca() = default;
};

class Odbiorca : public Osoba, public Adres {
private:
    void klasaWirtualnaOsoba() override {}
    void klasaWirtualnaAdres() override {}
public:
    Odbiorca() = default;
};

// --- Klasa Paczka ---
class Paczka {
public:
    enum class RozmiarPaczki { MALA, SREDNIA, DUZA };

private:
    //--[REQUIREMENT: Encapsulation]--
    // Pola są prywatne, dostęp przez publiczne metody.
    std::string numerPaczki;
    Nadawca nadawca;
    Odbiorca odbiorca;
    RozmiarPaczki rozmiar;

    static std::string generateRandomPackageNumber();

public:
    Paczka(const Nadawca& n, const Odbiorca& o, RozmiarPaczki r);
    Paczka(std::string num, const Nadawca& n, const Odbiorca& o, RozmiarPaczki r);

    // Gettery
    const Nadawca& getNadawca() const { return nadawca; }
    const Odbiorca& getOdbiorca() const { return odbiorca; }
    std::string getNumerPaczki() const { return numerPaczki; }
    RozmiarPaczki getRozmiar() const { return rozmiar; }

    void paczkaPrzyjeta() const;

    //--[REQUIREMENT: Operator Overloading]--
    // Deklaracja przyjaźni, aby umożliwić globalnej funkcji dostęp do prywatnych pól.
    friend std::ostream& operator<<(std::ostream& os, const Paczka& p);
};