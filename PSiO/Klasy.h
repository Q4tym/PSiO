#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "json.hpp"

// --- Deklaracje klas ---
class Paczka;

// --- Klasa Sortownia ---
class Sortownia {
public:
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


// --- Klasy abstrakcyjne ---
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
    // Enum dla rozmiaru paczki
    enum class RozmiarPaczki { MALA, SREDNIA, DUZA };

private:
    std::string numerPaczki;
    Nadawca nadawca;
    Odbiorca odbiorca;
    RozmiarPaczki rozmiar; // Nowe pole

    static std::string generateRandomPackageNumber();

public:
    // Zaktualizowane konstruktory
    Paczka(const Nadawca& n, const Odbiorca& o, RozmiarPaczki r);
    Paczka(std::string num, const Nadawca& n, const Odbiorca& o, RozmiarPaczki r);

    // Gettery
    const Nadawca& getNadawca() const { return nadawca; }
    const Odbiorca& getOdbiorca() const { return odbiorca; }
    std::string getNumerPaczki() const { return numerPaczki; }
    RozmiarPaczki getRozmiar() const { return rozmiar; }

    void paczkaPrzyjeta() const;
};