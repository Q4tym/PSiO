#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "json.hpp" // Do obsługi formatu JSON

// --- Deklaracje klas ---
class Paczka; // Deklaracja wyprzedzająca

// --- Klasa Sortownia ---
class Sortownia {
public:
    // Enum do wyboru kryterium sortowania
    enum class KryteriumSortowania {
        WG_MIASTA,
        WG_KODU_POCZTOWEGO
    };

    // Metody publiczne
    void wczytajPaczkiZPliku(const std::string& nazwaPliku);
    void sortujPaczki(KryteriumSortowania kryterium);
    const std::vector<Paczka>& getPaczki() const;

private:
    std::vector<Paczka> paczki; // Wektor do przechowywania paczek
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
private:
    std::string numerPaczki;
    Nadawca nadawca;
    Odbiorca odbiorca;

    // Prywatna metoda do generowania unikalnego numeru paczki
    static std::string generateRandomPackageNumber();

public:
    // Konstruktor do tworzenia NOWEJ paczki (generuje nowy numer)
    Paczka(const Nadawca& n, const Odbiorca& o);

    // Konstruktor do wczytywania paczki Z PLIKU (używa istniejącego numeru)
    Paczka(std::string num, const Nadawca& n, const Odbiorca& o);

    // Gettery
    const Nadawca& getNadawca() const { return nadawca; }
    const Odbiorca& getOdbiorca() const { return odbiorca; }
    std::string getNumerPaczki() const { return numerPaczki; }

    void paczkaPrzyjeta() const;
};