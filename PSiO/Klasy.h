#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::sort
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
    void wczytajPaczkiZPliku(const std::string& nazwaPliku); //
    void sortujPaczki(KryteriumSortowania kryterium); //
    void sortujPaczkiPoMiescie(); // Dodana metoda
    const std::vector<Paczka>& getPaczki() const; //

private:
    std::vector<Paczka> paczki; // Wektor do przechowywania paczek
};


// --- Klasy abstrakcyjne ---
class Adres {
public:
    std::string ulica; //
    std::string miasto; //
    std::string wojewodztwo; //
    std::string kodPocztowy; //
    std::string kraj; //
    virtual ~Adres() = default; //
private:
    virtual void klasaWirtualnaAdres() = 0; //
};

class Osoba {
public:
    std::string imie; //
    std::string nazwisko; //
    std::string telefon; //
    std::string email; //
    virtual ~Osoba() = default; //
private:
    virtual void klasaWirtualnaOsoba() = 0; //
};

// --- Klasy konkretne ---
class Nadawca : public Osoba, public Adres {
private:
    void klasaWirtualnaOsoba() override {} //
    void klasaWirtualnaAdres() override {} //
public:
    Nadawca() = default; //
};

class Odbiorca : public Osoba, public Adres {
private:
    void klasaWirtualnaOsoba() override {} //
    void klasaWirtualnaAdres() override {} //
public:
    Odbiorca() = default; //

    // Added getters for miasto and kodPocztowy for sorting purposes
    const std::string& getMiasto() const { return miasto; }
    const std::string& getKodPocztowy() const { return kodPocztowy; }
};

// --- Klasa Paczka ---
class Paczka {
private:
    std::string numerPaczki; //
    Nadawca nadawca; //
    Odbiorca odbiorca; //

    // Prywatna metoda do generowania unikalnego numeru paczki
    static std::string generateRandomPackageNumber(); //

public:
    // Konstruktor do tworzenia NOWEJ paczki (generuje nowy numer)
    Paczka(const Nadawca& n, const Odbiorca& o); //

    // Konstruktor do wczytywania paczki Z PLIKU (używa istniejącego numeru)
    Paczka(std::string num, const Nadawca& n, const Odbiorca& o); //

    // Gettery
    const Nadawca& getNadawca() const { return nadawca; } //
    const Odbiorca& getOdbiorca() const { return odbiorca; } //
    std::string getNumerPaczki() const { return numerPaczki; } //

    void paczkaPrzyjeta() const; //
};

// Implementacja metod Sortownia (often in a .cpp file, but including here for completeness)
void Sortownia::sortujPaczki(KryteriumSortowania kryterium) {
    if (kryterium == KryteriumSortowania::WG_MIASTA) {
        std::sort(paczki.begin(), paczki.end(), [](const Paczka& a, const Paczka& b) {
            return a.getOdbiorca().getMiasto() < b.getOdbiorca().getMiasto();
            });
    }
    else if (kryterium == KryteriumSortowania::WG_KODU_POCZTOWEGO) {
        std::sort(paczki.begin(), paczki.end(), [](const Paczka& a, const Paczka& b) {
            return a.getOdbiorca().getKodPocztowy() < b.getOdbiorca().getKodPocztowy();
            });
    }
}

const std::vector<Paczka>& Sortownia::getPaczki() const {
    return paczki;
}

// Placeholder for wczytajPaczkiZPliku (implementation depends on your JSON structure)
void Sortownia::wczytajPaczkiZPliku(const std::string& nazwaPliku) {
    // Example implementation using nlohmann/json (you need to provide actual JSON structure)
    // For now, it will just clear the packages.
    paczki.clear();
    std::ifstream ifs(nazwaPliku);
    if (ifs.is_open()) {
        nlohmann::json j;
        ifs >> j;
        for (const auto& item : j) {
            // Assuming your JSON structure matches your Paczka/Odbiorca/Nadawca constructors
            // This is a simplified example, adjust according to your actual JSON data
            std::string numer = item["numerPaczki"].get<std::string>();
            Odbiorca odb;
            odb.imie = item["odbiorca"]["imie"].get<std::string>();
            odb.nazwisko = item["odbiorca"]["nazwisko"].get<std::string>();
            odb.ulica = item["odbiorca"]["adres"]["ulica"].get<std::string>();
            odb.miasto = item["odbiorca"]["adres"]["miasto"].get<std::string>();
            odb.kodPocztowy = item["odbiorca"]["adres"]["kodPocztowy"].get<std::string>();
            odb.kraj = item["odbiorca"]["adres"]["kraj"].get<std::string>();
            // ... populate Nadawca similarly if needed for Paczka constructor
            Nadawca nad; // Assuming default constructor for Nadawca is fine for now

            paczki.emplace_back(numer, nad, odb); // Use the constructor for loading from file
        }
    }
    // else, handle error or throw exception if file not found/opened
}

// Placeholder for Paczka constructors and generateRandomPackageNumber
Paczka::Paczka(const Nadawca& n, const Odbiorca& o) : nadawca(n), odbiorca(o) {
    numerPaczki = generateRandomPackageNumber();
}

Paczka::Paczka(std::string num, const Nadawca& n, const Odbiorca& o) : numerPaczki(std::move(num)), nadawca(n), odbiorca(o) {}

std::string Paczka::generateRandomPackageNumber() {
    // Implement random number generation
    return "RANDOM123"; // Placeholder
}

void Paczka::paczkaPrzyjeta() const {
    // Implement logic for package accepted
}